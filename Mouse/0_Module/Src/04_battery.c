/*
 * 04_battery.c
 *
 *  Created on: Aug 12, 2024
 *      Author: sssho
 */
#include "04_battery.h"

/* ---------------------------------------------------------------
	バッテリの電圧を取得する関数
--------------------------------------------------------------- */
uint16_t Battery_GetVoltage(){
  ADC_ChannelConfTypeDef sConfig = {0};

  sConfig.Channel = 7;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_15CYCLES;

  HAL_ADC_ConfigChannel(hadc1, &sConfig);

  HAL_ADC_Start(hadc1);
  HAL_ADC_PollForConversion(hadc1, 100);
  uint32_t adc_raw_value = HAL_ADC_GetValue(hadc1);

  return adc_raw_value*VOLTAGE_RATIO/MAX_ADC_VALUE;
}
