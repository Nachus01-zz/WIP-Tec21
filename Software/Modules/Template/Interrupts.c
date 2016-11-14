#include "Interrupts.h"

void Interrupts_Init()
{
    GIE=1;      //Global interrupts
    PEIE=1;     //Peripheral interrupts
    
    TXIE=1;     //UART Transmission
    TXIF=0;
    
    RCIE=1;     //UART Reception
    RCIF=0;
    
    SSP1IE=1;   //li2c Interrupt
    SSP1IF=0;
}