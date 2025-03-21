#include "graphics.h"
#include <iostream>

using namespace std;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Texture* nen = nullptr;
    SDL_Texture* nv_chet = nullptr;
    SDL_Texture* nv_dungyen = nullptr;
    SDL_Texture* nv_tancong = nullptr;
    SDL_Texture* thannam = nullptr;
    SDL_Texture* thannu = nullptr;
    SDL_Texture* zombie_thuong = nullptr;
    SDL_Texture* zombie_nhayxa = nullptr;
    SDL_Texture* zombie_dabong = nullptr;
    SDL_Texture* zombie_mu = nullptr;
    SDL_Texture* zombie_khoaitay = nullptr;
    SDL_Texture* zombie_canhcua = nullptr;
    SDL_Texture* menu = nullptr;
    Mouse mouse = {0,0};
    const int S_W = 1040;
    const int S_H = 780;
    const int SP = 3;
    Uint32 time = 0;

bool initGraphics()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Khong khoi tao SDL" << endl;
        return false;
    }

    window = SDL_CreateWindow("iTM0", 120, 20, S_W, S_H, SDL_WINDOW_SHOWN);
    if (!window)
    {
        cout << "Khong tao cua so" << endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        cout << "Khong tao renderer" << endl;
        return false;
    }

    nen = IMG_LoadTexture(renderer, "nen.png");
    nv_chet = IMG_LoadTexture(renderer, "nvchet.png");
    nv_dungyen = IMG_LoadTexture(renderer, "nvdungyen.png");
    nv_tancong = IMG_LoadTexture(renderer, "nvtancong.png");
    thannam = IMG_LoadTexture(renderer, "thannam.png");
    thannu = IMG_LoadTexture(renderer, "thannu.png");
    zombie_thuong = IMG_LoadTexture(renderer, "zombie_thuong.png");
    zombie_nhayxa = IMG_LoadTexture(renderer, "zombie_nhayxa.png");
    zombie_dabong = IMG_LoadTexture(renderer, "zombie_dabong.png");
    zombie_mu = IMG_LoadTexture(renderer, "zombie_mu.png");
    zombie_khoaitay = IMG_LoadTexture(renderer, "zombie_khoaitay.png");
    zombie_canhcua = IMG_LoadTexture(renderer, "zombie_canhcua.png");

    return true;
}

void cleanupGraphics()
{
    SDL_DestroyTexture(zombie_canhcua);
    SDL_DestroyTexture(zombie_khoaitay);
    SDL_DestroyTexture(zombie_mu );
    SDL_DestroyTexture(zombie_nhayxa);
    SDL_DestroyTexture(zombie_dabong);
    SDL_DestroyTexture(zombie_thuong);
    SDL_DestroyTexture(thannu);
    SDL_DestroyTexture(thannam);
    SDL_DestroyTexture(nv_tancong);
    SDL_DestroyTexture(nv_dungyen);
    SDL_DestroyTexture(nv_chet);
    SDL_DestroyTexture(nen);
    SDL_DestroyTexture(menu);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
