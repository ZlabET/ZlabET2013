#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include "ecrobot_interface.h"
#include "kernel.h"

// ������ێ����邽�߂̍\���̂̒�`
typedef struct BlueTooth{

}BlueTooth;

// ���J����
void BlueTooth_init(BlueTooth* this);
unsigned int BlueTooth_isReceived(BlueTooth* this);

#endif


