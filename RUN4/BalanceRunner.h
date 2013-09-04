#if !defined(EA_C605D693_C4E5_4bae_AA91_AF78605F3679__INCLUDED_)
#define EA_C605D693_C4E5_4bae_AA91_AF78605F3679__INCLUDED_


//#include "Direction.h"

#include "GyroSensor.h"
#include "Motor.h"
#include "Tail.h"


//������ێ����邽�߂̍\���̂̒�`
typedef struct BalanceRunner
{
	int forward;
	int turn;
	BOOL isInitialized;
	GyroSensor *gyroSensor;
	Motor *leftMotor;
	Motor *rightMotor;
	Tail *tail;
} BalanceRunner;

//���J����
void BalanceRunner_init(BalanceRunner* this);
void BalanceRunner_run(BalanceRunner* this, int direction);

#endif /*!defined(EA_C605D693_C4E5_4bae_AA91_AF78605F3679__INCLUDED_)*/
//�����ŏI��
