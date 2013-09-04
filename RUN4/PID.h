#ifndef PID_H
#define PID_H

#include "ecrobot_interface.h"

// ‘®«‚ğ•Û‚·‚é‚½‚ß‚Ì\‘¢‘Ì‚Ì’è‹`
typedef struct PID{
	S32 diff[2];
	F32 integral;
}PID;

// ŒöŠJ‘€ì
void PID_init(PID* this);
float PID_calculation(PID* this, U16 sensor_val, U16 target_val, float kp);

#endif
