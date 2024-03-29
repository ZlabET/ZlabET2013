#ifndef PID_H
#define PID_H

#include "ecrobot_interface.h"

// 属性を保持するための構造体の定義
typedef struct PID{
	S32 diff[2];
	F32 integral;
}PID;

// 公開操作
void PID_init(PID* this);
float PID_calculation(PID* this, U16 sensor_val, U16 target_val, float kp);

#endif
