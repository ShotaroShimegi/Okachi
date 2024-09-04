/*
 * myThread.c
 *
 *  Created on: Sep 4, 2024
 *      Author: sssho
 */
#include "stdio.h"

#include "41_myThread.h"


void mySetup(void){
	// 初期設定
	printf("Hello\n");
}

void myloop(void){
	while(1){

	}
}

void myTimerCallback(void){
	// 1kHzタイマ割り込み
}

void myPWMCallback(uint8_t ch){
	// PWM割り込み
}
