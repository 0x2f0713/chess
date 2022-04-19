#include <string>
#include "SDL2/SDL.h"

#define BACKGROUND_COLOR \
  SDL_Color { 49, 46, 43, 1 }

void initScreen(SDL_Window* window);
SDL_Surface* loadMedia(std::string mediaPath, SDL_Surface* surface);