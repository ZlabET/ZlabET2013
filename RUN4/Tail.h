#ifndef TAIL_H
#define TAIL_H

#include "ecrobot_interface.h"
#include "kernel.h"

// ‘®«‚ğ•Û‚·‚é‚½‚ß‚Ì\‘¢‘Ì‚Ì’è‹`
typedef struct Tail{
	MOTOR_PORT_T outputPort;
}Tail;

// ŒöŠJ‘€ì
void Tail_init(Tail* this, MOTOR_PORT_T outputPort);
void Tail_control(Tail* this, float angle);

#endif
