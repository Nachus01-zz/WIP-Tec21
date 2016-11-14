/* 
 * File:   i2c.h
 * Author: Ignacius
 *
 * Created on 8 de noviembre de 2016, 08:54 PM
 */

#ifndef I2C_H
#define	I2C_H
#define SDAR PORTCbits.RC1
#define SCLR PORTCbits.RC0
#define SDAW LATCbits.LATC1
#define SCLW LATCbits.LATC0
#define SDAIO TRISCbits.TRISC1
#define SCLIO TRISCbits.TRISC0
#define SDAPI SSPDATPPS
#define SCLPI SSPCLKPPS
#define SDAPO RC1PPS
#define SCLPO RC0PPS
#define ADDRBMP280 0x77
#define ADDRHTU21D 0x40
#define BMP280PRES 0xF7
#define BMP280TEMP 0xFA
#define HTU21DTEMP 0xE3
#define HTU21DHMDT 0xE5

#include<pic16lf1705.h>
#include"types.h"

u8 li2cstep=0;

void li2c_Init();

void li2c_StartBit();

void li2c_StopBit();

void li2c_RepeatStart();

void li2c_Address(u8 address, u8 rd);

void li2c_Write(u8 message);

u8 li2c_Read();

void li2c_StartReception();

void li2c_Acknowledge();

#endif	/* I2C_H */

