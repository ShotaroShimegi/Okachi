/*
 * 02_interface_led.c
 *
 *  Created on: Aug 12, 2024
 *      Author: sssho
 */
#include "main.h"
#include "02_interface_led.h"

/* ---------------------------------------------------------------
	コマンドで全LEDを発光状態を制御,コマンドは2進数操作
--------------------------------------------------------------- */
void IF_LED_Command_Control(uint8_t command){
	HAL_GPIO_WritePin(IF_LED1_GPIO_Port, IF_LED1_Pin, command & 0x01);
	HAL_GPIO_WritePin(IF_LED2_GPIO_Port, IF_LED2_Pin, command & 0x02);
	HAL_GPIO_WritePin(IF_LED3_GPIO_Port, IF_LED3_Pin, command & 0x04);
}

/* --------------------------------------------------------------
	全てのLEDを手軽にトグルする関数
--------------------------------------------------------------- */
void IF_LED_ALL_TOGGLE(){
	HAL_GPIO_TogglePin(IF_LED1_GPIO_Port, IF_LED1_Pin);
	HAL_GPIO_TogglePin(IF_LED2_GPIO_Port, IF_LED2_Pin);
	HAL_GPIO_TogglePin(IF_LED3_GPIO_Port, IF_LED3_Pin);
}
