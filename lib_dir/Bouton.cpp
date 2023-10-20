#include "Bouton.h"
#include <avr/interrupt.h>
#include <avr/io.h
#define F_CPU 8000000UL
#include <util/delay.h>

/*
volatile uint8_t btnState = false;
    ISR(INT0_vect)
{ // action quand l'event d'interruption int1 a lieu

    _delay_ms(30);

    btnState = true;

    EIFR |= (1 << INTF1); // oublier toutes les requetes en cours
}
*/

Bouton::Bouton(uint8_t int_N_p) : int_N(int_N_p)
{}

Bouton::~Bouton(){ }

void Bouton::setRisingEdge(int_N)
{
    reset();

    EICRA |= (1 << ISC00);

    EICRA = (1 << ISC01);
}
void Bouton::setFallingEdge(int_N)
{
    reset();

    EICRA |= (0 << ISC00);

    EICRA = (1 << ISC01);

}
void Bouton::setAnyEdge(int_N)
{
    reset();

    EICRA |= (1 << ISC00);

    EICRA = (0 << ISC01);

}

void Bouton::enableInterrupt(int_N)
{
    EIMSK |= (1 << int_N); // on active l'interruption sur int_N
}

void Bouton::disableInterrupt(int_N)
{
    EIMSK &= ~(1 << int_N); // on desactive l'interruption sur int_
}

void reset(){
    EICRA &= ~(1 << ISC00);

    EICRA &= ~(1 << ISC01);
}

