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
bool IF_SW_Get_Right_Switch();
bool IF_SW_Get_Center_Switch();
bool IF_SW_Get_Left_Switch();

#endif /* MOUSE_MODULE_INC_INTERFACE_SWITCH_H_ */
