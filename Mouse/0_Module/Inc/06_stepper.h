/*
 * stepper.h
 *
 *  Created on: Aug 12, 2024
 *      Author: sssho
 */

#ifndef MOUSE_MODULE_INC_STEPPER_H_
#define MOUSE_MODULE_INC_STEPPER_H_

#include <stdint.h>
#include <stdbool.h>
#include "main.h"

#define RIGHT_CW()	HAL_GPIO_WritePin(R_STEP_DIR_GPIO_Port, R_STEP_DIR_Pin, SET)
#define RIGHT_CCW()	HAL_GPIO_WritePin(R_STEP_DIR_GPIO_Port, R_STEP_DIR_Pin, RESET)
#define LEFT_CW()	HAL_GPIO_WritePin(L_STEP_DIR_GPIO_Port, L_STEP_DIR_Pin, SET)
#define LEFT_CCW()	HAL_GPIO_WritePin(L_STEP_DIR_GPIO_Port, L_STEP_DIR_Pin, RESET)

typedef struct step_motor{
	int32_t sigma_pulse;
	int32_t pulse_time_ms;
	float vel;
	float target_vel;
	float accel_mmpss;
	float saved_pulse;
}STEP_MOTOR;

// ステッピングモータはセンサ+アクチュエータ と見做す
void Stepper_Initialize(void);
void Stepper_Reset(void);
uint32_t Stepper_GetRightDistance(void);
uint32_t Stepper_GetLeftDistance(void);
float Stepper_GetAngle(void);
void Stepper_SetParameters(int32_t vel_l, int32_t vel_r,int32_t accel,int32_t distance,float angle);
void Stepper_UpdateSensor(void);
bool Stepper_UpdateRight(void);
bool Stepper_UpdateLeft(void);
void Stepper_StartMotor(void);
void Stepper_StopMotor(void);


#endif /* MOUSE_MODULE_INC_STEPPER_H_ */
