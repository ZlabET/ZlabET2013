#include "Motor.h"

//”ñŒöŠJ‘€ì


//‰Šú‰»‚·‚é
void Motor_init(Motor* this, MOTOR_PORT_T outputPort)
{
	this->outputPort = outputPort;
}

//‰ñ“]Šp“x‚ðƒŠƒZƒbƒg‚·‚é
void Motor_resetAngle(Motor* this)
{
	return nxt_motor_set_count(this->outputPort, 0);
}

//‰ñ“]Šp“x‚ð“¾‚é
long Motor_getAngle(Motor* this)
{
	return nxt_motor_get_count(this->outputPort);
}

//‰ñ“]‚³‚¹‚é
void Motor_rotate(Motor* this, int pwm)
{
	nxt_motor_set_speed(this->outputPort, pwm, 1); //’l‚Í•Ô‚³‚È‚¢
}
