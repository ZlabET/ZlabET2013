#include "BalanceRunner.h"
#include "balancer.h"  //�|���U�q����p�w�b�_�t�@�C��

#define LOW     20  //�ᑬ
#define NORMAL  50  //�ʏ�
#define HIGH    100//����
#define BATT  ecrobot_get_battery_voltage()  //�o�b�e���[�d��



//����������
void BalanceRunner_init(BalanceRunner* this)
{
	this->forward       = HIGH;
	this->turn          = LOW;
	this->isInitialized = FALSE;
}

//�|�����s���s��
void BalanceRunner_run(BalanceRunner* this, int derection)
{
	int turn;                           //�����𔽉f������]���x
	unsigned int gyro;
	unsigned int gyro_offset;     //�W���C���Z���T�l�A�W���C���I�t�Z�b�g�l
	long motor_ang_l;
	long motor_ang_r;      //���[�^��]�p�x
	signed char pwm_l;
	signed char pwm_r;           //���[�^PWM�o�͒l


  //�ŏ������A�|���U�q����̏������ƃ��[�^�̉�]�p�x�̃��Z�b�g���s��
	if(! this->isInitialized)
	{
		balance_init(); //�|���U�q���䏉����

		//���[�^�G���R�[�_�����Z�b�g����
		nxt_motor_set_count(NXT_PORT_C, 0);
		nxt_motor_set_count(NXT_PORT_B, 0);
 
	 //�������ς݂ɂ���
	  this->isInitialized = TRUE;
    }

	Tail_control(this->tail, 0);

	turn = derection;

	//�|���U�q����API�ɓn���p�����[�^���擾����
	//gyro_offset = GyroSensor_getOffset(this->gyroSensor);
	gyro_offset = 610;
	gyro = GyroSensor_getAngularVelocity(this->gyroSensor);
	motor_ang_l = Motor_getAngle(this->leftMotor);
	motor_ang_r = Motor_getAngle(this->rightMotor);

 //�|���U�q����API���Ăяo���A�|�����s���邽�߂̍��E���[�^�̏o�͒l�𓾂�
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

 //���E���[�^��]���w������
  Motor_rotate(this->leftMotor,pwm_l);
  Motor_rotate(this->rightMotor,pwm_r);
}
