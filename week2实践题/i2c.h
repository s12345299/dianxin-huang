#ifndef i2c.h
#define i2c.h
#include "RM.h"
void Start(void);
void Stop(void);
void SendByte(unsigned char data);
unsigned char ReceiveAck(void);
void SendData(unsigned char data);
#endif