#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include "ecrobot_interface.h"
#include "kernel.h"

// 属性を保持するための構造体の定義
typedef struct BlueTooth{

}BlueTooth;

// 公開操作
void BlueTooth_init(BlueTooth* this);
unsigned int BlueTooth_isReceived(BlueTooth* this);

#endif


