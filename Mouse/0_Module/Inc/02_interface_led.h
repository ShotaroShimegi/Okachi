/*
 * interface_led.h
 *
 *  Created on: Aug 12, 2024
 *      Author: sssho
 */

#ifndef MOUSE_MODULE_INC_INTERFACE_LED_H_
#define MOUSE_MODULE_INC_INTERFACE_LED_H_

#include <stdint.h>
#include "main.h"

/* LED関数群 */
#define IF_LED1_ON()			HAL_GPIO_WritePin( IF_LED1_GPIO_Port, IF_LED1_Pin, GPIO_PIN_SET)			// LED1を点灯
#define IF_LED1_OFF()			HAL_GPIO_WritePin( IF_LED1_GPIO_Port, IF_LED1_Pin, GPIO_PIN_RESET)			// LED1を消灯
#define IF_LED1_TOGGLE()		HAL_GPIO_TogglePin(IF_LED1_GPIO_Port, IF_LED1_Pin)							// LED1の状態をトグル
#define IF_LED2_ON()			HAL_GPIO_WritePin( IF_LED2_GPIO_Port, IF_LED2_Pin, GPIO_PIN_SET)			// LED2を点灯
#define IF_LED2_OFF()			HAL_GPIO_WritePin( IF_LED2_GPIO_Port, IF_LED2_Pin, GPIO_PIN_RESET)			// LED2を消灯
#define IF_LED2_TOGGLE()		HAL_GPIO_TogglePin(IF_LED2_GPIO_Port, IF_LED2_Pin)							// LED2の状態をトグル
#define IF_LED3_ON()			HAL_GPIO_WritePin( IF_LED3_GPIO_Port, IF_LED3_Pin, GPIO_PIN_SET)			// LED3を点灯
#define IF_LED3_OFF()			HAL_GPIO_WritePin( IF_LED3_GPIO_Port, IF_LED3_Pin, GPIO_PIN_RESET)			// LED3を消灯
#define IF_LED3_TOGGLE()		HAL_GPIO_TogglePin(IF_LED3_GPIO_Port, IF_LED3_Pin)							// LED3の状態をトグル

// LED全体指示関数
void IF_LED_Command_Control(uint8_t command);
void IF_LED_ALL_TOGGLE();

#endif /* MOUSE_MODULE_INC_INTERFACE_LED_H_ */
