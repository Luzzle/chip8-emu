#include "include/Window.h"
#include "include/CPU.h"

#include <iostream>
#include <assert.h>

int main(int argc, char** argv){

    if (argc != 2){
        std::cerr << "Some error message ill write later" << std::endl;
        exit(-1);
    }

    CPU* cpu = new CPU();
    cpu->loadROM(argv[1]);

    //Window* p_window = new Window();
    

    /*
    while (!p_window->windowShouldClose()){
        p_window->pollEvents();
        p_window->draw();
    }
    */
    
    return 0;
}