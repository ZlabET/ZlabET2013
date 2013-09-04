#include "TouchSensor.h"

//非公開操作


//初期化する
void TouchSensor_init(TouchSensor* this, SENSOR_PORT_T inputPort)
{
	this->inputPort = inputPort;
}

	//押下状態を得る
BOOL TouchSensor_isPressed(TouchSensor* this)
{
	return ecrobot_get_touch_sensor(this->inputPort);
}


