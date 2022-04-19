#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
typedef struct context {
    bool quit;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event e;
    TTF_Font* font;
    context() {
        quit = false;
        window = NULL;
        renderer = NULL;
        font = NULL;
    }
} context;

/* Initializer */
bool init(context* ctx);
bool initWindow(context* ctx);
bool initTTF();
bool loadFont(TTF_Font* &font);
bool initIMGLoader();

/* Destroyer */
void destroyWindow(context* ctx);

/* Utilities */
SDL_Surface* loadMedia(std::string mediaPath, SDL_Surface* surface);
void updateSurface(SDL_Surface* src, SDL_Surface* des, int x, int y, int w, int h);