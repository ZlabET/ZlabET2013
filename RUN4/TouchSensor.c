#include "TouchSensor.h"

//”ñŒöŠJ‘€ì


//‰Šú‰»‚·‚é
void TouchSensor_init(TouchSensor* this, SENSOR_PORT_T inputPort)
{
	this->inputPort = inputPort;
}

	//‰Ÿ‰ºó‘Ô‚ð“¾‚é
BOOL TouchSensor_isPressed(TouchSensor* this)
{
	return ecrobot_get_touch_sensor(this->inputPort);
}


