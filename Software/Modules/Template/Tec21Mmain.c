/*
 * File:   T2PTmain.c
 * Author: Ignacius
 *
 * Created on 24 de octubre de 2016, 07:55 PM
 */

#include "types.h"
#include "li2c.h"
#include "EUSART.h"
#include "Miscelaneous.h"
#include "ci2c.h"
#include "Interrupts.h"

u8 adrs=0;
u8 rdwt=0;
u8 rd=0;
u8 nxt=0;
u8 i2cout='A';


void interrupt intrpt()
{
    if(SSP1IF&&SSP1IE)
    {
        SSP1IF=0;
        switch (li2cstep)
        {
            case 1:
                li2c_Address(ADDRBMP280,0);
                li2cstep++;
                break;
            case 2:
                li2c_Write(BMP280PRES);
                li2cstep++;
                break;
            case 3:
                li2c_RepeatStart();
                li2cstep++;
                break;
            case 4:
                li2c_Address(ADDRBMP280,1);
                li2c_StartReception();
                li2cstep++;
                break;
            case 5:
                if(nxt)
                {
                    i2cout=li2c_Read();
                    li2cstep++;
                    nxt--;
                }
                else
                {
                    i2cout=li2c_Read();
                    li2cstep=7;
                }
                break;
            case 6:
                li2c_Acknowledge();
                li2cstep=5;
                break;
            case 7:
                li2c_StopBit();
                li2cstep=0;
                break;
        }
    }
}

void main()
{
    Miscelaneous_Init();
    EUSART_Init();
    li2c_Init();
    Interrupts_Init();
    while(1)
    {
        TXREG=i2cout;
        if(rd)
        {
            
        }
        else                    //in order to read
        {
            rd=1;
            nxt=0;
            li2cstep=1; 
            li2c_StartBit();
        }
        //0: StartBit
        //1: DeviceAddress (wt)
        //2: RegisterAddress
        //3: Restart
        //4: DeviceAddress (rd)
        //5: Read (can go to 6 or 7)
        //6: acknowledge
        //7: StopBit
    }
}