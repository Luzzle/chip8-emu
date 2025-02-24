#include "include/Stack.h"

#include <iostream>
#include <assert.h>

u_int16_t Stack::pop(){

    assert(stack->size() > 0);

    u_int16_t front = stack->front();
    stack->pop_front();
    
    return front;
}

void Stack::push(u_int16_t addr){
    stack->push_front(addr);
}

Stack::Stack(){
    stack = new std::deque<u_int16_t>();
}

