#include "include/screen/lobby.h"

#include <map>
#include <string>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "include/ui/ui.h"

std::map<std::string, std::string> mediaLists{
    {"STANDARD_BOARD", "resources/images/lobby/standardboard.png"},
    {"PLAYHAND_ICON", ""},
    {"QUIT_ICON", ""},
};

void initScreen(SDL_Window* window, TTF_Font* font) {
  SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
  // Fill the surface
  SDL_FillRect(screenSurface, NULL,
               SDL_MapRGB(screenSurface->format, BACKGROUND_COLOR.r,
                          BACKGROUND_COLOR.g, BACKGROUND_COLOR.b));

  // Load Standard board
  updateSurface(loadMedia(mediaLists["STANDARD_BOARD"], screenSurface),
                screenSurface, 250, 100, 500, 500);
  updateSurface(initText(font),
                screenSurface, 500, 500, 100, 24);
  SDL_UpdateWindowSurface(window);
}
SDL_Surface* initText(TTF_Font* font) {
  SDL_Surface* text;
  // Set color to black
  SDL_Color color = {255,255,255};

  text = TTF_RenderText_Solid(font, "Hello World!", color);
  if (!text) {
    SDL_LogError(1, "Failed to render text: %s",TTF_GetError());
  }
  return text;
}