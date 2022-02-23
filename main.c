
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "include/win.h"
#include "include/render.h"
#include "include/logic.h"



int main(int argc, char *argv[]){

	if(SDL_Init(SDL_INIT_VIDEO) != 0){
        fprintf(stderr, "SDL could not iniatialize: SDL Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window *window = SDL_CreateWindow("Life", 
    									  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
    									  SCREEN_WIDTH, SCREEN_HEIGHT, 
    									  SDL_WINDOW_SHOWN);

    if(window == NULL){
        fprintf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window,
    											-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); // use default graphics card to do rendering rather than CPU
    
    if(renderer == NULL){
        SDL_DestroyWindow(window);
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Surface *surface = IMG_Load("resources/icon.png");
    SDL_SetWindowIcon(window, surface);
    SDL_FreeSurface(surface);

    world_t world = {
        .grid = {DEAD},
        .state = RUNNING_STATE
    };

    world.grid[5][5] = ALIVE;
    world.grid[1][9] = ALIVE;
    world.grid[12][8] = ALIVE;
    
    SDL_Event event;
    short int quit = 0;

    while(!quit){
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    quit = 1;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    if(event.button.button == SDL_BUTTON_LEFT)
                        SDL_Log("LEFT!");
                    else if(event.button.button == SDL_BUTTON_RIGHT)
                        SDL_Log("RIGHT!");
                    break;

                default: {}
            }
        }


        

        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
        SDL_RenderClear(renderer); // clear the renderer
        render_window(renderer, &world);
        SDL_RenderPresent(renderer);
        
    }

    
    SDL_Quit();

	return 0;
}
