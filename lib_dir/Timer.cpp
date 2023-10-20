#include "Timer.h"

Timer::Timer(uint8_t timer, uint8_t time_ms) : timer(timer){
    switch (timer){
        case 0:
            timer_freq = F_CPU / PRESCALER_8BITS;
            TCCR0A = 0;
            TCCR0B |= (1 << WGM12) | (1 << CS02); //prescaler 256 and CTC mode
            TCNT0 = 0;
            OCR0A = uint16_t{timer_freq * time_ms / 1000};
            break;
        case 1:
            timer_freq = F_CPU / PRESCALER_16BITS;
            // Initialize timer 1
            TCCR1A |= 0;
            TCCR1B |= (1 << WGM12) | (1 << CS12) | (1 << CS10); //prescaler 1024 and CTC mode
            TCNT1 = 0;
            OCR1A = uint16_t{timer_freq * time_ms / 1000};
            break;
        case 2:
            timer_freq = F_CPU / PRESCALER_8BITS;
            // Initialize timer 2
            TCCR2A = 0;
            TCCR2B |= (1 << WGM12) | (1 << CS22); //prescaler 256 and CTC mode
            TCNT2 = 0;
            OCR2A = uint16_t{timer_freq * time_ms / 1000};
            break;
        default:
            // Throw error
            break;
    }
}

Timer::~Timer(){
    // Deinitialize timer
    // reset all registers

}

void Timer::enable(){
    // Start timer
    this->reset();
    switch (timer){
        case 0:
            TIMSK0 |= (1 << OCIE0A);
            break;
        case 1:
            TIMSK1 |= (1 << OCIE1A);
            break;
        case 2:
            TIMSK2 |= (1 << OCIE2A);
            break;
        default:
            // Throw error
            break;
    }
}

void Timer::disable(){
    // Stop timer
    switch (timer){
        case 0:
            TIMSK0 &= ~(1 << OCIE0A);
            break;
        case 1:
            TIMSK1 &= ~(1 << OCIE1A);
            break;
        case 2:
            TIMSK2 &= ~(1 << OCIE2A);
            break;
        default:
            // Throw error
            break;
    }
}

void Timer::reset(){
    // Reset timer
    switch (timer){
        case 0:
            TCNT0 = 0;
            break;
        case 1:
            TCNT1 = 0;
            break;
        case 2:
            TCNT2 = 0;
            break;
        default:
            // Throw error
            break;
    }
}