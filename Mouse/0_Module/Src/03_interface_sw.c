/*
 * 03_interface_sw.c
 *
 *  Created on: Aug 12, 2024
 *      Author: sssho
 */
#include "main.h"

#include "03_interface_switch.h"
#include "08_clock.h"

/* ---------------------------------------------------------------
	タクトスイッチの入力状態を取得関数、チャタリングチェック機能付き
--------------------------------------------------------------- */
bool IF_SW_GetRightSwitch(){
	static bool previous_input = 0;
	bool current_input = HAL_GPIO_ReadPin(R_SW_GPIO_Port, R_SW_Pin);
	if(current_input != previous_input)	{
		Clock_WaitMs(20);
		current_input = HAL_GPIO_ReadPin(R_SW_GPIO_Port, R_SW_Pin);
	}
	previous_input = current_input;
	return current_input;
}

/* ---------------------------------------------------------------
	タクトスイッチの入力状態を取得関数、チャタリングチェック機能付き
--------------------------------------------------------------- */
bool IF_SW_GetCenterSwitch(){
	static bool previous_input = 0;
	bool current_input = HAL_GPIO_ReadPin(C_SW_GPIO_Port, C_SW_Pin);
	if(current_input != previous_input)	{
		Clock_WaitMs(20);
		current_input = HAL_GPIO_ReadPin(C_SW_GPIO_Port, C_SW_Pin);
	}
	previous_input = current_input;
	return current_input;
}

/* ---------------------------------------------------------------
	タクトスイッチの入力状態を取得関数、チャタリングチェック機能付き
--------------------------------------------------------------- */
bool IF_SW_GetLeftSwitch(){
	static bool previous_input = 0;
	bool current_input = HAL_GPIO_ReadPin(L_SW_GPIO_Port, L_SW_Pin);
	//
	if(current_input != previous_input)	{
		Clock_WaitMs(20);
		current_input = HAL_GPIO_ReadPin(L_SW_GPIO_Port, L_SW_Pin);
	}
	previous_input = current_input;
	return current_input;
}
