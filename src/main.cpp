#include "include/ui/ui.h"
#include "include/screen/lobby.h"

#include <iostream>
int main() {
  context ctx = context();
  bool init = initWindow(&ctx);
  if (init) {
    // Get window surface
    

  }
  else {
      ctx.quit = true;
      // Implement logging here
  }
  initScreen(ctx.window);
  while (!ctx.quit) {
    while (SDL_PollEvent(&(ctx.e)) != 0) {
      // User requests quit
      if (ctx.e.type == SDL_QUIT) {
        ctx.quit = true;
      }
    }

  }

  destroyWindow(&ctx);

  return 0;
}