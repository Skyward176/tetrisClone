#include <iostream>
#include <string>
#include <SDL2/SDL.h>

void OpenNewWindow() {
    SDL_Init (SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("My Window",0, 0, 800, 600, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
}

int main() {
    bool quit = false;

    SDL_Event event;

    OpenNewWindow();
    while(!quit) {
        SDL_WaitEvent(&event);

        switch(event.type) {
            case SDL_QUIT:
                quit = true;
                break;
        }
    }
    SDL_Quit();
    return 0;
}
