#include "BlueTooth.h"


#define CMD_START   '1'


void BlueTooth_init(BlueTooth* this){

}

// ブルートゥース信号を受け取る
unsigned int BlueTooth_isReceived(BlueTooth* this)
{
	int i;
	char rx_buf[BT_MAX_RX_BUF_SIZE];
	unsigned int rx_len;
	unsigned char start = 0;

	for (i=0; i<BT_MAX_RX_BUF_SIZE; i++)
	{
		rx_buf[i] = 0; /* 受信バッファをクリア */
	}

	rx_len = ecrobot_read_bt(rx_buf, 0, BT_MAX_RX_BUF_SIZE);
	if (rx_len > 0)
	{
		/* 受信データあり */
		if (rx_buf[0] == CMD_START)
		{
			start = 1; /* 走行開始 */
		}
		ecrobot_send_bt(rx_buf, 0, rx_len); /* 受信データをエコーバック */
	}

	return start;
}
