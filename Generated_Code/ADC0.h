/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : ADC0.h
**     Project     : adc-mkl05z32x4
**     Processor   : MKL05Z32VLF4
**     Component   : Init_ADC
**     Version     : Component 01.012, Driver 01.12, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2020-07-22, 14:23, # CodeGen: 8
**     Abstract    :
**          This file implements the ADC (ADC0) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
**     Settings    :
**          Component name                                 : ADC0
**          Device                                         : ADC0
**          Settings                                       : 
**            Clock gate                                   : Enabled
**            Clock settings                               : 
**              Input clock select                         : Asynchro clock
**              Prescaler                                  : divide by 4
**              Frequency                                  : 1300 kHz
**              High-speed conversion                      : Disabled
**              Asynchro clock output                      : Disabled
**              Long sample time                           : Disabled
**              Long sample time length                    : 20 ADCK cycles
**            Conversion mode                              : Single
**            Result data format                           : 8-bit right
**            Low power mode                               : Disabled
**            Conversion trigger                           : SW
**            HW average settings                          : 
**              HW average                                 : Enabled
**              HW average length                          : 32 samples
**            Single conversion time - Single-ended        : 427.52 us
**            Single conversion time - Differential        : Differential mode not supported
**            Additional conversion time - Single-ended    : 418.46 us
**            Additional conversion time - Differential    : Differential mode not supported
**            Compare settings                             : 
**              Compare                                    : Disabled
**              Compare value 1                            : 0
**              Compare value 2                            : 0
**              Relation of the CV1 to CV2                 : Less than or equal
**              Compare function                           : Result < CV1
**            Offset                                       : 4
**            Voltage reference                            : Alternate pin pair
**          Pins/Signals                                   : 
**            Channel 0                                    : Disabled
**            Channel 1                                    : Disabled
**            Channel 2                                    : Disabled
**            Channel 3                                    : Disabled
**            Channel 4                                    : Disabled
**            Channel 5                                    : Disabled
**            Channel 6                                    : Enabled
**              Single input                               : Enabled
**                Channel 6 single input                   : ADC0_SE6/TSI0_IN4/PTB0/IRQ_8/LLWU_P4/EXTRG_IN/SPI0_SCK
**                Channel 6 single input signal            : 
**            Channel 7                                    : Disabled
**            Channel 8                                    : Disabled
**            Channel 9                                    : Disabled
**            Channel 10                                   : Disabled
**            Channel 11                                   : Disabled
**            Channel 12                                   : Disabled
**            Channel 13                                   : Disabled
**            Channel 14                                   : Disabled
**            Channel 15                                   : Disabled
**            Channel 16                                   : Disabled
**            Channel 17                                   : Disabled
**            Channel 18                                   : Disabled
**            Channel 19                                   : Disabled
**            Channel 20                                   : Disabled
**            Channel 21                                   : Disabled
**            Channel 22                                   : Disabled
**            Channel 23                                   : Disabled
**            Channel 24                                   : Disabled
**            Channel 25                                   : Disabled
**            Channel 26                                   : Disabled
**            Channel 27                                   : Disabled
**            Channel 28                                   : Disabled
**            Channel 29                                   : Disabled
**            Channel 30                                   : Disabled
**            Trigger A                                    : Disabled
**            Trigger B                                    : Disabled
**          Interrupts/DMA                                 : 
**            Interrupt                                    : INT_ADC0
**            Interrupt request                            : Disabled
**            Interrupt priority                           : 0 (Highest)
**            ISR name                                     : 
**            Conversion complete A interrupt              : Disabled
**            Conversion complete B interrupt              : Disabled
**            DMA request                                  : Disabled
**          Initialization                                 : 
**            ADC part triggered  by trigger A             : 
**              Initial channel select A                   : ADC disabled
**              Differential mode A                        : Disabled
**            ADC part triggered  by trigger B             : 
**              Initial channel select B                   : ADC disabled
**              Differential mode B                        : Disabled
**            Call Init method                             : yes
**     Contents    :
**         Init - void ADC0_Init(void);
**
**     Copyright : 1997 - 2015 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file ADC0.h
** @version 01.12
** @brief
**          This file implements the ADC (ADC0) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
*/         
/*!
**  @addtogroup ADC0_module ADC0 module documentation
**  @{
*/         

#ifndef ADC0_H_
#define ADC0_H_

/* MODULE ADC0. */

/* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

/* Peripheral base address parameter */
#define ADC0_DEVICE ADC0_BASE_PTR


/*
** ===================================================================
**     Method      :  ADC0_Init (component Init_ADC)
**     Description :
**         This method initializes registers of the ADC module
**         according to the Peripheral Initialization settings.
**         Call this method in user code to initialize the module. By
**         default, the method is called by PE automatically; see "Call
**         Init method" property of the component for more details.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void ADC0_Init(void);


/* END ADC0. */
#endif /* #ifndef __ADC0_H_ */
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
