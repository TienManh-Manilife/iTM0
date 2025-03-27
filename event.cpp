#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "graphics.h"
#include "move.h"
#include "event.h"

using namespace std;

void chay_menu()
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

void batdauchoi()
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

void chay_lose()
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
            SDL_Delay(5000);
}

void chay_huongdan()
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
    SDL_RenderCopy(renderer, huongdan, NULL, NULL);
    SDL_RenderPresent(renderer);
    if (mouse.x != 0) play = 5;
}

void chay_win()
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
    SDL_Delay(5000);
}

void chondokho()
{
    mouse.x = 500;
    mouse.y = 500;
    while(SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT) run = 0;
        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            mouse.x = event.button.x;
            mouse.y = event.button.y;
        }
    }
    SDL_RenderCopy(renderer, dokho, NULL, NULL);
    SDL_RenderPresent(renderer);
    if (mouse.x <= 400 && mouse.y <= 225)
    {
        MAX = 150;
        play = 0;
    }
    else if (mouse.x >= 640 && mouse.y <= 225)
    {
        MAX = 300;
        play = 0;
    }
    else if (mouse.x <= 400 && mouse.y >= 555)
    {
        MAX = 500;
        play = 0;
    }
    else if (mouse.x >= 640 && mouse.y >= 555)
    {
        MAX = 1000;
        play = 0;
    }
}

void game()
{
    //khoi tao
    initGraphics();

    // menu
    menu = IMG_LoadTexture(renderer, "menu.png");
    SDL_RenderCopy (renderer, menu, NULL, NULL);
    SDL_RenderPresent(renderer);
    play = 1;

    // Vòng lặp sự kiện:
    while(run)
    {
        //Menu
        if (play == 1)
        {
            chay_menu();
        }
        //Bat dau choi
        else if (play == 0)
        {
            batdauchoi();
        }

        //Lose
        else if (play == 2)
        {
            chay_lose();
        }

        // Huong dan
        else if (play == 3)
        {
            chay_huongdan();
        }

        //win
        else if (play == 4)
        {
            chay_win();
        }

        //chon do kho
        else if (play == 5)
        {
            chondokho();
        }

        if (KILL >= MAX) play = 4;
        else isPlay = 1;
    }

    // Giải phóng bộ nhớ:
    cleanupGraphics();

    cout << "Ban da giet duoc: " << KILL;
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
}
