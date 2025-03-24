//24020220
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

extern SDL_Window* window;

extern SDL_Renderer* renderer;

extern SDL_Texture* nen;

extern SDL_Texture* nv_dungyen;

extern SDL_Texture* zombie_thuong;

extern SDL_Texture* zombie_mu;

extern SDL_Texture* zombie_dabong;

extern SDL_Texture* zombie_canhcua;

extern SDL_Texture* zombie_khoaitay;

extern Mix_Music* nhacnen;

extern Mix_Chunk* no1;

extern bool phat_no1;

extern Mix_Chunk* no2;

extern Mix_Chunk* no3;

extern Mix_Chunk* no4;

extern Mix_Chunk* tancong1;

extern int thutuno;

extern SDL_Texture* zombie_nhayxa;

extern SDL_Texture* danbungno;

extern SDL_Texture* danthuong;

extern SDL_Texture* anhbungno;

extern SDL_Texture* nv_chet;

extern SDL_Texture* nv_tancong;

extern SDL_Texture* nv_bungno;

extern SDL_Texture* menu;

extern bool thoigian1, thoigian2, phat_tancong1;

extern const int S_W;

extern const int S_H;

extern const int SP;

struct Mouse
{
    int x;
    int y;
};

extern Mouse mouse;

extern bool bool_time1;

extern int play;

bool initGraphics();

void cleanupGraphics();

extern Uint32 time, time1;

extern SDL_Rect rect_dan;

#endif
