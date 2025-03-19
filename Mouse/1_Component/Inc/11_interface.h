/*
 * 11_interface.h
 *
 *  Created on: Aug 12, 2024
 *      Author: sssho
 */

#ifndef MOUSE_COMPONENT_INC_INTERFACE_H_
#define MOUSE_COMPONENT_INC_INTERFACE_H_

#include<stdint.h>

uint8_t IF_selectMode();
void IF_setBlinkParameters(uint8_t command,uint8_t time_ms);
void IF_checkBlinking();


#endif /* MOUSE_COMPONENT_INC_INTERFACE_H_ */
