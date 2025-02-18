#include "include/Window.h"
#include "include/CPU.h"

#include <iostream>
#include <bitset>

int main(void){
    CPU* cpu = new CPU();

    Window* p_window = new Window();
    
    while (!p_window->windowShouldClose()){
        p_window->pollEvents();
        p_window->draw();
    }

    return 0;
}