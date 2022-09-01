#include <iostream>
#include <string>
#include <SDL2/SDL.h>

int main() {
    bool running = true;

    SDL_Event e;

    SDL_Init (SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("My Window",0, 0, 800, 600, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    
    int rectX = 200;
    int rectY = 600;
    int TICKRATE = 100; //ticks per second 
    Uint32 prevUpdateTime = 0;
    Uint32 curTime;
    Uint32 accumulator = 0;
    while(running) {
        SDL_PollEvent(&e);
        if (e.type ==SDL_QUIT) {
            break;
        }
        //Tick system
        curTime = SDL_GetTicks(); 
        Uint32 timeDelta = curTime - prevUpdateTime;
        prevUpdateTime += timeDelta;

        accumulator += timeDelta;
        
        while(accumulator > 1000/TICKRATE) {
            if(rectY + 1 <= 600) {
                rectY ++;
            } else {
                rectY = 0;
            }
            accumulator -= 1000/TICKRATE;
        }
        SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( renderer );
        SDL_Rect fillRect = { rectX, rectY, 400, 300};
        SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0x00, 0xFF);
        SDL_RenderFillRect(renderer, &fillRect);
        SDL_RenderPresent( renderer);

    }
    SDL_Quit();
    return 0;
}
