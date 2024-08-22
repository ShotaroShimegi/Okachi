/*
 * 10_state.h
 *
 *  Created on: Aug 12, 2024
 *      Author: sssho
 */

#ifndef MOUSE_COMPONENT_INC_STATE_H_
#define MOUSE_COMPONENT_INC_STATE_H_

#include <stdint.h>

#include "02_interface_led.h"
#include "04_battery.h"
#include "05_ir_sensor.h"
#include "06_stepper.h"
#include "08_clock.h"

typedef struct StateMouse{
	uint8_t wall_info;
	uint32_t distance_mm;
	float vel_mmps;
	float accel_mmpss;
	float theta_deg;
	float omega_radps;
	float omega_accel_radpss;
	uint8_t run_mode;
} STATE_MOUSE;

typedef struct StateSensor{
	uint32_t dist_r_mm;
	uint32_t dist_l_mm;
	float theta_deg;

};

enum {
	STOP = 0,
	STRAIGHT_DECEL = 1,
	STRAIGHT_ACCEL = 2,
	BACK_DECEL = 3,
	BACK_ACCEL = 4,
	SPIN_DECEL = 5,
	SPIN_ACCEL = 6,
	TURN_R_DECEL = 7,
	TURN_R_ACCEL = 8,
	TURN_L_DECEL = 9,
	TURN_L_ACCEL = 10
}RUN_MODE;

#endif /* MOUSE_COMPONENT_INC_STATE_H_ */
