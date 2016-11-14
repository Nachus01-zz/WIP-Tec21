#include "EUSART.h"

void EUSART_Init()
{
    SPBRG=12;
    SPEN=1;
    SYNC=0;
    TXEN=1;
    CREN=1;
}

