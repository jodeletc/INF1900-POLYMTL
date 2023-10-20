#include <stdint.h>

class Timer{
    public:
        Timer(uint8_t timer, uint8_t time_ms);
        ~Timer();
        void enable();
        void disable();
        void reset();

        static const uint32_t F_CPU = 8000000UL;
        static const uint32_t PRESCALER_8BITS = 256;
        static const uint32_t PRESCALER_16BITS = 1024;

    private:
        uint8_t timer;
        uint16_t timer_freq;
}