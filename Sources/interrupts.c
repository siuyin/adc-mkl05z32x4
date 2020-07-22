/*
 * interrupts.c
 *
 *  Created on: 22 Jul, 2020
 *      Author: siuyin
 */

#include "interrupts.h"

#include "Cpu.h"
#include "Events.h"
#include "ADC0.h"
#include "PTB.h"
#include "SysTick.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
#include "GPIO_PDD.h"
#include "ADC_PDD.h"

void sysTickISR(void) {
	tick++;
}

extern volatile unsigned int ADCResult;
void adcISR(void) {
	ADCResult = ADC_PDD_GetResultValueRaw(ADC0_BASE_PTR, 0);
}
