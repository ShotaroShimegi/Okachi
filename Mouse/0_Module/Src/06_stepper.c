/*
 * 06_stepper.c
 *
 *  Created on: Aug 16, 2024
 *      Author: sssho
 */
#include "tim.h"
#include "00_HW_params.h"
#include "06_stepper.h"

// 左右モータ毎のパラメータ
STEP_MOTOR Left;
STEP_MOTOR Right;

// 左右モータの共通パラメータ
int32_t 	center_vel_mmps, center_dist_mm,target_dist_mm;
float		center_angle_deg,target_angle_deg;
const float DISTANCE_MMPPULSE = HW_WHEEL_RADIUS_MM*HW_STEP_DEGREE/180*PI;

STEP_MOTOR setParameter(int32_t _sigma_pulse, int32_t _time_ms,float _vel,float _target_vel,float _accel_mmps,float _saved_pulse){
	STEP_MOTOR* temp;
	temp->sigma_pulse = _sigma_pulse;
	temp->pulse_time_ms = _time_ms;
	temp->vel = _vel;
	temp->target_vel = _target_vel;
	temp->accel_mmpss = _accel_mmps;
	temp->saved_pulse = _saved_pulse;

	return *temp;
}

/* ---------------------------------------------------------------
	ステッパの初期準備
--------------------------------------------------------------- */
void Stepper_Initialize(void){
	// プライベート変数の初期化
	center_vel_mmps = 0;
	center_dist_mm = 0;
	center_angle_deg = 0.0;
	LEFT = setParameter(0, 0, 0.0f, 0.0f, 0.0f, 0.0f);
	RIGHT = setParameter(0, 0, 0.0f, 0.0f, 0.0f, 0.0f);
}

/* ---------------------------------------------------------------
	途中工程での変数の初期化
--------------------------------------------------------------- */
void Stepper_Reset(void){
	// 走行距離関連と事前記録の初期化
	center_vel_mmps = 0;
	center_dist_mm = 0;
	center_angle_deg = 0.0;}

/* ---------------------------------------------------------------
	走行距離のゲッター（右モータ）
--------------------------------------------------------------- */
uint32_t Stepper_GetRightDistance(void){
	return sigma_pulse_r*DISTANCE_MMPPULSE;
}

/* ---------------------------------------------------------------
	走行距離のゲッター（左モータ）
--------------------------------------------------------------- */
uint32_t Stepper_GetLeftDistance(void){
	return sigma_pulse_l*DISTANCE_MMPPULSE;
}

/* ---------------------------------------------------------------
	タイヤから想定される角度のゲッター
--------------------------------------------------------------- */
uint32_t Stepper_GetAngle(void){
	return center_angle_deg;
}

/* ---------------------------------------------------------------
	走行パラメータの設定、走行開始直前に呼び出す想定
--------------------------------------------------------------- */
void Stepper_SetParameters(int32_t vel_l, int32_t vel_r,int32_t accel,int32_t distance,float angle){
	// 回転方向の設定
	if(vel_r > 0) RIGHT_CW();	else RIGHT_CCW();
	if(vel_l > 0) LEFT_CCW();	else LEFT_CW();

	// 単純なセッター
	LEFT.target_vel = vel_l,LEFT.accel_mmpss = ABS(accel);
	RIGHT.target_vel = vel_r, RIGHT.accel_mmpss = ABS(accel);
	target_dist_mm = distance;
	target_angle_deg = angle;

	// パラメータセッティング中の記録を保存
	start_pulse_l = sigma_pulse_l;
	start_pulse_r = sigma_pulse_r;
}


void Stepper_UpdateSensor(){
	int32_t diff_pulse_r = sigma_pulse_r - start_pulse_r;
	int32_t diff_pulse_l = sigma_pulse_l - start_pulse_l;

	float distance_center = (diff_pulse_r + diff_pulse_l)*DISTANCE_MMPPULSE*0.50f;
	float angle_ceter = RAD2DEG((diff_pulse_r - diff_pulse_l)*DISTANCE_MMPPULSE/HW_TREAD_MM);
	return 0;
}

