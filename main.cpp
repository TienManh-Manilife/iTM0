#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "dichuyen.h"

using namespace std;

const int S_W = 800;
const int S_H = 600;
const int SP = 2;

int main(int argc, char* argv[])
{
    // Khoi tao
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("WINDOW", 100, 200, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    IMG_Init(IMG_INIT_PNG);

    // Camera - anh nen
    SDL_Texture* texture_anhnen = IMG_LoadTexture(renderer,"nen.png");
    int nen_w, nen_h;
    SDL_QueryTexture(texture_anhnen,NULL, NULL, &nen_w, &nen_h);
    SDL_Rect camera = {0, nen_h - 1200, S_W*2, S_H*2};
    SDL_Rect renderQuad_manhinh = { 0, 0, S_W, S_H };
    SDL_RenderCopy(renderer, texture_anhnen, &camera, &renderQuad_manhinh);
    SDL_RenderPresent(renderer);

    // Nhan vat
    const int nhanvat_w = 73, nhanvat_h = 85;
    int frame_now = 0;
    const int totalFrames = 8;
    Uint32 lastFrameTime = 0;
    const int frameDelay = 100;
    SDL_Texture* texture_nhanvat = IMG_LoadTexture(renderer,"nvdungyen.png");

    bool run = 1;
    SDL_Event event;
    while(run==1)
    {
        while(SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                run = 0;
            }
        }

    Uint32 currentTime = SDL_GetTicks();

    if (currentTime > lastFrameTime + frameDelay)
    {
        frame_now = (frame_now + 1) % 6;
        lastFrameTime = currentTime;
    }

    SDL_Rect rectframe_nhanvat = { frame_now * nhanvat_w, 0, nhanvat_w, nhanvat_h };

    SDL_Rect renderQuad_nhanvat = { S_W/2 - nhanvat_w, S_H - nhanvat_h - 150, nhanvat_w*2, nhanvat_h*2 };

    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, texture_anhnen, &camera, &renderQuad_manhinh);
    SDL_RenderPresent(renderer);

    SDL_RenderCopy(renderer, texture_nhanvat, &rectframe_nhanvat, &renderQuad_nhanvat);
    SDL_RenderPresent(renderer);

    SDL_Delay(10);
    }

    SDL_DestroyTexture(texture_nhanvat);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    IMG_Quit();
    return 0;
}
