/* ###################################################################
 **     Filename    : main.c
 **     Project     : adc-mkl05z32x4
 **     Processor   : MKL05Z32VLF4
 **     Version     : Driver 01.01
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2020-07-22, 11:48, # CodeGen: 0
 **     Abstract    :
 **         Main module.
 **         This module contains user's application code.
 **     Settings    :
 **     Contents    :
 **         No public methods
 **
 ** ###################################################################*/
/*!
 ** @file main.c
 ** @version 01.01
 ** @brief
 **         Main module.
 **         This module contains user's application code.
 */
/*!
 **  @addtogroup main_module main module documentation
 **  @{
 */
/* MODULE main */

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "ADC0.h"
#include "PTB.h"
#include "SysTick.h"
#include "TPM0.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
#include "GPIO_PDD.h"
#include "ADC_PDD.h"
#include "TPM_PDD.h"
#include "interrupts.h"

volatile unsigned int ADCResult;
// SenseADCInputTask starts a conversion on ADC single-ended channel 6.
// The result, ADCResult, is updated by adcISR the ADC interrupt service routine.
void SenseADCInputTask(void) {
	static unsigned int nrt;
	if (tick != nrt) {
		return;
	}
	nrt += 50;

	ADC_PDD_WriteStatusControl1Reg(ADC0_BASE_PTR, 0,
			ADC_PDD_SINGLE_ENDED_AD6 + (1<<6));	// start conversion, (1<<6)=enable conversion complete interrupt

}

// UpdateLEDTask turns on the red LED if the value of ADCResult is above a set threshold.
void UpdateLEDTask(void) {
	static unsigned int nrt; // next run tick
	if (tick != nrt) {
		return;
	}
	nrt += 20;

	// Threshold around 2047 with hystersis.
	if (ADCResult > 2057) {
		GPIO_PDD_ClearPortDataOutputMask(GPIOB_BASE_PTR, GPIO_PDD_PIN_8);
	} else if (ADCResult < 2037) {
		GPIO_PDD_SetPortDataOutputMask(GPIOB_BASE_PTR, GPIO_PDD_PIN_8);
	}

}

void UpdateLEDPWMTask(void) {
	static unsigned int nrt; // next run tick
	if (tick != nrt) {
		return;
	}
	nrt += 20;

	TPM_PDD_WriteChannelValueReg(TPM0_BASE_PTR, 2, (ADCResult << 4));
}

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
	/* Write your local variable definition here */

	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
	PE_low_level_init();
	/*** End of Processor Expert internal initialization.                    ***/

	/* Write your code here */

	TPM_PDD_WriteChannelValueReg(TPM0_BASE_PTR, 2, 0x7fff);
	while (1) {
		SenseADCInputTask();
		//UpdateLEDTask();
		UpdateLEDPWMTask();
	}

	/*** Don't write any code pass this line, or it will be deleted during code generation. ***/
	/*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
#ifdef PEX_RTOS_START
	PEX_RTOS_START(); /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
#endif
	/*** End of RTOS startup code.  ***/
	/*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
	for (;;) {
	}
	/*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
 ** @}
 */
/*
 ** ###################################################################
 **
 **     This file was created by Processor Expert 10.5 [05.21]
 **     for the Freescale Kinetis series of microcontrollers.
 **
 ** ###################################################################
 */
