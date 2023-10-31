#include <avr/io.h>
#include <util/delay.h>
#include <Communication.h>
#include <memoire_24.h>

class ByteCodeInterpreter
{
public:
    ByteCodeInterpreter();
    ~ByteCodeInterpreter();
    bool receiveAndSave();

private:
    static const uint8_t BYTE_CODE_END = 0xFF;

    Communication com;
    Memoire24CXXX memoire;
};