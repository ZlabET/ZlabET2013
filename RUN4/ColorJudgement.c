
#include "ColorJudgement.h"
#define LIGHT_BLACK //黒色の光センサ
#define KP -0.7

//初期化する
void ColorJudgement_init(ColorJudgement* this)
{
	//LIGHT_BLACK = 0;
	this->BLACK[0] = 0;
}

//黒色をキャリブレーションする
void ColorJudgement_calibration(ColorJudgement* this)
{
	this->BLACK[0] = LightSensor_getBrightness(this->lightSensor);

	//sprintf(buf,"%d",this->BLACK[0]);
	//ecrobot_send_bt(buf, 0, 10);

}


//路面の色を判定する
int ColorJudgement_caluculateDirection(ColorJudgement* this)
{
	return PID_calculation(this->pid, LightSensor_getBrightness(this->lightSensor), this->BLACK[0],  KP);

}


