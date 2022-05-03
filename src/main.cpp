#include "include/ui/ui.h"
#include "include/screen/lobby.h"

int main() {
  context ctx = context();
  bool initState = init(&ctx);
  if (initState) {
    initScreen(ctx.window, ctx.renderer, ctx.font);
  }
  else {
      ctx.quit = true;
      // Implement logging here
  }
  while (!ctx.quit) {
    while (SDL_PollEvent(&(ctx.e)) != 0) {
      switch (ctx.e.type)
      {
      case SDL_QUIT:
        // User requests quit
        ctx.quit = true;
        break;
      
      default:
        break;
      }
    }

  }

  destroyWindow(&ctx);

  return 0;
}