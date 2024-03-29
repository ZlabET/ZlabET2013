#include "Motor.h"

//非公開操作


//初期化する
void Motor_init(Motor* this, MOTOR_PORT_T outputPort)
{
	this->outputPort = outputPort;
}

//回転角度をリセットする
void Motor_resetAngle(Motor* this)
{
	return nxt_motor_set_count(this->outputPort, 0);
}

//回転角度を得る
long Motor_getAngle(Motor* this)
{
	return nxt_motor_get_count(this->outputPort);
}

//回転させる
void Motor_rotate(Motor* this, int pwm)
{
	nxt_motor_set_speed(this->outputPort, pwm, 1); //値は返さない
}
