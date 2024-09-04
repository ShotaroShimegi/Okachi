/*
 * 08_clock.h
 *
 *  Created on: Aug 12, 2024
 *      Author: sssho
 */

#ifndef MOUSE_MODULE_INC_CLOCK_H_
#define MOUSE_MODULE_INC_CLOCK_H_

#include <stdint.h>

void Clock_WaitMs(uint16_t);
void Clock_MicroMs(uint16_t);
void Clock_StartInterupt();
void Clock_StopInterupt();

#endif /* MOUSE_0_MODULE_INC_08_CLOCK_H_ */
