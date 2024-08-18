/*
 * ir_sensor.h
 *
 *  Created on: Aug 12, 2024
 *      Author: sssho
 */

#ifndef MOUSE_MODULE_INC_IR_SENSOR_H_
#define MOUSE_MODULE_INC_IR_SENSOR_H_

#include <stdint.h>

enum{
	RIGHT_FROMT = 5,
	RIGHT = 6,
	LEFT = 8,
	LEFT_FRONT = 9
}SENSOR_ADC;

enum{
	SENSOR_LIGHT_1 = 1,		// 左前と右センサと仮定
	SENSOR_LIGHT_2			// 右前と左センサと仮定
};

/* 赤外センサ関数の基本機能*/
void 		Sensor_LED_ON(uint8_t set_num);
void 		Sensor_LED_OFF(uint8_t set_num);
uint16_t 	Sensor_GetADC(uint8_t ch);

#endif /* MOUSE_MODULE_INC_IR_SENSOR_H_ */
