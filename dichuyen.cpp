#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "dichuyen.h"

using namespace std;

void hanhdong(SDL_Event &event, int &trangthai)
{
    if (event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
            case SDLK_a:
                trangthai = 2;
                break;
            case SDLK_d:
                trangthai = 3;
                break;
            case SDLK_w:
                trangthai = 4;
                break;
            case SDLK_s:
                trangthai = 5;
                break;
            case SDLK_SPACE:
                trangthai = 6;
                break;
        }
    }

    else if (event.type == SDL_KEYUP) trangthai = 1;
    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        if (event.button.button == SDL_BUTTON_LEFT)
        {
            trangthai = 7;
        }
    }
}

void chontexture(int &trangthai,
                 SDL_Texture* texture_nvdungyen,
                 SDL_Texture* texture_nvdibo,
                 SDL_Texture* texture_nvbungno,
                 SDL_Texture* texture_nvnhay,
                 SDL_Texture* texture_nvtancong,
                 SDL_Texture* texture_thannam,
                 SDL_Texture* texture_thannu)
{
}
