#ifndef DICHUYEN_H_INCLUDED
#define DICHUYEN_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

extern int trangthai;

extern int frame;

extern int nv_x, nv_y , nv_w, nen_w, nen_h;

extern SDL_Rect rect_nv;

extern SDL_Rect rect_nen;

extern SDL_Rect rect_cat_nv;

void capnhattrangthai (SDL_Event &event, int &trangthai, bool &run);

void hanhdongnhanvat ();

void hanhdongzombie();

void dan();

#endif