bool Stepper_UpdateRight(void){
	sigma_pulse_r++;

	// 走行条件を確認し、速度更新するか確認, 非常停止によるPWM停止
	if(ABS(distance_center) > 1.2f*ABS(target_distance_mm)){
		HAL_TIM_PWM_Stop_IT(&htim2, 2);
		return 1;
	}
	else if(ABS(angle_center) > 1.2f*ABS(target_angle_deg)){
		HAL_TIM_PWM_Stop_IT(&htim2, 2);
		return 2;
	}

	// 周期時間を格納
	RIGHT.pulse_time_ms = DISTANCE_MMPPULSE / RIGHT.vel_r*1000;
	if(RIGHT.vel < RIGHT.target_vel)		RIGHT.vel += RIGHT.accel_mmpss*RIGHT.pulse_time_ms*0.001f;
	else if(RIGHT.target_vel < RIGHT.vel)	RIGHT.vel -= RIGHT.accel_mmpss*RIGHT.pulse_time_ms*0.001f;
	else 									RIGHT.vel = RIGHT.vel;

	// 割り込み関連の設定を反映
	__HAL_TIM_SET_AUTORELOAD(&htim2,(uint16_t)(DISTANCE_MMPPULSE/RIGHT.vel*1000000));
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,(uint16_t)(DISTANCE_MMPPULSE/RIGHT.vel*500000));
	HAL_TIM_PWM_Start_IT(&htim2, 2);

	return 0;
}

bool Stepper_UpdateLeft(void){
	sigma_pulse_l++;
	// 走行条件を確認し、速度更新するか確認, 非常停止によるPWM停止
	if(ABS(distance_center) > 1.2f*ABS(target_distance_mm)){
		HAL_TIM_PWM_Stop_IT(&htim16, 1);
		return 1;
	}
	else if(ABS(angle_center) > 1.2f*ABS(target_angle_deg)){
		HAL_TIM_PWM_Stop_IT(&htim16, 1);
		return 2;
	}

	// 周期時間を格納
	LEFT.pulse_time_ms = DISTANCE_MMPPULSE / LEFT.vel_r*1000;
	if(LEFT.vel < LEFT.target_vel)		LEFT.vel += LEFT.accel_mmpss*LEFT.pulse_time_ms*0.001f;
	else if(LEFT.target_vel < LEFT.vel)	LEFT.vel -= LEFT.accel_mmpss*LEFT.pulse_time_ms*0.001f;
	else 								LEFT.vel = LEFT.vel;

	// 割り込み関連の設定を反映
	__HAL_TIM_SET_AUTORELOAD(&htim16,(uint16_t)(DISTANCE_MMPPULSE/RIGHT.vel*1000000));
	__HAL_TIM_SET_COMPARE(&htim16,TIM_CHANNEL_1,(uint16_t)(DISTANCE_MMPPULSE/RIGHT.vel*500000));
	HAL_TIM_PWM_Start_IT(&htim16, 1);

	return 0;
}

/* ---------------------------------------------------------------
	モータ駆動開始関数
--------------------------------------------------------------- */
void Stepper_StartMotor(void){
	HAL_GPIO_WritePin(MOTOR_EN_GPIO_Port, MOTOR_EN_Pin, RESET);
	HAL_TIM_PWM_Start_IT(&htim2, 2);
	HAL_TIM_PWM_Start_IT(&htim16, 1);
}

/* ---------------------------------------------------------------
	モータ駆動停止関数
--------------------------------------------------------------- */
void Stepper_StopMotor(void){
	HAL_TIM_PWM_Stop_IT(&htim2, 2);
	HAL_TIM_PWM_Stop_IT(&htim16, 1);
	HAL_GPIO_WritePin(MOTOR_EN_GPIO_Port, MOTOR_EN_Pin, SET);
}
