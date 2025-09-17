/*
 * 01_communication.c
 *
 *  Created on: Aug 12, 2024
 *      Author: sssho
 */
#include <stdio.h>

#include "tim.h"
#include "usart.h"

#include "01_communication.h"

/* ---------------------------------------------------------------
	printfとscanfを使用するための設定
--------------------------------------------------------------- */
void Communication_Initialize(void){
	setbuf(stdout,NULL);
}

/* ---------------------------------------------------------------
	UART1で1文字受信する関数
--------------------------------------------------------------- */
uint8_t Communication_TerminalRecev(void){
	uint8_t data[1];
	HAL_UART_Receive( &huart2, (uint8_t*)data, sizeof(data), 1 );
	return (*data);
}
