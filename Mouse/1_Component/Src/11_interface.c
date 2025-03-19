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

/* ---------------------------------------------------------------
	モード選択を実施、Enterの戻り値で
--------------------------------------------------------------- */
uint8_t IF_selectMode(){
	uint8_t mode = 0;

	// Enter SW押したらモード終了したら返す
	while(!IF_SW_GetCenterSwitch()){
		if(!IF_SW_GetRightSwitch())	mode++;
		if(!IF_SW_GetLeftSwitch())	mode--;
		if(mode > 7)				mode = 0;
		printf("Mode: %d\n",mode);
		IF_LED_Command_Control(mode);
		Clock_WaitMs(10);
	}
	printf("Entered: Mode=%d",mode);

	return mode;
}

/* ---------------------------------------------------------------
	センサLEDを系列ごとにONにする
--------------------------------------------------------------- */
void IF_setBlinkParameters(uint8_t command,uint8_t time_ms);

/* ---------------------------------------------------------------
	センサLEDを系列ごとにONにする
--------------------------------------------------------------- */
void IF_checkBlinking();
