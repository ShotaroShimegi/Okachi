/*
 * battery.h
 *
 *  Created on: Aug 12, 2024
 *      Author: sssho
 */

#ifndef MOUSE_MODULE_INC_BATTERY_H_
#define MOUSE_MODULE_INC_BATTERY_H_

#include <stdint.h>
#include "adc.h"

const uint32_t MAX_ADC_VALUE = 4096;
const uint32_t VOLTAGE_RATIO = 6*3300;
// バッテリー電圧をmv単位で返す。
uint16_t Battery_GetVoltage();

#endif /* MOUSE_MODULE_INC_BATTERY_H_ */
