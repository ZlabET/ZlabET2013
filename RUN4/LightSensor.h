#if !defined(EA_864E58A2_E079_47f7_A30D_E7178C933A70_INCLUDED_)
#define EA_864E58A2_E079_47f7_A30D_E7178C933A70_INCLUDED_

#include "ecrobot_interface.h"
#include "kernel.h"



//������ێ����邽�߂̍\���̂̒�`
typedef struct LightSensor
{
  SENSOR_PORT_T inputPort;
} LightSensor;

//���J����
void LightSensor_init(LightSensor* this, SENSOR_PORT_T inputPort);
unsigned int LightSensor_getBrightness(LightSensor* this);

#endif /*!defined(EA_864E58A2_E079_47f7_A30D_E7178C933A70_INCLUDED_)*/
//�����ŏI��
