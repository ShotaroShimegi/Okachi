/*
 * myThread.h
 *
 *  Created on: Aug 12, 2024
 *      Author: sssho
 */

#ifndef MOUSE_SYSTEM_INC_MYTHREAD_H_
#define MOUSE_SYSTEM_INC_MYTHREAD_H_

#include<stdint.h>

// マウスにおける実質的な処理を司る
// 原則はArduino関数っぽく分割

void mySetup(void);
void myloop(void);
void myTimerCallback(void);
void myPWMCallback(uint8_t ch);

#define RIGHT_PWM_TIM	1
#define LEFT_PWM_TIM 	2



#endif /* MOUSE_SYSTEM_INC_MYTHREAD_H_ */
