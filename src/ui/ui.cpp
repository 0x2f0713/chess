#include "include/ui/ui.h"

#include <iostream>

#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "include/constant.h"

bool init(context* ctx) {
  return initWindow(ctx) && initTTF() && initIMGLoader() && loadFont(ctx->font);
}
bool initWindow(context* ctx) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    // TODO: Implement log here
    return false;
  } else {
    // Create window
    // ctx->window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED,
    //                                SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
    //                                SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    int result = SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT,
                                             SDL_WINDOW_SHOWN, &(ctx->window),
                                             &(ctx->renderer));
    if (ctx->window == NULL || ctx->renderer == NULL || result != 0) {
      std::cout << "Failed to create window and renderer: " << SDL_GetError()
                << std::endl;
      return false;
    }
  }
  return true;
}

bool initTTF() {
  if (TTF_Init() < 0) {
    SDL_Log("%s", TTF_GetError());
    return false;
  }
  return true;
}
bool loadFont(TTF_Font*& font) {
  font = TTF_OpenFont("resources/fonts/Montserrat-Regular.ttf", 24);
  if (!font) {
    SDL_LogError(1, "Failed to load font: %s", TTF_GetError());
    return false;
  }
  return true;
}
bool initIMGLoader() {
  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags)) {
    printf("SDL_image could not initialize! SDL_image Error: %s\n",
           IMG_GetError());
    return false;
  }
  return true;
}

void destroyWindow(context* ctx) {
  SDL_DestroyWindow(ctx->window);

  // Quit SDL subsystems
  SDL_Quit();
}

SDL_Surface* loadMedia(std::string mediaPath, SDL_Surface* surface) {
  // The final optimized image
  SDL_Surface* optimizedSurface = NULL;

  // Load image at specified path
  SDL_Surface* loadedSurface = IMG_Load(mediaPath.c_str());
  if (loadedSurface == NULL) {
    printf("Unable to load image %s! SDL_image Error: %s\n", mediaPath.c_str(),
           IMG_GetError());
  } else {
    // Convert surface to screen format
    optimizedSurface = SDL_ConvertSurface(loadedSurface, surface->format, 0);
    if (optimizedSurface == NULL) {
      printf("Unable to optimize image %s! SDL Error: %s\n", mediaPath.c_str(),
             SDL_GetError());
    }

    // Get rid of old loaded surface
    SDL_FreeSurface(loadedSurface);
  }

  return optimizedSurface;
}

void updateSurface(SDL_Surface* src, SDL_Surface* des, int x, int y, int w,
                   int h) {
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;
  offset.w = w;
  offset.h = h;
  // SDL_BlitSurface(src, NULL, des, &offset);
  SDL_BlitScaled(src, NULL, des, &offset);
}

void updateRenderer() {
  // SDL_RenderPresent( renderer );
}