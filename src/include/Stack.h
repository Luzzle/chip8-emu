#ifndef C8_STACK_H
#define C8_STACK_H

#include <deque>

class Stack{
    private:
        std::deque<u_int16_t>* stack;

    public:
        Stack();
        u_int16_t pop();
        void push(u_int16_t);
};

#endif