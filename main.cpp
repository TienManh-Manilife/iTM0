//24020220
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <vector>
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
    play = 1;

    // Vòng lặp sự kiện:
    bool run = 1;
    SDL_Event event;
    while(run)
    {
        if (play == 1)
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
            SDL_RenderCopy(renderer, menu, NULL, NULL);
            SDL_RenderPresent(renderer);
            if (mouse.x >= 135 && mouse.x <= 300 && mouse.y >= 115 && mouse.y <= 222) play = 0;
        }

        //Bat dau choi
        else if (play == 0)
        {

            while(SDL_PollEvent(&event))
            {
                capnhattrangthai (event, trangthai, run);
            }

            hanhdongnhanvat();
            hanhdongzombie();
            SDL_RenderPresent(renderer);
            SDL_Delay(20);
        }

        //Ketthuc
        else if (play == 2)
        {
            while(SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT) run = 0;
                if (event.type == SDL_MOUSEBUTTONDOWN)
                {
                    play = 0;
                }
            }
            //______________________________________________________________________________
        }
    }

    // Giải phóng bộ nhớ:
    cleanupGraphics();
    return 0;
}
