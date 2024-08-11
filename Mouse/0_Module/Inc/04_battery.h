/*
 * battery.h
 *
 *  Created on: Aug 12, 2024
 *      Author: sssho
 */

#ifndef MOUSE_MODULE_INC_BATTERY_H_
#define MOUSE_MODULE_INC_BATTERY_H_

// ADCは、コチラの関数では値貰って吐き出すだけする(DMAは使わなない)
// ADCのセットアップは良い感じに行う
void initializeBattery();
void checkBattery();
uint8_t getVolatage();




#endif /* MOUSE_MODULE_INC_BATTERY_H_ */
