#include "include/screen/lobby.h"
#include "SDL2/SDL_image.h"

void initScreen(SDL_Window* window) {
    SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
    // Fill the surface
    SDL_FillRect(screenSurface, NULL,
                 SDL_MapRGB(screenSurface->format, BACKGROUND_COLOR.r, BACKGROUND_COLOR.g, BACKGROUND_COLOR.b));

    // Update the surface
    SDL_UpdateWindowSurface(window);
    SDL_BlitSurface( loadMedia("resources/images/lobby/standardboard.png", screenSurface), NULL, screenSurface, NULL );
    SDL_UpdateWindowSurface( window );
}
SDL_Surface* loadMedia(std::string mediaPath, SDL_Surface* surface)
{
    //The final optimized image
    SDL_Surface* optimizedSurface = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( mediaPath.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", mediaPath.c_str(), IMG_GetError() );
    }
    else
    {
        //Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface( loadedSurface, surface->format, 0 );
        if( optimizedSurface == NULL )
        {
            printf( "Unable to optimize image %s! SDL Error: %s\n", mediaPath.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return optimizedSurface;
}