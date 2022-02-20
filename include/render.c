
#include "render.h"

const SDL_Colour SIDE_COLOUR = {.r = 255, .g = 25, .b = 50};
const SDL_Colour GRID_COLOUR = {.r = 255, .g = 255, .b = 255};
const SDL_Colour CELL_DEAD_COLOUR = {.r = 0, .g = 255, .b = 0};
const SDL_Colour CELL_ALIVE_COLOUR = {.r = 100, .g = 100, .b = 100};
const SDL_Colour RESET_STATE_COLOUR = {.r = 200, .g = 200, .b = 200};



void render_alive(SDL_Renderer *renderer, 
				  const world_t *world,
				  const SDL_Colour *colour,
				  int i, int j){

}



void render_dead(SDL_Renderer *renderer, 
				 const world_t *world,
				 const SDL_Colour *colour,
				 int i, int j){

}



void render_cells(SDL_Renderer *renderer, 
				  const world_t *world,
				  const SDL_Colour *alive_colour, const SDL_Colour *dead_colour){

	for(int i = 0; i < CELL_ROWS; i++){
		for(int j = 0; j < CELL_COLS; j++){

			switch(world->grid[i][j]){
				case ALIVE:
					render_alive(renderer, world, alive_colour, i, j);
					break;

				case DEAD:
					render_dead(renderer, world, dead_colour, i, j);
					break;

				default: {}
			}

		}
	}
}



void render_side_count(SDL_Renderer *renderer, 
					   const world_t *world,
					   const SDL_Colour *colour){

	unsigned char thickness = 8;

	thickLineRGBA(renderer,
				  WORLD_WIDTH + thickness/2, 0,
				  WORLD_WIDTH + thickness/2, WORLD_HEIGHT,
				  thickness,
				  colour->r,
				  colour->g,
				  colour->b,
				  255);
}



void render_grid(SDL_Renderer *renderer, 
				 const SDL_Colour *colour){
	
	SDL_SetRenderDrawColor(renderer, colour->r, colour->g, colour->b, 255);

	for(int i = 0; i <= CELL_ROWS + 1; i++){
		SDL_RenderDrawLine(renderer,
						   0, i * CELL_HEIGHT,
					   	   WORLD_WIDTH - 1, i * CELL_HEIGHT);
	}

	for(int i = 0; i <= CELL_COLS; i++){
		SDL_RenderDrawLine(renderer,
						   i * CELL_WIDTH, 0,
					   	   i * CELL_WIDTH, WORLD_HEIGHT);
	}
}



void render_running_state(SDL_Renderer *renderer, const world_t *world){
	render_side_count(renderer, world, &SIDE_COLOUR);
	render_grid(renderer, &GRID_COLOUR);
	render_cells(renderer, world, &CELL_ALIVE_COLOUR, &CELL_DEAD_COLOUR);
}



void render_reset_state(SDL_Renderer *renderer, const world_t *world, const SDL_Colour *colour){
	render_side_count(renderer, world, colour);
	render_grid(renderer, colour);
	render_cells(renderer, world, colour, colour);
}



void render_window(SDL_Renderer *renderer, const world_t *world){

	switch(world->state){

		case RUNNING_STATE:
			render_running_state(renderer, world);
			break;

		case RESET_STATE:
			render_reset_state(renderer, world, &RESET_STATE_COLOUR);
			break;

		default: {}
	}

}

