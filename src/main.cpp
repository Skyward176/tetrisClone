#include <iostream>
#include <string>
#include <SDL2/SDL.h>

struct Rect{
    int posX;
    int posY;
    int sizeX;
    int sizeY;
};

void handleSidewaysMovement(Rect* rect, int direction) {
    switch(direction){
        case -1: 
            if(rect->posX>0){
                rect->posX -=10;
            }
            break;
        case 1:
            if(rect->posX<800-rect->sizeX){
                rect->posX +=10;
            }
            break;
    }
}

int main() {
    int TICKRATE = 100; //ticks per second 

    SDL_Init (SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Not Tetris",0, 0, 800, 600, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    
    // Tick Logic
    Uint32 prevUpdateTime = 0;
    Uint32 curTime;
    Uint32 accumulator = 0;


    //instantiate rect struct
    Rect testRect;
    testRect.posX=200;
    testRect.posY=600;
    testRect.sizeX=200;
    testRect.sizeY=150;
    
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    bool running = true;
    while(running) {
        SDL_Event e;
        while(SDL_PollEvent(&e)){
            switch(e.type){
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_KEYDOWN:
                    switch(e.key.keysym.sym){
                        case SDLK_LEFT:
                            handleSidewaysMovement(&testRect, -1);
                            break;
                        case SDLK_RIGHT:
                            handleSidewaysMovement(&testRect, 1);
                            break;
                    }
            }
        }

        //Tick system
        curTime = SDL_GetTicks(); 
        Uint32 timeDelta = curTime - prevUpdateTime;
        prevUpdateTime += timeDelta;

        accumulator += timeDelta;
        
        while(accumulator > 1000/TICKRATE) {
            if(testRect.posY + 1 <= 600) {
                testRect.posY ++;
            } else {
                testRect.posY = 0;
            }
            accumulator -= 1000/TICKRATE;
        }

        SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( renderer );
        SDL_Rect fillRect = { testRect.posX, testRect.posY, testRect.sizeX, testRect.sizeY};
        SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0x00, 0xFF);
        SDL_RenderFillRect(renderer, &fillRect);
        SDL_RenderPresent( renderer);

    }
    SDL_Quit();
    return 0;
}
