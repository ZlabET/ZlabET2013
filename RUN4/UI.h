#if !defined(EA_FB3DF40C_CBF0_454a_9BA8_39674A045269__INCLUDED_)
#define EA_FB3DF40C_CBF0_454a_9BA8_39674A045269__INCLUDED_

#include "TouchSensor.h"
#include "Tail.h"
#include "ColorJudgement.h"
#include "BlueTooth.h"

#include "kernel.h"
#include "ecrobot_interface.h"

// 属性を保持するための構造体の定義
typedef struct UI
{
	ColorJudgement *colorJudgement;
	TouchSensor *touchSensor;
	Tail *tail;
	BlueTooth *blueTooth;
} UI;

// 公開操作
void UI_init(UI* this);
void UI_calibration(UI* this, float angle);
void UI_waitStart(UI* this, float angle);

#endif /*!defined(EA_FB3DF40C_CBF0_454a_9BA8_39674A045269__INCLUDED_)*/

