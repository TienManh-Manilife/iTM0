#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "player.h"
#include "dichuyen.h"

using namespace std;

const int S_W = 800;
const int S_H = 600;
const int

int main(int argc, char* argv[])
{
    bool up = false, down = false, left = false, right = false;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("WINDOW", 100, 200, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    IMG_Init(IMG_INIT_PNG);
    SDL_Texture* texture = IMG_LoadTexture(renderer,"image.png");
    int w, h;
    SDL_QueryTexture(texture,NULL,NULL,&w, &h);
    SDL_Rect rect = {400,300,w*0.1,h*0.1};
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
            DiChuyenMuot(event ,up, down, left, right);
        }

    TranhThoatManHinh(rect, SP, up, down, left, right, S_W, S_H);

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,texture,NULL,&rect);
    SDL_RenderPresent(renderer);
    SDL_Delay(10);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    IMG_Quit();
    return 0;
}
