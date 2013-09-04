#include "LineTracer.h"
#include "UI.h"
#include "ColorJudgement.h"
#include "PID.h"
#include "BalanceRunner.h"
#include "TouchSensor.h"
#include "Tail.h"
#include "LightSensor.h"
#include "GyroSensor.h"
#include "Motor.h"
#include "BlueTooth.h"

#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"

#define DEVICE_NAME	"ET318"
#define PASS_KEY	"HRR318"

// �I�u�W�F�N�g��ÓI�Ɋm�ۂ���
LineTracer 	lineTracer;
UI 		ui;
ColorJudgement 	colorJudgement;
PID     pid;
BlueTooth blueTooth;
BalanceRunner 	balanceRunner;
TouchSensor 	touchSensor;
Tail    tail;
LightSensor 	lightSensor;
GyroSensor 	gyroSensor;
Motor 		leftMotor, rightMotor;

// �f�o�C�X�������p�t�b�N�֐�
// ���̊֐���nxtOSEK�N�����Ɏ��s����܂��B
void ecrobot_device_initialize()
{
	// �Z���T�A���[�^�Ȃǂ̊e�f�o�C�X�̏������֐���
	// �����Ŏ������邱�Ƃ��ł��܂�
	// �ˁ@���Z���T�ԐFLED��ON�ɂ���
	ecrobot_set_light_sensor_active(NXT_PORT_S3);
	ecrobot_init_bt_slave(PASS_KEY); /*BlueTooth�ʐM������*/
}

// �f�o�C�X�I���p�t�b�N�֐�
// ���̊֐���STOP�܂���EXIT�{�^���������ꂽ���Ɏ��s����܂��B
void ecrobot_device_terminate()
{
	// �Z���T�A���[�^�Ȃǂ̊e�f�o�C�X�̏I���֐���
	// �����Ŏ������邱�Ƃ��ł��܂��B
	// �ˁ@���Z���T�ԐFLED��OFF�ɂ���
	ecrobot_set_light_sensor_inactive(NXT_PORT_S3);
	ecrobot_term_bt_connection(); /*BlueTooth�ʐM���I��*/
}

// 1msec�������荞��(ISR�J�e�S��2)����N������郆�[�U�[�p�t�b�N�֐�
void user_1ms_isr_type2(void)
{
	// ����͉����s��Ȃ�
}

TASK(TaskMain)
{
	// �I�u�W�F�N�g�Ԃ̃����N���\�z����
	lineTracer.colorJudgement  = &colorJudgement;
	lineTracer.balanceRunner   = &balanceRunner;
	ui.touchSensor		   = &touchSensor;
	ui.tail                = &tail;
	ui.colorJudgement = &colorJudgement;
	ui.blueTooth = &blueTooth;
	colorJudgement.lightSensor = &lightSensor;
	colorJudgement.pid = &pid;
	balanceRunner.gyroSensor   = &gyroSensor;
	balanceRunner.leftMotor    = &leftMotor;
	balanceRunner.rightMotor   = &rightMotor;
	balanceRunner.tail         = &tail;

	// �e�I�u�W�F�N�g������������
	LineTracer_init(&lineTracer);
	UI_init(&ui);
	ColorJudgement_init(&colorJudgement);
	PID_init(&pid);
	BlueTooth_init(&blueTooth);
	BalanceRunner_init(&balanceRunner);
	TouchSensor_init(&touchSensor, NXT_PORT_S4);
	Tail_init(&tail, NXT_PORT_A);
	LightSensor_init(&lightSensor, NXT_PORT_S3);
	GyroSensor_init(&gyroSensor, NXT_PORT_S1);
	Motor_init(&leftMotor, NXT_PORT_C);
	Motor_init(&rightMotor, NXT_PORT_B);

	UI_calibration(&ui, 105);

	TouchSensor_init(&touchSensor, NXT_PORT_S4);

	// UI�ɊJ�n�҂����˗�����
	UI_waitStart(&ui, 105);

	// 4ms�����ŁA���C���g���[�T�Ƀg���[�X���s���˗�����
	while(1)
	{
		LineTracer_trace(&lineTracer);
		systick_wait_ms(4);
	}
}
