#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "graphics.h"
#include "move.h"
#include "musics.h"

using namespace std;

int main(int argc, char* argv[])
{
    // Khởi tạo:
    if (!initGraphics()) return -1;

    // menu
    menu = IMG_LoadTexture(renderer, "menu.png");
    SDL_RenderCopy (renderer, menu, NULL, NULL);
    SDL_RenderPresent(renderer);
    bool play = 1;

    // nen
    int nen_w, nen_h;
    SDL_QueryTexture(nen, NULL, NULL, &nen_w, &nen_h);
    SDL_Rect rect_nen = {0, 0, nen_w*13/15, nen_h*13/15};

    // Vòng lặp sự kiện:
    bool run = 1;
    SDL_Event event;
    while(run)
    {
        if (play)
        {
            while(SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT) run = 0;
                if (event.type == SDL_MOUSEBUTTONDOWN)
                {
                    mouse.x = event.button.x;
                    mouse.y = event.button.y;
                }
            }
            if (mouse.x >= 135 && mouse.x <= 300 && mouse.y >= 115 && mouse.y <= 222) play = 0;
        }

        else
        {
            while(SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT) run = 0;
            }
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, nen, NULL, &rect_nen);
            SDL_RenderPresent(renderer);
            SDL_Delay(100);
        }
    }

    // Giải phóng bộ nhớ:
    cleanupGraphics();
    return 0;
}
