#include "Tail.h"

#define P_GAIN      5.0F /* 完全停止用モータ制御比例係数 */
#define PWM_ABS_MAX 60 /* 完全停止用モータ制御PWM絶対最大値 */

void Tail_init(Tail* this, MOTOR_PORT_T outputPort){
	this->outputPort = outputPort;
}

// しっぽを回転させる
void Tail_control(Tail* this, float angle)
{
	float pwm = (float)(angle - nxt_motor_get_count(this->outputPort))*P_GAIN; /* 比例制御 */
	/* PWM出力飽和処理 */
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
