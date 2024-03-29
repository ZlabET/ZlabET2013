#include "GyroSensor.h"
#define GYRO_OFFSET 610

//非公開操作

//初期化する
void GyroSensor_init(GyroSensor* this, SENSOR_PORT_T inputPort)
{
	this->inputPort = inputPort;
	this->offset = GYRO_OFFSET;
}

unsigned int GyroSensor_getAngularVelocity(GyroSensor* this)
{
	return ecrobot_get_gyro_sensor(this->inputPort);
}

unsigned int GyroSensor_getOffset(GyroSensor* this)
{
	return this->offset;
}