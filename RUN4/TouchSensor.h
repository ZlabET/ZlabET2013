#if !defined(EA_6012785F_E7A6_4a38_9143_89EE66F593B1__INCLUDED_)
#define EA_6012785F_E7A6_4a38_9143_89EE66F593B1__INCLUDED_


#include "ecrobot_interface.h"
#include "kernel.h"


// ������ێ����邽�߂̍\���̂̒�`
typedef struct TouchSensor
{
	SENSOR_PORT_T inputPort;
} TouchSensor;

// ���J����
void TouchSensor_init(TouchSensor* this, SENSOR_PORT_T inputPort);
BOOL TouchSensor_isPressed(TouchSensor* this);

#endif /*!defined(EA_6012785F_E7A6_4a38_9143_89EE66F593B1__INCLUDED_)*/
