
#ifndef RENDER_H
#define RENDER_H

#include <stdlib.h>
#include <SDL2/SDL.h>

#include "SDLExtensions/SDL2_gfxPrimitives.h"
#include "win.h"

void render_window(SDL_Renderer *renderer, const world_t *world);

#endif
