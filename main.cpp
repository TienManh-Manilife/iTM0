//24020220
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "graphics.h"
#include "move.h"

using namespace std;

int main(int argc, char* argv[])
{
    srand(time(0));

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
    int spawnTimer = 0;
    while(run)
    {
        //Menu
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
            if (mouse.x >= 135 && mouse.x <= 300 && mouse.y >= 115 && mouse.y <= 222) play = 3;
        }

        //Bat dau choi
        else if (play == 0)
        {

            while(SDL_PollEvent(&event))
            {
                capnhattrangthai (event, trangthai, run);
            }
            hanhdongnhanvat();
            spawnTimer++;
        if (spawnTimer > 100)
        {
            spawnZombie();
            spawnTimer = 0;
        }
        updateZombies();
        renderZombies();

        if (dungno >= 15)
        {
            SDL_Rect bungno = {0,0, 100, 100};
            SDL_RenderCopy(renderer, thannu, NULL, &bungno);
        }

        if (nangcap >= 50)
        {
            SDL_Rect dungnangcap = {0,680, 100, 100};
            SDL_RenderCopy(renderer, danbungno, NULL, &dungnangcap);
        }

        SDL_RenderPresent(renderer);

        if (SDL_GetTicks() - time2 >= 100)
        {
            damage ++;
            time2 = SDL_GetTicks();
            if (ZOMBIE_SPEED_ADD <= 3000)ZOMBIE_SPEED_ADD++;
            hp++;
        }
        SDL_Delay(20);
        }

        //Lose
        else if (play == 2)
        {
            mouse.x = 0;
            while(SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT) run = 0;
                if (event.type == SDL_MOUSEBUTTONDOWN)
                {
                    mouse.x = event.button.x;
                    mouse.y = event.button.y;
                }
            }
            SDL_RenderCopy(renderer, lose, NULL, NULL);
            SDL_RenderPresent(renderer);
            if (mouse.x !=0 && mouse.y !=0) run = 0;

        }

        // Huong dan
        else if (play == 3)
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
            SDL_RenderCopy(renderer, huongdan, NULL, NULL);
            SDL_RenderPresent(renderer);
            if (mouse.x != 0) play = 0;
        }

        //win
        else if (play == 4)
        {
            mouse.x = 0;
            mouse.y = 0;
            while(SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT) run = 0;
                if (event.type == SDL_MOUSEBUTTONDOWN)
                {
                    mouse.x = event.button.x;
                    mouse.y = event.button.y;
                }
            }
            SDL_RenderCopy(renderer, win, NULL, NULL);
            SDL_RenderPresent(renderer);
            if (mouse.x !=0 && mouse.y !=0) run = 0;
        }

        if (KILL >= 1000) play = 4;
    }

    // Giải phóng bộ nhớ:
    cleanupGraphics();

    cout << "Ban da giet duoc: " << KILL;
    return 0;
}
