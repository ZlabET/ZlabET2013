#include "LightSensor.h"

//����J����

//����������
void LightSensor_init(LightSensor* this, SENSOR_PORT_T inputPort)
{
	this->inputPort = inputPort;
}


//�P�x�𓾂�
unsigned int LightSensor_getBrightness(LightSensor* this)
{
	return ecrobot_get_light_sensor(this->inputPort);
}