//24020220
#ifndef DICHUYEN_H_INCLUDED
#define DICHUYEN_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

extern int trangthai, trangthai_zom;

extern int frame;

extern int nv_x, nv_y , nv_w, nen_w, nen_h, dan_x, dan_y;

extern SDL_Rect rect_nv;

extern SDL_Rect rect_nen;

extern SDL_Rect rect_anh, rect_cat_thuong, rect_thuong;

extern Uint32 zombie_time;

void capnhattrangthai (SDL_Event &event, int &trangthai, bool &run);

void hanhdongnhanvat ();

void hanhdongzombie();

#endif
