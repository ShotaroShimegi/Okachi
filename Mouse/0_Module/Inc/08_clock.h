/*
 * 08_clock.h
 *
 *  Created on: Aug 12, 2024
 *      Author: sssho
 */

#ifndef MOUSE_MODULE_INC_CLOCK_H_
#define MOUSE_MODULE_INC_CLOCK_H_

#include <stdint.h>

void Clock_Wait_Ms(uint16_t);
void Clock_Micro_Ms(uint16_t);
void Clock_InteruptStart();
void Clock_InteruptStop();

#endif /* MOUSE_0_MODULE_INC_08_CLOCK_H_ */
