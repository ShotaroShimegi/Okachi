/*
 * 03_interface_sw.c
 *
 *  Created on: Aug 12, 2024
 *      Author: sssho
 */
#include "main.h"
#include "03_interface_switch.h"

/* ---------------------------------------------------------------
	タクトスイッチの入力状態を取得関数、チャタリングチェック機能付き
--------------------------------------------------------------- */
bool IF_SW_Get_Right_Switch(){
	static bool prevoous_input = 0;
	bool current_input = HAL_GPIO_ReadPin(R_SW_GPIO_Port, R_SW_Pin);
	if(current_input != previous_input)	{
		Clock_Wait_Ms(20);
		current_input = HAL_GPIO_ReadPin(R_SW_GPIO_Port, R_SW_Pin);
	}
	previous_input = current_input;
	return current_input;
}

/* ---------------------------------------------------------------
	タクトスイッチの入力状態を取得関数、チャタリングチェック機能付き
--------------------------------------------------------------- */
bool IF_SW_Get_Center_Switch(){
	static bool prevoous_input = 0;
	bool current_input = HAL_GPIO_ReadPin(C_SW_GPIO_Port, C_SW_Pin);
	if(current_input != previous_input)	{
		Clock_Wait_Ms(20);
		current_input = HAL_GPIO_ReadPin(C_SW_GPIO_Port, C_SW_Pin);
	}
	previous_input = current_input;
	return current_input;
}

/* ---------------------------------------------------------------
	タクトスイッチの入力状態を取得関数、チャタリングチェック機能付き
--------------------------------------------------------------- */
bool IF_SW_Get_Left_Switch(){
	static bool prevoous_input = 0;
	bool current_input = HAL_GPIO_ReadPin(L_SW_GPIO_Port, L_SW_Pin);
	//
	if(current_input != previous_input)	{
		Clock_Wait_Ms(20);
		current_input = HAL_GPIO_ReadPin(L_SW_GPIO_Port, L_SW_Pin);
	}
	previous_input = current_input;
	return current_input;
}
