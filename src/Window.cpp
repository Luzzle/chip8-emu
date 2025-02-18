#include "include/Window.h"

#include <iostream>

Window::Window(){
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "Failed to initialize the SDL2 library\n";
        exit(-1);
    }

    p_window = SDL_CreateWindow("Chip-8 Emulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 320, SDL_WINDOW_RESIZABLE);

    if(!p_window)
    {
        std::cerr << "Failed to create window\n";
        exit(-1);
    }


    p_windowSurface = SDL_GetWindowSurface(p_window);
    if(!p_windowSurface)
    {
        std::cerr << "Failed to get the surface from the window\n";
        exit(-1);
    }

}

void Window::pollEvents(){
    SDL_Event e;
    if (SDL_PollEvent(&e) > 0)
    {
        switch(e.type)
        {
            case SDL_QUIT:
                b_windowShouldClose = true;
                break;
        }
    }
}

void Window::draw(){
    SDL_UpdateWindowSurface(p_window);
}

bool Window::windowShouldClose(){
    return b_windowShouldClose;
}