#include "include/ui/ui.h"
#include "include/screen/lobby.h"

int main() {
  context ctx = context();
  bool initState = init(&ctx);
  if (initState) {
    initScreen(ctx.window, ctx.font);
  }
  else {
      ctx.quit = true;
      // Implement logging here
  }
  initScreen(ctx.window, ctx.font);
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