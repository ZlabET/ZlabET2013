#include "UI.h"


void UI_init(UI* this)
{
	// 何もしない
}

void UI_calibration(UI* this, float angle)
{
	while(1)
	{
		Tail_control(this->tail, angle);

		//ecrobot_bt_data_logger(0,0);

		if(TouchSensor_isPressed(this->touchSensor))
		{
		ColorJudgement_calibration(this->colorJudgement);

		while(TouchSensor_isPressed(this->touchSensor)){

		}
		break;
		}
	}
}


void UI_waitStart(UI* this, float angle)
{
	// タッチセンサが押されるまで、待ち続ける
	while(1)
	{
		Tail_control(this->tail, angle);
		
		if(TouchSensor_isPressed(this->touchSensor))
		{
			//ColorJudgement_calibration(this->colorJudgement);
			Tail_control(this->tail, 0);
			break;		// タッチセンサが押された
		}
		

		if(BlueTooth_isReceived(this->blueTooth) == 1)
		{
			Tail_control(this->tail, 0);
			break;		// BlueToothよりスタート指示がでた
		}
	}
} 

