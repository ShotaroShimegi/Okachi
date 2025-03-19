/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define IR_SEN_FL_Pin GPIO_PIN_0
#define IR_SEN_FL_GPIO_Port GPIOA
#define IR_SE_R_Pin GPIO_PIN_1
#define IR_SE_R_GPIO_Port GPIOA
#define IR_SEN_L_Pin GPIO_PIN_3
#define IR_SEN_L_GPIO_Port GPIOA
#define IR_SEN_FR_Pin GPIO_PIN_4
#define IR_SEN_FR_GPIO_Port GPIOA
#define BATTERY_Pin GPIO_PIN_5
#define BATTERY_GPIO_Port GPIOA
#define MOTOR_R_PWM_Pin GPIO_PIN_6
#define MOTOR_R_PWM_GPIO_Port GPIOA
#define MOTOR_R_DIR_Pin GPIO_PIN_7
#define MOTOR_R_DIR_GPIO_Port GPIOA
#define IF_LED3_Pin GPIO_PIN_0
#define IF_LED3_GPIO_Port GPIOB
#define IF_R_SW_Pin GPIO_PIN_1
#define IF_R_SW_GPIO_Port GPIOB
#define IF_C_SW_Pin GPIO_PIN_8
#define IF_C_SW_GPIO_Port GPIOA
#define MOTOR_EN_Pin GPIO_PIN_10
#define MOTOR_EN_GPIO_Port GPIOA
#define IF_L_SW_Pin GPIO_PIN_11
#define IF_L_SW_GPIO_Port GPIOA
#define IR_LED_SET2_Pin GPIO_PIN_12
#define IR_LED_SET2_GPIO_Port GPIOA
#define MOTOR_L_PWM_Pin GPIO_PIN_3
#define MOTOR_L_PWM_GPIO_Port GPIOB
#define MOTOR_L_DIR_Pin GPIO_PIN_4
#define MOTOR_L_DIR_GPIO_Port GPIOB
#define IR_LED_SET1_Pin GPIO_PIN_5
#define IR_LED_SET1_GPIO_Port GPIOB
#define IF_LED1_Pin GPIO_PIN_6
#define IF_LED1_GPIO_Port GPIOB
#define IF_LED2_Pin GPIO_PIN_7
#define IF_LED2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
