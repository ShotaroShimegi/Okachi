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
#define IR_LED_SET1_Pin GPIO_PIN_5
#define IR_LED_SET1_GPIO_Port GPIOA
#define R_STEP_PWM_Pin GPIO_PIN_6
#define R_STEP_PWM_GPIO_Port GPIOA
#define IR_LED_SET2_Pin GPIO_PIN_7
#define IR_LED_SET2_GPIO_Port GPIOA
#define IF_LED4_Pin GPIO_PIN_0
#define IF_LED4_GPIO_Port GPIOB
#define IF_LED1_Pin GPIO_PIN_1
#define IF_LED1_GPIO_Port GPIOB
#define R_STEP_DIR_Pin GPIO_PIN_8
#define R_STEP_DIR_GPIO_Port GPIOA
#define L_SW_Pin GPIO_PIN_11
#define L_SW_GPIO_Port GPIOA
#define L_STEP_DIR_Pin GPIO_PIN_12
#define L_STEP_DIR_GPIO_Port GPIOA
#define L_STEP_PWM_Pin GPIO_PIN_3
#define L_STEP_PWM_GPIO_Port GPIOB
#define R_SW_Pin GPIO_PIN_4
#define R_SW_GPIO_Port GPIOB
#define C_SW_Pin GPIO_PIN_5
#define C_SW_GPIO_Port GPIOB
#define IF_LED2_Pin GPIO_PIN_6
#define IF_LED2_GPIO_Port GPIOB
#define IF_LED3_Pin GPIO_PIN_7
#define IF_LED3_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
