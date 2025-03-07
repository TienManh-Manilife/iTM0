#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "dichuyen.h"

using namespace std;

void DiChuyenMuot(SDL_Event &event, bool &up, bool &down, bool &left, bool &right)
{
    if (event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
            case SDLK_UP:
            case SDLK_w: up = true; break;

            case SDLK_DOWN:
            case SDLK_s: down = true; break;

            case SDLK_LEFT:
            case SDLK_a: left = true; break;

            case SDLK_RIGHT:
            case SDLK_d: right = true; break;
        }
    }
    if (event.type == SDL_KEYUP)
    {
        switch (event.key.keysym.sym)
        {
            case SDLK_UP:
            case SDLK_w: up = false; break;

            case SDLK_DOWN:
            case SDLK_s: down = false; break;

            case SDLK_LEFT:
            case SDLK_a: left = false; break;

            case SDLK_RIGHT:
            case SDLK_d: right = false; break;
        }
    }
}

void TranhThoatManHinh(SDL_Rect &rect,int SP, bool up, bool down, bool left, bool right, int S_W, int S_H)
{
    if (up) rect.y -= SP;
    if (down) rect.y += SP;
    if (left) rect.x -= SP;
    if (right) rect.x += SP;

    if (rect.x < 0) rect.x = 0;
    if (rect.y < 0) rect.y = 0;
    if (rect.x > S_W - rect.w) rect.x = S_W - rect.w;
    if (rect.y > S_H - rect.h) rect.y = S_H - rect.h;
}
