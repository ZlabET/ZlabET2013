
#include "ColorJudgement.h"
#define LIGHT_BLACK //���F�̌��Z���T
#define KP -0.7

//����������
void ColorJudgement_init(ColorJudgement* this)
{
	//LIGHT_BLACK = 0;
	this->BLACK[0] = 0;
}

//���F���L�����u���[�V��������
void ColorJudgement_calibration(ColorJudgement* this)
{
	this->BLACK[0] = LightSensor_getBrightness(this->lightSensor);

	//sprintf(buf,"%d",this->BLACK[0]);
	//ecrobot_send_bt(buf, 0, 10);

}


//�H�ʂ̐F�𔻒肷��
int ColorJudgement_caluculateDirection(ColorJudgement* this)
{
	return PID_calculation(this->pid, LightSensor_getBrightness(this->lightSensor), this->BLACK[0],  KP);

}


