#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "dichuyen.h"

using namespace std;

void nvdichuyenphai(SDL_Event &event, bool &isMoving)
{
    if (event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
            case SDLK_a:
            case SDLK_d:
                isMoving = true;
                break;
            case SDLK_w:
            case SDLK_s:
                isMoving = false;
                break;
        }
    }
    else if (event.type == SDL_KEYUP)
    {
        isMoving = false;
    }
}
