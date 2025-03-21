#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

extern SDL_Window* window;

extern SDL_Renderer* renderer;

extern SDL_Texture* nen;

extern SDL_Texture* nv_dungyen;

extern SDL_Texture* zombie_thuong;

extern SDL_Texture* zombie_mu;

extern SDL_Texture* zombie_dabong;

extern SDL_Texture* zombie_canhcua;

extern SDL_Texture* zombie_khoaitay;

extern SDL_Texture* zombie_nhayxa;

extern SDL_Texture* thannam;

extern SDL_Texture* thannu;

extern SDL_Texture* nv_chet;

extern SDL_Texture* nv_tancong;

extern SDL_Texture* menu;

extern const int S_W;

extern const int S_H;

extern const int SP;

struct Mouse
{
    int x;
    int y;
};

extern Mouse mouse;

bool initGraphics();

void cleanupGraphics();

extern Uint32 time;

#endif
