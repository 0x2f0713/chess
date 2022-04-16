#include "include/ui/ui.h"
int main() {
  context ctx = context();
  bool init = initWindow(&ctx);
  if (init) {
    // Get window surface
    SDL_Surface* screenSurface = SDL_GetWindowSurface(ctx.window);

    // Fill the surface white
    SDL_FillRect(screenSurface, NULL,
                 SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

    // Update the surface
    SDL_UpdateWindowSurface(ctx.window);

    // Wait two seconds
    SDL_Delay(2000);
  }
  destroyWindow(&ctx);

  return 0;
}