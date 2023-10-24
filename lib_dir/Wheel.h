#include <stdint.h>
#include <avr/io.h> 

typedef volatile uint16_t* Register; 

class Wheel {
public:
    Wheel(Register output);

    void setCompareValue(uint16_t value);
    

private:
    Register pOutput; 

};
