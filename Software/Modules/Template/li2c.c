#include "li2c.h"

void li2c_Init()
{
    SDAIO=1;                    //SDA must be set to input before initializing
    SCLIO=1;                    //SCL must be set to input before initializing
    
    //This coult go in Miscelaneous
    SDAPI=0b10001;              //SDA Input pin to RC1
    SCLPI=0b10000;              //SCL Input pin to RC0
    SDAPO=0b10001;              //SDA Output pin to RC1
    SCLPO=0b10000;              //SCL Output pin to RC0
    
    SSPEN=1;                    //Module enable
    SSP1CON1bits.SSPM=0b1000;   //I2C Master mode,
    SSP1ADD=2;                  //clock=FOSC/(4*(SSPxADD+1))
    
}

void li2c_StartBit()
{
    SEN=1;
}

void li2c_StopBit()
{
    PEN=1;
}

void li2c_RepeatStart()
{
    RSEN=1;
}

void li2c_Address(u8 address, u8 rd)
{
    u8 output;
    output=(address<<1);
    output+=rd;
    SSP1BUF=output;
}

void li2c_Write(u8 message)
{
    SSP1BUF=message;
}

u8 li2c_Read()
{
    return SSP1BUF;
}

void li2c_StartReception()
{
    RCEN=1;
}

void li2c_Acknowledge()
{
    ACKEN=1;
}
