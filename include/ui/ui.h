#include "SDL2/SDL.h"

typedef struct context {
    bool quit;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event e;
    context() {
        quit = false;
        window = NULL;
        renderer = NULL;
    }
} context;

bool initWindow(context* ctx);
bool initIMGLoader();
void destroyWindow(context* ctx);