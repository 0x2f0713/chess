#include "include/screen/lobby.h"

#include <map>
#include <string>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "include/ui/ui.h"
#include "include/constant.h"

std::map<std::string, std::string> mediaLists{
    {"STANDARD_BOARD", "resources/images/lobby/standardboard.png"},
    {"PLAYHAND_ICON", ""},
    {"QUIT_ICON", ""},
};

void initScreen(SDL_Window* window, SDL_Renderer* renderer,TTF_Font* font) {
  SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
  // Fill the window
  SDL_SetRenderDrawColor(renderer, BACKGROUND_COLOR.r, BACKGROUND_COLOR.g, BACKGROUND_COLOR.b, 255);
  SDL_RenderClear(renderer);

  // Update window
  SDL_RenderPresent(renderer);

  // // Load Standard board
  SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer,loadMedia(mediaLists["STANDARD_BOARD"], screenSurface));
  SDL_Rect image_dest = {250, 100, 500, 500};
  SDL_RenderCopy(renderer, texture, NULL, &image_dest);

  // Test write text
  // SDL_Surface* text = initText(font, "Play Chess", {255,255,255,255});
  // SDL_Texture* text_texture;

  // text_texture = SDL_CreateTextureFromSurface(renderer, text);

  // SDL_Rect dest = {1000, SCREEN_HEIGHT/3 - text->h /2, text->w, text->h};

  // if( SDL_RenderCopy(renderer, text_texture, NULL, &dest) == 0) {
  //   SDL_LogError(1, "Failed to render copy: %s", SDL_GetError());
  // }
  // SDL_RenderPresent( renderer );


  SDL_Surface* textSurface = initText(font, "Play Chess", {255,255,255,255});
  SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
  SDL_Rect imageLocation = {1000, SCREEN_HEIGHT/3 - textSurface->h /2, textSurface->w, textSurface->h};
  showText(renderer, textTexture, NULL, &imageLocation);
}
SDL_Surface* initText(TTF_Font* font, const char * text, SDL_Color color) {
  SDL_Surface* textSurface;

  textSurface = TTF_RenderText_Solid(font, text, color);
  if (!text) {
    SDL_LogError(1, "Failed to render text: %s", TTF_GetError());
  }
  return textSurface;
}
bool showText(SDL_Renderer *renderer,SDL_Texture* textTexture, SDL_Rect* src_rect, SDL_Rect* dst_rect) {
  if( SDL_RenderCopy(renderer, textTexture, NULL, dst_rect) == 0) {
    SDL_LogError(1, "Failed to render copy: %s", SDL_GetError());
    return false;
  }
  SDL_RenderPresent(renderer);
  return true;
}