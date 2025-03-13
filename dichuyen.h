#ifndef DICHUYEN_H_INCLUDED
#define DICHUYEN_H_INCLUDED


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
void hanhdong(SDL_Event &event, int &trangthai);

void chontexture(int &trangthai, SDL_Texture* texture_nvdungyen,
                 SDL_Texture* texture_nvdibo, SDL_Texture* texture_nvbungno,
                 SDL_Texture* texture_nvnhay, SDL_Texture* texture_nvtancong,
                 SDL_Texture* texture_thannam, SDL_Texture* texture_thannu,
                 int &totalFrames, const int &SP, const int frameDelay,
                 Uint32 currentTime, const int nhanvat_h, SDL_Rect &toadonhanvat,
                 SDL_Rect &catnhanvat, Uint32 lastFrameTime, SDL_Renderer* renderer,
                 SDL_Texture* texture_anhnen, SDL_Rect catnen, SDL_Rect toadonen,
                 SDL_Texture* texture_now, int frame_now, const int S_W, const int S_H);

void ham();

#endif
