/*
 * myThread.c
 *
 *  Created on: Sep 4, 2024
 *      Author: sssho
 */
#include <stdio.h>
#include <stdbool.h>

#include "main.h"

#include "01_communication.h"
#include "03_interface_switch.h"
#include "08_clock.h"

#include "11_interface.h"

#include "41_myThread.h"


void mySetup(void){
	// 初期駆動
	Communication_Initialize();
	printf("Hello\n");
	for(uint8_t i=0;i<2;i++){
		HAL_GPIO_WritePin(IF_LED1_GPIO_Port, IF_LED1_Pin,RESET);
		HAL_GPIO_WritePin(IF_LED2_GPIO_Port, IF_LED2_Pin,RESET);
		HAL_GPIO_WritePin(IF_LED3_GPIO_Port, IF_LED3_Pin,RESET);
		HAL_Delay(500);
		HAL_GPIO_WritePin(IF_LED1_GPIO_Port, IF_LED1_Pin,SET);
		HAL_GPIO_WritePin(IF_LED2_GPIO_Port, IF_LED2_Pin,SET);
		HAL_GPIO_WritePin(IF_LED3_GPIO_Port, IF_LED3_Pin,SET);
		HAL_Delay(500);
	}
	IF_selectMode();

}

void myloop(void){
	while(1){

		if(!IF_SW_GetRightSwitch())	HAL_GPIO_WritePin(IF_LED3_GPIO_Port,IF_LED3_Pin,RESET);
		else						HAL_GPIO_WritePin(IF_LED3_GPIO_Port,IF_LED3_Pin,SET);
		if(!IF_SW_GetCenterSwitch())HAL_GPIO_WritePin(IF_LED2_GPIO_Port,IF_LED2_Pin,RESET);
		else						HAL_GPIO_WritePin(IF_LED2_GPIO_Port,IF_LED2_Pin,SET);
		if(!IF_SW_GetLeftSwitch())	HAL_GPIO_WritePin(IF_LED1_GPIO_Port,IF_LED1_Pin,RESET);
		else						HAL_GPIO_WritePin(IF_LED1_GPIO_Port,IF_LED1_Pin,SET);
		Clock_WaitMs(100);
	}
}

void myTimerCallback(void){
	// 1kHzタイマ割り込み
}

void myPWMCallback(uint8_t ch){
	// PWM割り込み
}
