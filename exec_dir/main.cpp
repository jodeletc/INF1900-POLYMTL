#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h> 
#include "Wheel.h"

// constexpr uint8_t DEBOUNCE_TIME = 10;

// bool isButtonPressed() {return (PIND & (1 << PD2));}

// bool isDebounce()
// {
//     if(isButtonPressed())
//     {
//         _delay_ms(DEBOUNCE_TIME);
//         return isButtonPressed();
//     }
//     return false;
// }

int main()
{
    //Led led(&PORTA, &DDRA, PA0, PA1);

    DDRD |= (1<< PD4) | (1<< PD5) |(1<< PD6) | (1<< PD7);

    DDRA = (1<< DDA0)| (1<< DDA1);
    PORTA |= (1 << PA0); //Green quand on avance
    // while(true)
    // {
    //     //  led.turnLedGreen();
    //     // _delay_ms(3000);
    //     led.turnLedAmber();
    //     // _delay_ms(3000);
    //     // led.turnLedRed();
    //     // _delay_ms(6000);
    // }

    uint16_t i = 255;
    Wheel wheelR(&OCR1A);
    

    Wheel wheelL(&OCR1B);

    while(i > 0){
        wheelR.setCompareValue(0xFF);
        wheelL.setCompareValue(i);
        i -= 20;
        _delay_ms(1000);
        wheelR.setCompareValue(0x00);
        wheelL.setCompareValue(0x00);
         _delay_ms(1000);
//         wheelR.setCompareValue(0xEF);
//         wheelL.setCompareValue(0x00);
//          _delay_ms(2000);
//         wheelR.setCompareValue(100);
//         wheelL.setCompareValue(0x00);
//          _delay_ms(2000);
//         wheelR.setCompareValue(50);
//         wheelL.setCompareValue(0x00);
//  _delay_ms(2000);
//         wheelR.setCompareValue(25);
//         wheelL.setCompareValue(0x00);
//  _delay_ms(2000);
//         wheelR.setCompareValue(20);
//         wheelL.setCompareValue(0x00);
//  _delay_ms(2000);
//         wheelR.setCompareValue(15);
//         wheelL.setCompareValue(0x00);
//  _delay_ms(2000);
//         wheelR.setCompareValue(10);
//         wheelL.setCompareValue(0x00);
//  _delay_ms(2000);
//         wheelR.setCompareValue(05);
//         wheelL.setCompareValue(0x00);
//  _delay_ms(2000);
//         wheelR.setCompareValue(0);
//         wheelL.setCompareValue(0x00);

    }
   
    return 0;
}
 
