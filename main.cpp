#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

const int S_W = 1040;
const int S_H = 780;
const int SP = 2;

int main(int argc, char* argv[])
{
    // Khởi tạo:
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("iTM0",120, 20, S_W, S_H, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Texture* nen = IMG_LoadTexture(renderer, "nen.png");
    SDL_Texture* nv_chet = IMG_LoadTexture(renderer, "nvchet.png");
    SDL_Texture* nv_dungyen = IMG_LoadTexture(renderer, "nvdungyen.png");
    SDL_Texture* nv_tancong = IMG_LoadTexture(renderer, "nvtancong.png");
    SDL_Texture* thannam = IMG_LoadTexture(renderer, "thannam.png");
    SDL_Texture* thannu = IMG_LoadTexture(renderer, "thannu.png");
    SDL_Texture* zombie_thuong = IMG_LoadTexture(renderer, "zombie_thuong.png");
    SDL_Texture* zombie_nhayxa = IMG_LoadTexture(renderer, "zombie_nhayxa.png");
    SDL_Texture* zombie_dabong = IMG_LoadTexture(renderer, "zombie_dabong.png");
    SDL_Texture* zombie_mu = IMG_LoadTexture(renderer, "zombie_mu.png");
    SDL_Texture* zombie_khoaitay = IMG_LoadTexture(renderer, "zombie_khoaitay.png");
    SDL_Texture* zombie_canhcua = IMG_LoadTexture(renderer, "zombie_canhcua.png");

    // Camera và ảnh nền:


    // Nhân vật và các hành động:
    int nv_w, nv_h;
    SDL_QueryTexture(nv_dungyen, NULL, NULL, &nv_w, &nv_h);
    SDL_Rect rect_nv = {10,0, nv_w*2, nv_h*2};

    // Zombies thuong
    int zombie_thuong_w, zombie_thuong_h;
    SDL_QueryTexture(zombie_thuong, NULL, NULL, &zombie_thuong_w, &zombie_thuong_h);
    SDL_Rect rect_zombie_thuong = {10,0, zombie_thuong_w*0.8, zombie_thuong_h*0.8};


    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, nen, NULL, NULL);
    SDL_RenderCopy(renderer, zombie_thuong, NULL, &rect_zombie_thuong);
    SDL_RenderCopy(renderer, nv_dungyen, NULL, &rect_nv);
    SDL_RenderPresent(renderer);

    // Vòng lặp sự kiện:
    bool run = 1;
    bool menu = 1;
    SDL_Event event;
    while(run)
    {
        while (menu)
        {

        }

        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) run = 0;
        }
    }

    // Giải phóng bộ nhớ:
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
