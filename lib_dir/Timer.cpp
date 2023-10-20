#include "Timer.h"

Timer::Timer(TimerConfig config_p) : config(config_p)
{

    switch (config.timer)
    {
    case 0:
        if (TIMER0_2_PRESCALERS_MAP.find(config.prescaler) != TIMER0_2_PRESCALERS_MAP.end())
        {
            timer_freq = F_CPU / config.prescaler;
            TCCR0A = 0;
            TCCR0B |= (1 << WGM12) | TIMER0_2_PRESCALERS_MAP[config.prescaler]; // prescaler 256 and CTC mode
            TCNT0 = 0;
            OCR0A = uint16_t{timer_freq * config.delay_ms / 1000};
        }
        break;
    case 1:
        if (TIMER1_PRESCALERS_MAP.find(config.prescaler) != TIMER1_PRESCALERS_MAP.end())
        {
            timer_freq = F_CPU / config.prescaler;
            TCCR1A |= 0;
            TCCR1B |= (1 << WGM12) | TIMER1_PRESCALERS_MAP[config.prescaler]; // prescaler 1024 and CTC mode
            TCNT1 = 0;
            OCR1A = uint16_t{timer_freq * config.delay_ms / 1000};
        }
        break;
    case 2:
        if (TIMER0_2_PRESCALERS_MAP.find(config.prescaler) != TIMER0_2_PRESCALERS_MAP.end())
        {
            timer_freq = F_CPU / config.prescaler;
            TCCR2A = 0;
            TCCR2B |= (1 << WGM12) | TIMER0_2_PRESCALERS_MAP[config.prescaler]; // prescaler 256 and CTC mode
            TCNT2 = 0;
            OCR2A = uint16_t{timer_freq * config.delay_ms / 1000};
        }
        break;
    }
}

Timer::~Timer()
{
}

void Timer::enable()
{
    // Start timer
    this->reset();
    switch (config.timer)
    {
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

void Timer::disable()
{
    // Stop timer
    switch (config.timer)
    {
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

void Timer::reset()
{
    // Reset timer
    switch (config.timer)
    {
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