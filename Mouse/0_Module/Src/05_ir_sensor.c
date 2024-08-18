/*
 * 05_ir_sensor.c
 *
 *  Created on: Aug 16, 2024
 *      Author: sssho
 */
#include "main.h"
#include "adc.h"
#include "05_ir_sensor.h"

/* ---------------------------------------------------------------
	センサLEDを系列ごとにONにする
--------------------------------------------------------------- */
void Sensor_LED_ON(uint8_t set_num){
	if(set_num == SENSOR_LIGHT_1)		HAL_GPIO_WritePin(IR_LED_SET1_GPIO_Port, IR_LED_SET1_Pin, SET);
	else if(set_num == SENSOR_LIGHT_2)	HAL_GPIO_WritePin(IR_LED_SET2_GPIO_Port, IR_LED_SET2_Pin, SET);
}

/* ---------------------------------------------------------------
	センサLEDを系列ごとにOFFにする
--------------------------------------------------------------- */
void Sensor_LED_OFF(uint8_t set_num){
	if(set_num == SENSOR_LIGHT_SET1)		HAL_GPIO_WritePin(IR_LED_SET1_GPIO_Port, IR_LED_SET1_Pin, RESET);
	else if(set_num == SENSOR_LIGHT_SET2)	HAL_GPIO_WritePin(IR_LED_SET2_GPIO_Port, IR_LED_SET2_Pin, RESET);
}

/* ---------------------------------------------------------------
	各センサのADC値を付与する
--------------------------------------------------------------- */
uint16_t Sensor_GetADC(uint8_t ch){
	  ADC_ChannelConfTypeDef sConfig = {0};

	  sConfig.Channel = ch;
	  sConfig.Rank = 1;
	  sConfig.SamplingTime = ADC_SAMPLETIME_15CYCLES;

	  HAL_ADC_ConfigChannel(&hadc1, &sConfig);

	  HAL_ADC_Start(&hadc1);
	  HAL_ADC_PollForConversion(&hadc1, 100);
	  uint32_t adc_raw_value = HAL_ADC_GetValue(&hadc1);

	  return adc_raw_value;
}
