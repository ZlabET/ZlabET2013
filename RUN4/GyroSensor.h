#if !defined(EA_C2A0622D_F813_42cd_9E79_9CA85E572752__INCLUDED_)
#define EA_C2A0622D_F813_42cd_9E79_9CA85E572752__INCLUDED_

#include "ecrobot_interface.h"
#include "kernel.h"

// 属性を保持するための構造体の定義
typedef struct GyroSensor
{
	unsigned int offset;
	SENSOR_PORT_T inputPort;
} GyroSensor;

// 公開操作
void GyroSensor_init(GyroSensor* this, SENSOR_PORT_T inputPort);
unsigned int GyroSensor_getAngularVelocity(GyroSensor* this);
unsigned int GyroSensor_getOffset(GyroSensor* this);

#endif /*!define(EA_C2A0622D_F813_42cd_9E79_9CA85E572752_INCLUDED_)*/
