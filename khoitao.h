#ifndef DICH_H_INCLUDED
#define DICH_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// Biến toàn cục lưu trữ window và renderer
extern SDL_Window* window;
extern SDL_Renderer* renderer;

// Hàm khởi tạo và giải phóng SDL
bool initSDL();
void closeSDL();


#endif // DICH_H_INCLUDED
