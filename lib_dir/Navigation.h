#include <stdint.h>
#include <avr/io.h> 


class Navigation {
public:
    Navigation();

    void forward ();
    void backward ();
    

private:
    Register pOutput; 

};
