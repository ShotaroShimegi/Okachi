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
int32_t 	center_vel_mmps, center_dist_mm;
float		center_angle_deg;
const float DISTANCE_MMPPULSE = HW_WHEEL_RADIUS_MM*HW_STEP_DEGREE/180*PI;

/* ---------------------------------------------------------------
	ステッパの初期準備
--------------------------------------------------------------- */
void Stepper_Initialize(void){
	// プライベート変数の初期化
	center_vel_mmps = 0;
	center_dist_mm = 0;
	center_angle_deg = 0.0;
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
void Stepper_SetParameters(int32_t vel_r, int32_t vel_l,int32_t accel,int32_t distance,float angle){
	// 回転方向の設定
	if(vel_r > 0) RIGHT_CW();	else RIGHT_CCW();
	if(vel_l > 0) LEFT_CCW();	else LEFT_CW();

	// 単純なセッター
	velocity_mmps = ABS(velocity);
	accel_mmpss = accel;
	radius_mm = radius;
	distance_mm = distance;
	angle_deg = angle;
	fix_omega_radps = fix_omega;

	// 引数から計算するセッター、スラローム想定用
	if(veloity == 0){		// 超信地旋回指令の場合、上書きなど
		omega_radps = (float)300.0f/radius;
		omega_accel_radpss = (float)500.0f/radius;
	}else if(radius > 0){	// スラローム走行指令
		omega_radps = (float)velocity_mmps / radius;
		omega_accel_radpss = (float)accel_mmps /radius;
	}else{					// 直線・後退走行
		omega_radps = 0.0f;
		omega_accel_radpss = 0.0f;
	}

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
	if(ABS(distance_center) > 1.2f*ABS(distance_mm)){
		HAL_TIM_PWM_Start_IT(&htim2, 2);
		return 1;
	}
	else if(ABS(angle_center) > 1.2f*ABS(angle)){
		HAL_TIM_PWM_Start_IT(&htim2, 2);
		return 2;
	}

	// 周期時間を格納
	time_pulse_r_ms = DISTANCE_MMPPULSE / velocity_r * 1000;
	velocity_r = velocity_mmps + omega_radps*HW_TREAD_MM*0.5f;
			accel_mmpss*time_pulse_r_ms + omega_accel_radpss*time_pulse_r_ms;


	// 次回の速度を算出

	// 割り込み関連の設定を反映

	//

	return 0;
}

bool Stepper_UpdateLeft(void){
	sigma_pulse_l++;
	int32_t diff_pulse_r = sigma_pulse_r - start_pulse_r;
	int32_t diff_pulse_l = sigma_pulse_l - start_pulse_l;

	float distance_center = (diff_pulse_r + diff_pulse_l)*DISTANCE_MMPPULSE*0.50f;
	float angle_ceter = RAD2DEG((diff_pulse_r - diff_pulse_l)*DISTANCE_MMPPULSE/HW_TREAD_MM);


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
