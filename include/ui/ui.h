#include "SDL2/SDL.h"

typedef struct context {
    bool quit;
    SDL_Window* window;
    SDL_Renderer* renderer;
    context() {
        quit = false;
        window = NULL;
        renderer = NULL;
    }
} context;

bool initWindow(context* ctx);
void destroyWindow(context* ctx);