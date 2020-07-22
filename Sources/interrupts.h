/*
 * interrupts.h
 *
 *  Created on: 22 Jul, 2020
 *      Author: siuyin
 */

#ifndef SOURCES_INTERRUPTS_H_
#define SOURCES_INTERRUPTS_H_

// tick is the system tick counter. It counts up.
volatile unsigned int tick;

// ADCResult holds the value of the latest ADC conversion.
volatile unsigned int ADCResult;


#endif /* SOURCES_INTERRUPTS_H_ */
