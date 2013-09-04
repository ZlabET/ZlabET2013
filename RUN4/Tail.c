#include "Tail.h"

#define P_GAIN      5.0F /* Š®‘S’âŽ~—pƒ‚[ƒ^§Œä”ä—áŒW” */
#define PWM_ABS_MAX 60 /* Š®‘S’âŽ~—pƒ‚[ƒ^§ŒäPWMâ‘ÎÅ‘å’l */

void Tail_init(Tail* this, MOTOR_PORT_T outputPort){
	this->outputPort = outputPort;
}

// ‚µ‚Á‚Û‚ð‰ñ“]‚³‚¹‚é
void Tail_control(Tail* this, float angle)
{
	float pwm = (float)(angle - nxt_motor_get_count(this->outputPort))*P_GAIN; /* ”ä—á§Œä */
	/* PWMo—Í–O˜aˆ— */
	if (pwm > PWM_ABS_MAX)
	{
		pwm = PWM_ABS_MAX;
	}
	else if (pwm < -PWM_ABS_MAX)
	{
		pwm = -PWM_ABS_MAX;
	}

	nxt_motor_set_speed(this->outputPort, (signed char)pwm, 1);
}
