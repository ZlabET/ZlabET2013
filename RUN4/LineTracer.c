#include "LineTracer.h"
#include "Direction.h"
#include "Color.h"

//初期化する
void LineTracer_init(LineTracer* this)
{
	//初期化しない
}

//ラインをトレースする
void LineTracer_trace(LineTracer* this)
{
	//COLOR color;                        //路面の色
	//DIRECTION direction;                //走行体の向き

	int turn;

    //走行体の進む量を計算する
	turn = ColorJudgement_caluculateDirection(this->colorJudgement);

	//倒立走行を行う
	BalanceRunner_run(this->balanceRunner, turn);
}


