#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#define BACKGROUND_COLOR \
  SDL_Color { 49, 46, 43, 1 }

void initScreen(SDL_Window* window, TTF_Font* font);
SDL_Surface* initText(TTF_Font* font);