
#if !defined(EA_DEA59006_B221_4c87_BCC1_054497B43B1E__INCLUDED_)
#define EA_DEA59006_B221_4c87_BCC1_054497B43B1E__INCLUDED_

#include "Color.h"
#include "LightSensor.h"
#include "PID.h"


//������ێ����邽�߂̍\���̂̒�`
typedef struct ColorJudgement
{
	U16 BLACK[1];
    LightSensor *lightSensor;
	PID *pid;
} ColorJudgement;

//���J����
void ColorJudgement_init(ColorJudgement* this);
int ColorJudgement_caluculateDirection(ColorJudgement* this);
void ColorJudgement_calibration(ColorJudgement* this);

#endif /*!defined(EA_DEA59006_B221_4c87_BCC1_054497B43B1E__INCLUDED_)*/
