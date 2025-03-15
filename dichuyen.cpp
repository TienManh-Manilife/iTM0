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
            case SDLK_w:
                trangthai = 3;
                break;
            case SDLK_d:
                trangthai = 4;
                break;
            case SDLK_SPACE:
                trangthai = 5;
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

void chontexture(int &trangthai, SDL_Texture* texture_nvdungyen,
                 SDL_Texture* texture_nvdibo, SDL_Texture* texture_nvbungno,
                 SDL_Texture* texture_nvnhay, SDL_Texture* texture_nvtancong,
                 SDL_Texture* texture_thannam, SDL_Texture* texture_thannu,
                 int &totalFrames, const int &SP, const int frameDelay,
                 Uint32 currentTime, const int nhanvat_h, SDL_Rect &toadonhanvat,
                 SDL_Rect &catnhanvat, Uint32 lastFrameTime, SDL_Renderer* renderer,
                 SDL_Texture* texture_anhnen, SDL_Rect catnen, SDL_Rect toadonen,
                 SDL_Texture* texture_now, int frame_now, const int S_W, const int S_H)
{
    if (trangthai == 1)
    {
        currentTime = SDL_GetTicks();
        totalFrames = 6;
        if (currentTime > lastFrameTime + frameDelay)
        {
            frame_now = (frame_now + 1) % totalFrames;
            lastFrameTime = currentTime;
        }
        // Nhan vat dung yen
        catnhanvat = { frame_now * 73, 0, 73, nhanvat_h};
        toadonhanvat = { S_W/2 - 73, S_H - nhanvat_h - 145, 73*2, nhanvat_h*2 };
        // Khung hinh dung yen
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture_anhnen, &catnen, &toadonen);
        SDL_RenderCopy(renderer, texture_nvdungyen, &catnhanvat, &toadonhanvat);
    }

    else if(trangthai == 2)
    {
        totalFrames = 8;
        // Nhan vat di chuyen sang trai
        // Khung hinh di chuyen sang trai
    }

    else if (trangthai == 3)
    {
        totalFrames = 8;
        //Nhan vat nhay
        // Khung hinh di chuyen len tren
    }

    else if (trangthai == 4)
    {
        totalFrames = 8;
        // Nhan vat di chuyen sang phai
        // Khung hinh di chuyen len tren
    }

    else if (trangthai == 5)
    {
        totalFrames = 3;
        // Nhan vat bung no
        // Render anh bung no
    }

    else if (trangthai == 6)
    {
        //Nhan vat tan cong
        // Khung hinh dung yen
    }

    else if (trangthai == 7)
    {
        //Nhan vat chet
        //Cap nhat khung hinh Menu
    }
}
