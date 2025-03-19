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
float		center_angle_deg,center_angle_rad,target_angle_deg;
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
	center_angle_rad = 0.0;
	Left = setParameter(0, 0, 0.0f, 0.0f, 0.0f, 0.0f);
	Right = setParameter(0, 0, 0.0f, 0.0f, 0.0f, 0.0f);
}

/* ---------------------------------------------------------------
	途中工程での変数の初期化
--------------------------------------------------------------- */
void Stepper_Reset(void){
	// 走行距離関連と事前記録の初期化
	center_vel_mmps = 0;
	center_dist_mm = 0;
	center_angle_deg = 0.0f;
	center_angle_rad = 0.0f;
	target_angle_deg = 0.0f;
	target_dist_mm = 0;
}

/* ---------------------------------------------------------------
	走行距離のゲッター（右モータ）
--------------------------------------------------------------- */
uint32_t Stepper_GetRightDistance(void){
	return Right.sigma_pulse*DISTANCE_MMPPULSE;
}

/* ---------------------------------------------------------------
	走行距離のゲッター（左モータ）
--------------------------------------------------------------- */
uint32_t Stepper_GetLeftDistance(void){
	return Left.sigma_pulse*DISTANCE_MMPPULSE;
}

/* ---------------------------------------------------------------
	タイヤから想定される角度のゲッター
--------------------------------------------------------------- */
float Stepper_GetAngle(void){
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
	Left.target_vel = vel_l,Left.accel_mmpss = ABS(accel);
	Right.target_vel = vel_r, Right.accel_mmpss = ABS(accel);
	target_dist_mm = distance;
	target_angle_deg = angle;

	// パラメータセッティング中の記録を保存
	Left.saved_pulse = Left.sigma_pulse;
	Right.saved_pulse = Right.sigma_pulse;
}


void Stepper_UpdateSensor(){
	int32_t diff_pulse_r = Right.sigma_pulse - Right.saved_pulse;
	int32_t diff_pulse_l = Left.sigma_pulse - Left.saved_pulse;

	center_dist_mm = (diff_pulse_r + diff_pulse_l)*DISTANCE_MMPPULSE*0.50f;
	center_vel_mmps = (Right.vel + Left.vel)*0.50f;
	center_angle_rad = (diff_pulse_r - diff_pulse_l)*DISTANCE_MMPPULSE/HW_TREAD_MM;
	center_angle_deg = RAD2DEG(center_angle_rad);
}

bool Stepper_UpdateRight(void){
	Right.sigma_pulse++;

	// 走行条件を確認し、速度更新するか確認, 非常停止によるPWM停止
	if(ABS(center_dist_mm) > 1.2f*ABS(target_dist_mm)){
		HAL_TIM_PWM_Stop_IT(&htim2, 2);
		return 1;
	}
	else if(ABS(center_angle_deg) > 1.2f*ABS(target_angle_deg)){
		HAL_TIM_PWM_Stop_IT(&htim2, 2);
		return 2;
	}

	// 周期時間を格納
	Right.pulse_time_ms = DISTANCE_MMPPULSE / Right.vel*1000;
	if(Right.vel < Right.target_vel)		Right.vel += Right.accel_mmpss*Right.pulse_time_ms*0.001f;
	else if(Right.target_vel < Right.vel)	Right.vel -= Right.accel_mmpss*Right.pulse_time_ms*0.001f;
	else 									Right.vel = Right.vel;

	// 割り込み関連の設定を反映
	__HAL_TIM_SET_AUTORELOAD(&htim2,(uint16_t)(DISTANCE_MMPPULSE/Right.vel*1000000));
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,(uint16_t)(DISTANCE_MMPPULSE/Right.vel*500000));
	HAL_TIM_PWM_Start_IT(&htim2, 2);

	return 0;
}

bool Stepper_UpdateLeft(void){
	Left.sigma_pulse++;
	// 走行条件を確認し、速度更新するか確認, 非常停止によるPWM停止
	if(ABS(center_dist_mm) > 1.2f*ABS(target_dist_mm)){
		HAL_TIM_PWM_Stop_IT(&htim16, 1);
		return 1;
	}
	else if(ABS(center_angle_deg) > 1.2f*ABS(target_angle_deg)){
		HAL_TIM_PWM_Stop_IT(&htim16, 1);
		return 2;
	}

	// 周期時間を格納
	Left.pulse_time_ms = DISTANCE_MMPPULSE / Left.vel*1000;
	if(Left.vel < Left.target_vel)		Left.vel += Left.accel_mmpss*Left.pulse_time_ms*0.001f;
	else if(Left.target_vel < Left.vel)	Left.vel -= Left.accel_mmpss*Left.pulse_time_ms*0.001f;
	else 								Left.vel = Left.vel;

	// 割り込み関連の設定を反映
	__HAL_TIM_SET_AUTORELOAD(&htim16,(uint16_t)(DISTANCE_MMPPULSE/Left.vel*1000000));
	__HAL_TIM_SET_COMPARE(&htim16,TIM_CHANNEL_1,(uint16_t)(DISTANCE_MMPPULSE/Left.vel*500000));
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
