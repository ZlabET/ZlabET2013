#if !defined(EA_C605D693_C4E5_4bae_AA91_AF78605F3679__INCLUDED_)
#define EA_C605D693_C4E5_4bae_AA91_AF78605F3679__INCLUDED_


//#include "Direction.h"

#include "GyroSensor.h"
#include "Motor.h"
#include "Tail.h"


//属性を保持するための構造体の定義
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

//公開操作
void BalanceRunner_init(BalanceRunner* this);
void BalanceRunner_run(BalanceRunner* this, int direction);

#endif /*!defined(EA_C605D693_C4E5_4bae_AA91_AF78605F3679__INCLUDED_)*/
//ここで終了
