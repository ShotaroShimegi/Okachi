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
	HAL_UART_Receive( &huart1, (uint8_t*)data, sizeof(data), 1 );
	return (*data);
}

/* ---------------------------------------------------------------
	printfを使用するための設定
--------------------------------------------------------------- */
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */
PUTCHAR_PROTOTYPE
{
	if(ch == '\n'){
		uint8_t _ch = '\r';
		HAL_UART_Receive(&huart1, &_ch, 1, 1);
	}
	HAL_UART_Receive(&huart1, &ch, 1, 1);
	return 1;
}

/* ---------------------------------------------------------------
	scanfを使用するための設定
--------------------------------------------------------------- */
#ifdef __GNUC__
#define GETCHAR_PROTOTYPE int __io_getchar(void)
#else
#define GETCHAR_PROTOTYPE int fgetc(FILE *f)
#endif /* __GNUC__ */
GETCHAR_PROTOTYPE {
	return Communication_TerminalRecev();
}
