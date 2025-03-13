#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "dichuyen.h"
#include <string>

using namespace std;

const int S_W = 800;
const int S_H = 600;
const int SP = 2;

int main(int argc, char* argv[])
{
    // Khởi tạo:
    SDL_Init(SDL_INIT_VIDEO); //Checked
    SDL_Window* window = SDL_CreateWindow("WINDOW", 100, 200, 800, 600, SDL_WINDOW_SHOWN); //Checked
    SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED); //Checked
    IMG_Init(IMG_INIT_PNG); //Checked
    int nen_w, nen_h; //Checked

    // Camera và ảnh nền:
    SDL_Texture* texture_anhnen = IMG_LoadTexture(renderer,"nen.png");
    SDL_QueryTexture(texture_anhnen,NULL, NULL, &nen_w, &nen_h);
    int x=0, y=nen_h - S_H*2
    SDL_Rect catnen = {y, x, S_W*2, S_H*2};
    SDL_Rect toadonen = { 0, 0, S_W, S_H };
    SDL_RenderCopy(renderer, texture_anhnen, &catnen, &toadonen);
    SDL_RenderPresent(renderer);
    int trangthai = 1;

    // Nhân vật và các hành động:
    const int nhanvat_w = 73, nhanvat_h = 85;
    int frame_now = 0;
    int totalFrames = 6;
    Uint32 lastFrameTime = 0;
    const int frameDelay = 100;
    SDL_Texture* texture_nvdungyen = IMG_LoadTexture(renderer, "nvdungyen.png");
    SDL_Texture* texture_nvdibo = IMG_LoadTexture(renderer, "nvdibo.png");
    SDL_Texture* texture_nvchet = IMG_LoadTexture(renderer, "nvchet.png");
    SDL_Texture* texture_nvbungno = IMG_LoadTexture(renderer, "nvbungno.png");
    SDL_Texture* texture_nvnhay = IMG_LoadTexture(renderer, "nvnhay.png");
    SDL_Texture* texture_nvtancong = IMG_LoadTexture(renderer, "nvtancong.png");
    SDL_Texture* texture_thannam = IMG_LoadTexture(renderer, "thannam.png");
    SDL_Texture* texture_thannu = IMG_LoadTexture(renderer, "thannu.png");

    //Địch:
    //Yêu quái:


    //Sói:


    //Boss:

    // Vòng lặp sự kiện:
    bool run = 1;
    SDL_Event event;
    while(run==1)
    {
        while(SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT) run = 0;
            hanhdong(event,trangthai);
        }


    Uint32 currentTime = SDL_GetTicks();

    if (currentTime > lastFrameTime + frameDelay)
    {
        frame_now = (frame_now + 1) % totalFrames;
        lastFrameTime = currentTime;
    }

    SDL_Texture* texture_now;

    SDL_Rect rectframe_nhanvat = { frame_now * nhanvat_w, 0, nhanvat_w, nhanvat_h };
    SDL_Rect renderQuad_nhanvat = { S_W/2 - nhanvat_w, S_H - nhanvat_h - 145, nhanvat_w*2, nhanvat_h*2 };
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture_anhnen, &camera, &renderQuad_manhinh);
    SDL_RenderCopy(renderer, current_texture, &rectframe_nhanvat, &renderQuad_nhanvat);
    SDL_RenderPresent(renderer);
    SDL_Delay(100);
    }

    //Giải phóng bộ nhớ:
    SDL_DestroyTexture(texture_nvdungyen);
    SDL_DestroyTexture(texture_nvdibo);
    SDL_DestroyTexture(texture_nvchet);
    SDL_DestroyTexture(texture_nvtancong);
    SDL_DestroyTexture(texture_nvnhay);
    SDL_DestroyTexture(texture_nvbungno);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    IMG_Quit();

    return 0;
}
