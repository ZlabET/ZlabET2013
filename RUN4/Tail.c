#include "Tail.h"

#define P_GAIN      5.0F /* ���S��~�p���[�^������W�� */
#define PWM_ABS_MAX 60 /* ���S��~�p���[�^����PWM��΍ő�l */

void Tail_init(Tail* this, MOTOR_PORT_T outputPort){
	this->outputPort = outputPort;
}

// �����ۂ���]������
void Tail_control(Tail* this, float angle)
{
	float pwm = (float)(angle - nxt_motor_get_count(this->outputPort))*P_GAIN; /* ��ᐧ�� */
	/* PWM�o�͖O�a���� */
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
