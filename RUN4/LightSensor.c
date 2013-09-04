#include "LightSensor.h"

//”ñŒöŠJ‘€ì

//‰Šú‰»‚·‚é
void LightSensor_init(LightSensor* this, SENSOR_PORT_T inputPort)
{
	this->inputPort = inputPort;
}


//‹P“x‚ð“¾‚é
unsigned int LightSensor_getBrightness(LightSensor* this)
{
	return ecrobot_get_light_sensor(this->inputPort);
}