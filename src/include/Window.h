#ifndef C8_WINDOW_H
#define C8_WINDOW_H

#include <SDL2/SDL.h>
#include <string>

class Window{
    private:
        SDL_Window* p_window;
        SDL_Surface* p_windowSurface;

        bool b_windowShouldClose = false;
        
    public:
        Window();
        
        void pollEvents();
        void draw();
        bool windowShouldClose();
};

#endif