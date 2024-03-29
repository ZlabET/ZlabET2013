#ifndef TAIL_H
#define TAIL_H

#include "ecrobot_interface.h"
#include "kernel.h"

// 属性を保持するための構造体の定義
typedef struct Tail{
	MOTOR_PORT_T outputPort;
}Tail;

// 公開操作
void Tail_init(Tail* this, MOTOR_PORT_T outputPort);
void Tail_control(Tail* this, float angle);

#endif
