#include "LineTracer.h"
#include "Direction.h"
#include "Color.h"

//����������
void LineTracer_init(LineTracer* this)
{
	//���������Ȃ�
}

//���C�����g���[�X����
void LineTracer_trace(LineTracer* this)
{
	//COLOR color;                        //�H�ʂ̐F
	//DIRECTION direction;                //���s�̂̌���

	int turn;

    //���s�̂̐i�ޗʂ��v�Z����
	turn = ColorJudgement_caluculateDirection(this->colorJudgement);

	//�|�����s���s��
	BalanceRunner_run(this->balanceRunner, turn);
}


