/*
 * interface_switch.h
 *
 *  Created on: Aug 12, 2024
 *      Author: sssho
 */

#ifndef MOUSE_MODULE_INC_INTERFACE_SWITCH_H_
#define MOUSE_MODULE_INC_INTERFACE_SWITCH_H_

#include<stdbool.h>

/* Tact SWithc関連の関数（チャタリング処理）*/
bool IF_SW_GetRightSwitch();
bool IF_SW_GetCenterSwitch();
bool IF_SW_GetLeftSwitch();

#endif /* MOUSE_MODULE_INC_INTERFACE_SWITCH_H_ */
