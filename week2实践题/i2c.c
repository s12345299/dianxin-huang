#include "i2c.h"
#include "RM.h"
void Start(void)
{
    SDA_High();
    SCL_High();
    SDA_Low();
    SCL_Low();

}
void Stop(void)
{
    SDA_Low();
    SCL_High();
    SDA_High();


}
void SendByte(unsigned char data)
{   SDA_Low();
    unsigned char a;
    for(a=0;a<8;a++){
        if(data&0x80){
             SDA_High();
        }
        else{
            SDA_Low();
        }
        SCL_High();
        SCL_Low();
        data<<=1;

    }
    SDA_High();
}
unsigned char ReceiveAck(void){
    unsigned char b;
    SCL_Low();
    SDA_High();
    SCL_High();
    if(SDA_Read())
    {
        b=1;
    }
    else{
        b=0;

    }
    SCL_Low();
    return b;
}
SendData(unsigned char data){
   Start();
   SendByte(data);
   ReceiveAck();
   Stop();

}

