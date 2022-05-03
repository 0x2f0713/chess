#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#define BACKGROUND_COLOR \
  SDL_Color { 49, 46, 43, 1 }

void initScreen(SDL_Window* window, SDL_Renderer* renderer,TTF_Font* font);
SDL_Surface* initText(TTF_Font* font, const char * text, SDL_Color color);
bool showText(SDL_Renderer *renderer,SDL_Texture* textTexture, SDL_Rect* src_rect, SDL_Rect* dst_rect);