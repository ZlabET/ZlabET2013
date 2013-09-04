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

// オブジェクトを静的に確保する
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

// デバイス初期化用フック関数
// この関数はnxtOSEK起動時に実行されます。
void ecrobot_device_initialize()
{
	// センサ、モータなどの各デバイスの初期化関数を
	// ここで実装することができます
	// ⇒　光センサ赤色LEDをONにする
	ecrobot_set_light_sensor_active(NXT_PORT_S3);
	ecrobot_init_bt_slave(PASS_KEY); /*BlueTooth通信初期化*/
}

// デバイス終了用フック関数
// この関数はSTOPまたはEXITボタンが押された時に実行されます。
void ecrobot_device_terminate()
{
	// センサ、モータなどの各デバイスの終了関数を
	// ここで実装することができます。
	// ⇒　光センサ赤色LEDをOFFにする
	ecrobot_set_light_sensor_inactive(NXT_PORT_S3);
	ecrobot_term_bt_connection(); /*BlueTooth通信を終了*/
}

// 1msec周期割り込み(ISRカテゴリ2)から起動されるユーザー用フック関数
void user_1ms_isr_type2(void)
{
	// 今回は何も行わない
}

TASK(TaskMain)
{
	// オブジェクト間のリンクを構築する
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

	// 各オブジェクトを初期化する
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

	// UIに開始待ちを依頼する
	UI_waitStart(&ui, 105);

	// 4ms周期で、ライントレーサにトレース走行を依頼する
	while(1)
	{
		LineTracer_trace(&lineTracer);
		systick_wait_ms(4);
	}
}
