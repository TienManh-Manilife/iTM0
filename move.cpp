#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "graphics.h"
#include "move.h"
#include "musics.h"

int trangthai = 0;

int frame = 0;

int nv_x = 10, nv_y = 0, nv_w = 0;

SDL_Rect rect_nv = {nv_x, nv_y, nv_w, 85};

SDL_Rect rect_cat_nv = {0, 0, nv_w, 85};

int nen_w, nen_h;

SDL_Rect rect_nen = {0, 0, nen_w*13/15, nen_h*13/15};

void capnhattrangthai (SDL_Event &event, int &trangthai, bool &run)
{
    switch (event.type)
    {
    case SDL_QUIT:
        run = 0;
        break;
    case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_w && event.key.repeat == 0)
        {
            trangthai = 1; // Di chuyen len
        }
        else if (event.key.keysym.sym == SDLK_s && event.key.repeat == 0)
        {
            trangthai = 2; // Di chuyen xuong
        }
        else if (event.key.keysym.sym == SDLK_SPACE && event.key.repeat == 0)
        {
            trangthai = 3; // Bung no
        }
        else trangthai = 1;
        break;
    case SDL_MOUSEBUTTONDOWN:
        if (event.button.button == SDL_BUTTON_LEFT)
        {
            trangthai = 4;
            break;
        }
        else trangthai = 0;
    }
}

void hanhdongnhanvat ()
{
    switch (trangthai)
    {
    case 0:
        if (SDL_GetTicks() - time >= 100)
        {
            frame = (frame+1)%6;
            time = SDL_GetTicks();
        }
        rect_cat_nv = {frame*73, 0, 73, 85};
        nv_w = 73;
        rect_nv = {nv_x, nv_y, nv_w*2, 145};
        SDL_RenderClear(renderer);
        rect_nen = {0, 0, nen_w*13/15, nen_h*13/15};
        SDL_RenderCopy(renderer, nen, NULL, &rect_nen);
        SDL_RenderCopy(renderer, nv_dungyen, &rect_cat_nv, &rect_nv);
        break;
    case 1:
        if (nv_y >= 50)nv_y -= 150;
        trangthai = 0;
        break;
    case 2:
        if (nv_y < 600)nv_y += 150;
        trangthai = 0;
        break;
    case 3:
        break;
    case 4:

    }
}

void hanhdongzombie()
{

}

