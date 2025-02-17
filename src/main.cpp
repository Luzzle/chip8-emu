#include "include/Window.h"

#include <iostream>


int main(void){
    Window* p_window = new Window();
    
    while (!p_window->windowShouldClose()){
        p_window->pollEvent();
        p_window->draw();
    }

    return 0;
}