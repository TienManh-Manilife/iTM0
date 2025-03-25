//24020220
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include "graphics.h"
#include "move.h"

using namespace std;

int trangthai = 0, trangthai_zom = 0;

int frame = 0;

int dan_x = 0, dan_y = 0, zb_w, zb_h;

int nv_x = 30, nv_y = 0, nv_w = 0;

SDL_Rect rect_nv = {nv_x, nv_y, nv_w, 85};

SDL_Rect rect_cat_nv = {0, 0, nv_w, 85};

SDL_Rect rect_anh = {nv_x, nv_y, nv_w, 85};

int nen_w, nen_h, zombie_frame = 0;

SDL_Rect rect_nen = {0, 0, nen_w*13/15, nen_h*13/15};

Uint32 time_zb = 0;

int frame_zb = 0;

vector<Zombie*> zombies;

void capnhattrangthai (SDL_Event &event, int &trangthai, bool &run)
{
    switch (event.type)
    {
    case SDL_QUIT:
        run = 0;
        break;
    case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_w)
        {
            trangthai = 1; // Di chuyen len
        }
        else if (event.key.keysym.sym == SDLK_s)
        {
            trangthai = 2; // Di chuyen xuong
        }
        else if (event.key.keysym.sym == SDLK_SPACE)
        {
            trangthai = 3; // Bung no
        }
        else trangthai = 0;
        break;
    case SDL_MOUSEBUTTONDOWN:
        if (event.button.button == SDL_BUTTON_LEFT)
        {
            trangthai = 4;
            break;
        }
        else trangthai = 0;
    }
}

