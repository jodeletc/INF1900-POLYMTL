#include <stdint.h>
#include <unordered_map>

struct TimerConfig
{
    uint8_t timer;      // Choix du timer: 0, 1, ou 2
    uint16_t prescaler; // Valeur du prescaler
    uint16_t delay_ms;  // Délai en millisecondes
};

std::unordered_map<uint16_t, uint8_t> TIMER0_2_PRESCALERS_MAP = {
    {1, (1 << CS00)},
    {8, (1 << CS01)},
    {64, (1 << CS01) | (1 << CS00)},
    {256, (1 << CS02)}};

std::unordered_map<uint16_t, uint8_t> TIMER1_PRESCALERS_MAP = {
    {1, (1 << CS10)},
    {8, (1 << CS11)},
    {64, (1 << CS11) | (1 << CS10)},
    {256, (1 << CS12)},
    {1024, (1 << CS12) | (1 << CS10)}};

class Timer
{
public:
    Timer(TimerConfig config);
    ~Timer();
    void enable();
    void disable();
    void reset();

    static const uint32_t F_CPU = 8000000UL;
    static const uint32_t PRESCALER_8BITS = 256;
    static const uint32_t PRESCALER_16BITS = 1024;

private:
    TimerConfig config;
    uint16_t timer_freq;
}