/*
 * 11_interface.c
 *
 *  Created on: Aug 22, 2024
 *      Author: sssho
 */
#include "11_interface.h"

#include "02_interface_led.h"
#include "03_interface_switch.h"
#include "08_clock.h"

uint8_t _command = 0;
uint16_t _time_ms = 0;
uint16_t _time_cnt_ms = 0;

/* ---------------------------------------------------------------
	モード選択を実施、Enterの戻り値で
--------------------------------------------------------------- */
uint8_t IF_selectMode(){
	uint8_t mode = 0;

	// Enter SW押したらモード終了したら返す
	while(IF_SW_GetCenterSwitch()){
		if(!IF_SW_GetRightSwitch())	mode++;
		if(!IF_SW_GetLeftSwitch())	mode--;
		if(mode > 7)				mode = 0;
		printf("Mode: %d\n",mode);
		IF_LED_Command_Control(mode);
		Clock_WaitMs(300);
	}
	printf("Entered: Mode=%d",mode);

	return mode;
}

/* ---------------------------------------------------------------
	IFのLEDについて点灯間隔を定義
	原則、main関数で呼び出すこと
--------------------------------------------------------------- */
void IF_setBlinkParameters(uint8_t command,uint16_t time_ms){
	_command = command;
	_time_ms = time_ms;
	_time_cnt_ms = 0;
}

/* ---------------------------------------------------------------
	定期周期についてLEDの点灯状態を確認する
	time_ms=0の場合、commandを維持するとする
--------------------------------------------------------------- */
void IF_checkBlinking(){
	if(_time_ms == 0)			IF_LED_Command_Control(_command);
	else if(_time_cnt_ms == 0){
		IF_LED_ALL_TOGGLE();
		_time_cnt_ms++;
	}
	else if(_time_cnt_ms < _time_ms){
		_time_cnt_ms++;
	}else if(_time_ms <= _time_cnt_ms){
		_time_cnt_ms = 0;
	}}
