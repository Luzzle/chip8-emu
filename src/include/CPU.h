#ifndef C8_CPU_H
#define C8_CPU_H

#include "Stack.h"

#include <string>

using BYTE = unsigned char;

class CPU{
    private:
        u_int16_t pc = 0;
        u_int16_t i = 0;
        // stack
        u_int16_t V[16];
        

    public:
        CPU();
        Stack* stack = new Stack();

        BYTE RAM[4096];

        
};

#endif