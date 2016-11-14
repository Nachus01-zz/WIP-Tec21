#include "Miscelaneous.h"

void Miscelaneous_Init()
{
    //TX pin
    RC4PPS=RC4TX;
    
    
    //Oscilator to 8MHz
    OSCCON=F8M;
   
}
