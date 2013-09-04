#ifndef TAIL_H
#define TAIL_H

#include "ecrobot_interface.h"
#include "kernel.h"

// ������ێ����邽�߂̍\���̂̒�`
typedef struct Tail{
	MOTOR_PORT_T outputPort;
}Tail;

// ���J����
void Tail_init(Tail* this, MOTOR_PORT_T outputPort);
void Tail_control(Tail* this, float angle);

#endif
