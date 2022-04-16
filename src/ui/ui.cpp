#include "include/ui/ui.h"
#include "include/constant.h"

bool initWindow(context* ctx) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    // TODO: Implement log here
    return false;
  } else {
    // Create window
    ctx->window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
                                   SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                   SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (ctx->window == NULL) {
      return false;
    }
  }
  return true;
}

void destroyWindow(context* ctx) {
  SDL_DestroyWindow(ctx->window);

  // Quit SDL subsystems
  SDL_Quit();
}