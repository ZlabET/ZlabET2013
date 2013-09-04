#include "PID.h"

#define DELTA_T 0.004
#define KI KP*0.157894736
#define KD KP*0.071052631

void PID_init(PID* this){
	this->diff[0] = 0;
	this->diff[1] = 0;
	this->integral = 0;
}

// PID§Œä‚Åù‰ñ‘¬“x‚ðŒvŽZ‚·‚é
float PID_calculation(PID* this, U16 sensor_val, U16 target_val, float kp){
	float KP = kp;
	static float p,i,d,val;
	
	this->diff[0] = this->diff[1];
	this->diff[1] = sensor_val - target_val;
	this->integral += (this->diff[1] + this->diff[0]) / 2.0 * DELTA_T;
	
	p = KP * this->diff[1];
	i = KI * this->integral;
	d = KD * (this->diff[1] - this->diff[0]) / DELTA_T;
	val = p + i + d;
	if(val > 100.0){
		val = 100.0;
	}
	else if(val < -100.0){
		val = -100.0;
	}
	
	return val;
}

