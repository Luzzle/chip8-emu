#ifndef C8_CPU_H
#define C8_CPU_H

#include "Stack.h"

#include <string>

using BYTE = u_int8_t;

class CPU{
    private:
        // registers
        u_int16_t pc;
        u_int16_t i;

        u_int8_t V[16];
        Stack stack;

        // ram
        BYTE RAM[4096];
        BYTE gfx[64 * 32];
        
        u_int16_t opcode;

    public:
        CPU();
        
        void loadROM(char*);

};

#endif