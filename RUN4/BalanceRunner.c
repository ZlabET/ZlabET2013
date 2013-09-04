#include "BalanceRunner.h"
#include "balancer.h"  //倒立振子制御用ヘッダファイル

#define LOW     20  //低速
#define NORMAL  50  //通常
#define HIGH    100//高速
#define BATT  ecrobot_get_battery_voltage()  //バッテリー電圧



//初期化する
void BalanceRunner_init(BalanceRunner* this)
{
	this->forward       = HIGH;
	this->turn          = LOW;
	this->isInitialized = FALSE;
}

//倒立走行を行う
void BalanceRunner_run(BalanceRunner* this, int derection)
{
	int turn;                           //方向を反映した回転速度
	unsigned int gyro;
	unsigned int gyro_offset;     //ジャイロセンサ値、ジャイロオフセット値
	long motor_ang_l;
	long motor_ang_r;      //モータ回転角度
	signed char pwm_l;
	signed char pwm_r;           //モータPWM出力値


  //最初だけ、倒立振子制御の初期化とモータの回転角度のリセットを行う
	if(! this->isInitialized)
	{
		balance_init(); //倒立振子制御初期化

		//モータエンコーダをリセットする
		nxt_motor_set_count(NXT_PORT_C, 0);
		nxt_motor_set_count(NXT_PORT_B, 0);
 
	 //初期化済みにする
	  this->isInitialized = TRUE;
    }

	Tail_control(this->tail, 0);

	turn = derection;

	//倒立振子制御APIに渡すパラメータを取得する
	//gyro_offset = GyroSensor_getOffset(this->gyroSensor);
	gyro_offset = 610;
	gyro = GyroSensor_getAngularVelocity(this->gyroSensor);
	motor_ang_l = Motor_getAngle(this->leftMotor);
	motor_ang_r = Motor_getAngle(this->rightMotor);

 //倒立振子制御APIを呼び出し、倒立走行するための左右モータの出力値を得る
 balance_control(
	 (float)this->forward,
	 (float)turn,
	 (float)gyro,
	 (float)gyro_offset,
	 (float)motor_ang_l,
	 (float)motor_ang_r,
	 BATT,
	 (signed char*)&pwm_l, (signed char*)&pwm_r
	 );

	//ecrobot_bt_data_logger(flag,this->forward);

 //左右モータ回転を指示する
  Motor_rotate(this->leftMotor,pwm_l);
  Motor_rotate(this->rightMotor,pwm_r);
}
