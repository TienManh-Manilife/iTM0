//24020220
#include "graphics.h"
#include <iostream>
#include <SDL2/SDL_mixer.h>
#include "move.h"

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
    SDL_Texture* nv_bungno = nullptr;
    SDL_Texture* menu = nullptr;
    SDL_Texture* danbungno = nullptr;
    SDL_Texture* danthuong = nullptr;
    SDL_Texture* anhbungno = nullptr;
    Mix_Music* nhacnen = nullptr;
    Mix_Chunk* no1 = nullptr;
    Mix_Chunk* no2 = nullptr;
    Mix_Chunk* no3 = nullptr;
    Mix_Chunk* no4 = nullptr;
    int thutuno = 0;
    Mouse mouse = {0,0};
    const int S_W = 1040;
    const int S_H = 780;
    const int SP = 3;
    Uint32 time = 0, time1 = 0;
    bool bool_time1 = 1;
    int play = 1;
    bool phat_no1 = 1;
    bool thoigian = 1;

bool initGraphics()
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        cout << "Khong khoi tao SDL" << endl;
        return false;
    }

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    Mix_Music* nhacnen = Mix_LoadMUS("nhactancong.mp3");
    if (nhacnen == nullptr)
    {
        cout << "Loi tai nhac: " << Mix_GetError() << endl;
        return 0;
    }
    else Mix_PlayMusic(nhacnen, -1);

    no1 = Mix_LoadWAV ("no1.wav");
    no2 = Mix_LoadWAV ("no2.wav");
    no3 = Mix_LoadWAV ("no3.wav");
    no4 = Mix_LoadWAV ("no4.wav");

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
    nv_bungno = IMG_LoadTexture(renderer, "nvbungno.png");
    thannu = IMG_LoadTexture(renderer, "thannu.png");
    zombie_thuong = IMG_LoadTexture(renderer, "zombie_thuong.png");
    zombie_nhayxa = IMG_LoadTexture(renderer, "zombie_nhayxa.png");
    zombie_dabong = IMG_LoadTexture(renderer, "zombie_dabong.png");
    zombie_mu = IMG_LoadTexture(renderer, "zombie_mu.png");
    zombie_khoaitay = IMG_LoadTexture(renderer, "zombie_khoaitay.png");
    zombie_canhcua = IMG_LoadTexture(renderer, "zombie_canhcua.png");
    SDL_Texture* danbungno = IMG_LoadTexture(renderer, "danbungno.png");;
    SDL_Texture* danthuong = IMG_LoadTexture(renderer, "danthuong.png");;
    SDL_Texture* anhbungno = IMG_LoadTexture(renderer, "anhbungno.png");;

    SDL_QueryTexture(nen, NULL, NULL, &nen_w, &nen_h);

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
    SDL_DestroyTexture(nv_tancong);
    SDL_DestroyTexture(nv_dungyen);
    SDL_DestroyTexture(nv_chet);
    SDL_DestroyTexture(nen);
    SDL_DestroyTexture(menu);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(danbungno);
    SDL_DestroyTexture(danthuong);
    SDL_DestroyTexture(anhbungno);
    SDL_DestroyTexture(nv_tancong);
    Mix_FreeMusic(nhacnen);
    Mix_CloseAudio();
    SDL_Quit();
}
//24020220
