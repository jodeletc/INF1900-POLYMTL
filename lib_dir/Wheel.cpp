#include "Wheel.h"


Wheel::Wheel(Register output) : pOutput(output){
    TCCR1A = (1<<WGM10) | (1<<COM1A1) | (1<<COM1B1);

    TCCR1B = (1<<CS11) ;

    TCCR1C = 0;
}

void Wheel::setCompareValue(uint16_t value){
    *pOutput = value;
}