void hanhdongnhanvat ()
{
    switch (trangthai)
    {
        //Dung yen
    case 0:
        if (SDL_GetTicks() - time0 >= 100)
        {
            frame = (frame+1)%6;
            time0 = SDL_GetTicks();
        }
        rect_cat_nv = {frame*73, 0, 73, 85};
        nv_w = 73;
        rect_nv = {nv_x, nv_y, nv_w*2, 145};
        SDL_RenderClear(renderer);
        rect_nen = {0, 0, nen_w*13/15, nen_h*13/15};
        SDL_RenderCopy(renderer, nen, NULL, &rect_nen);
        SDL_RenderCopy(renderer, nv_dungyen, &rect_cat_nv, &rect_nv);
        break;

        //Di chuyen len
    case 1:
        if (nv_y >= 50)nv_y -= 150;
        trangthai = 0;
        break;

        //Di chuyen xuong
    case 2:
        if (nv_y < 600)nv_y += 150;
        trangthai = 0;
        break;

        //Bung no
    case 3:
    if (true)
    {
        if (SDL_GetTicks() - time0 >= 100)
        {
            frame = (frame+1)%3;
            time0 = SDL_GetTicks();
        }

        if (phat_no1)
        {
            if (thutuno % 4 == 0)
            {
                if (no1 == nullptr) cout << "Loi tai nhac: " << Mix_GetError() << endl;
                else Mix_PlayChannel(1, no1, 0);
                thutuno++;
                phat_no1 = 0;
            }
            else if (thutuno % 4 == 1)
            {
                if (no2 == nullptr) cout << "Loi tai nhac: " << Mix_GetError() << endl;
                else Mix_PlayChannel(1, no2, 0);
                thutuno++;
                phat_no1 = 0;
            }
            else if (thutuno % 4 == 2)
            {
                if (no3 == nullptr) cout << "Loi tai nhac: " << Mix_GetError() << endl;
                else Mix_PlayChannel(1, no3, 0);
                thutuno++;
                phat_no1 = 0;
            }
            else
            {
                if (no4 == nullptr) cout << "Loi tai nhac: " << Mix_GetError() << endl;
                else Mix_PlayChannel(1, no4, 0);
                thutuno++;
                phat_no1 = 0;
            }
        }
        if (thoigian1)
        {
            time1 = SDL_GetTicks();
            thoigian1 = 0;
            dan_y = nv_y + 60;
            dan_x = nv_x;
        }

        if (SDL_GetTicks() - time1 >= 500)
        {
            trangthai = 0;
            thoigian1 = 1;
            phat_no1 = 1;
            dungno -= 10;
        }

        rect_cat_nv = {frame*80, 0, 80, 85};
        nv_w = 80;
        rect_nv = {nv_x, nv_y, nv_w*2, 145};
        rect_anh = {nv_x - 110, nv_y-20, nv_w*4, 145*2};
        dan_x += SP;
        rect_dan = {dan_x += SP, dan_y - 75, 170, 170};
        rect_nen = {0, 0, nen_w*13/15, nen_h*13/15};
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, nen, NULL, &rect_nen);
        SDL_RenderCopy(renderer, anhbungno, NULL, &rect_anh);
        SDL_RenderCopy(renderer, danbungno, NULL, &rect_dan);
        SDL_RenderCopy(renderer, nv_bungno, &rect_cat_nv, &rect_nv);
    }

    else trangthai = 0;
        break;

        //Tan cong ________________________________________________________________________________________________________________
    case 4:
        if(phat_tancong1)
        {
            if (tancong1 == nullptr) cout << "Loi tai nhac: " << Mix_GetError() << endl;
            else Mix_PlayChannel(2, tancong1, 0);
            phat_tancong1 = 0;
        }

        if (SDL_GetTicks() - time0 >= 100)
        {
            frame = (frame+1)%4;
            time0 = SDL_GetTicks();
        }

        if (thoigian2)
        {
            time1 = SDL_GetTicks();
            thoigian2 = 0;
            dan_y = nv_y + 60;
            dan_x = nv_x + 100;
        }

        if (SDL_GetTicks() - time1 >= 400)
        {
            trangthai = 0;
            thoigian2 = 1;
            phat_no1 = 1;
            phat_tancong1 = 1;
        }

        rect_cat_nv = {frame*95, 0, 95, 85};
        nv_w = 95;
        rect_nv = {nv_x, nv_y, nv_w*2, 145};
        SDL_RenderClear(renderer);
        rect_nen = {0, 0, nen_w*13/15, nen_h*13/15};
        rect_dan = {dan_x += SP, dan_y - 75, 130, 130};
        SDL_RenderCopy(renderer, nen, NULL, &rect_nen);
        SDL_RenderCopy(renderer, danthuong, NULL, &rect_dan);
        SDL_RenderCopy(renderer, nv_tancong, &rect_cat_nv, &rect_nv);
        break;

    default:
        trangthai = 0;
    }
}


// Code ben duoi tham khao CHAT GPT
void spawnZombie()
{
    int type = rand() % 5;
    int truonghop = rand() % 5;
    int startY;
    switch (truonghop)
    {
    case 0:
        startY = 0;
        break;
    case 1:
        startY = 136;
        break;
    case 2:
        startY = 8+136*2;
        break;
    case 3:
        startY = 8+136*3;
        break;
    case 4:
        startY = 8+136*4+20;
        break;
    }
    zombies.push_back(new Zombie(type, S_W, startY));
}

void updateZombies()
{
    for (size_t i = 0; i < zombies.size(); i++)
    {
        zombies[i]->move();
        if (zombies[i]->isOffScreen())
        {
            delete zombies[i];
            zombies.erase(zombies.begin() + i);
            i--;
        }
    }

    for (auto it = zombies.begin(); it != zombies.end(); )
        {
        if (dan_x >= (*it)->rect.x && dan_x <= (*it)->rect.x + (*it)->rect.w &&
            (dan_y >= (*it)->rect.y && dan_y <= (*it)->rect.y + (*it)->rect.h) )
        {
            if (trangthai == 3)
            {
                (*it)->health -= 7;
            }
            else
            {
                (*it)->health -= 1;
            }

            if ((*it)->health <= 0)
            {
                delete *it;
                it = zombies.erase(it);
                KILL++;
                dungno++;
            }
            else ++it;
        }
        else ++it;
    }
}

void renderZombies()
{
    for (Zombie* z : zombies)
    {
        z->render();
    }
}
