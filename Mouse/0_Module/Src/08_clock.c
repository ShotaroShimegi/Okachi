/*
 * 08_clock.c
 *
 *  Created on: Aug 17, 2024
 *      Author: sssho
 */
#include "tim.h"
#include "08_clock.h"

/* ---------------------------------------------------------------
	msWait関数（HALだとラッパー）
--------------------------------------------------------------- */
void Clock_Wait_Ms(uint16_t ms){
	HAL_Delay(ms);
}

/* ---------------------------------------------------------------
	usWait関数
--------------------------------------------------------------- */
void Clock_Micro_Ms(uint16_t us){
	uint16_t delay = __HAL_TIM_GET_COUNTER(&htim7) + us;
	HAL_TIM_Base_Start(&htim7);
	while(__HAL_TIM_GET_COUNTER(&htim7) < delay);
	HAL_TIM_Base_Stop(&htim7);
	TIM7->CNT = 0;
}

/* ---------------------------------------------------------------
	タイマ割込み開始の処理
--------------------------------------------------------------- */
void Clock_InteruptStart(){
	TIM6->CNT = 0;
	HAL_TIM_Base_Start_IT(&htim6);
}

/* ---------------------------------------------------------------
	タイマ割込み終了の処理
--------------------------------------------------------------- */
void Clock_InteruptStop(){
	HAL_TIM_Base_Stop_IT(&htim6);
	TIM6->CNT = 0;
}
