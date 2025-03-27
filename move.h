//24020220
#ifndef DICHUYEN_H_INCLUDED
#define DICHUYEN_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

extern int trangthai;

extern int frame, frame_zb, zb_w, zb_h, damage, hp, damage_add;

extern int nv_x, nv_y , nv_w, nen_w, nen_h, dan_x, dan_y;

extern SDL_Rect rect_nv;

extern SDL_Rect rect_nen;

extern SDL_Rect rect_anh;

extern Uint32 zombie_time;

void capnhattrangthai (SDL_Event &event, int &trangthai, bool &run);

void hanhdongnhanvat ();

extern Uint32 time_zb;

extern int ZOMBIE_SPEED, ZOMBIE_SPEED_ADD;


class Zombie
{
public:
    int x = 1040, y, health;
    SDL_Texture* texture;
    SDL_Rect rect;
    Zombie(int type, int startX, int startY) {
        texture = zombieTextures[type];
        x = startX;
        y = startY;
        health = getHealthByType(type);
    }

    void move()
    {
        x -= (ZOMBIE_SPEED + ZOMBIE_SPEED_ADD/3000);
    }

    void render()
    {
        SDL_QueryTexture(texture, NULL, NULL, &zb_w, &zb_h);
        if (SDL_GetTicks() - time_zb >= 100)
        {
            time_zb = SDL_GetTicks();
            frame_zb = (frame_zb+1)%7;
        }
        rect = { x, y, 142, 160};
        SDL_Rect rect_cat = {frame_zb*zb_w/7, 0, zb_w/7, zb_h};
        SDL_RenderCopy(renderer, texture, &rect_cat, &rect);
    }

    bool isOffScreen()
    {
        return x<-50;
    }

private:
    int type;
    int getHealthByType(int type)
    {
        switch (type)
        {
            case 0: return 1 + hp/100;
            case 1: return 2 + 1.2*hp/100;
            case 2: return 3 + 1.5*hp/100;
            case 3: return 4 + 1.8*hp/100;
            case 4: return 5 + 2*hp/100;
            default: return 4 + 5*hp/100;
        }
    }
};

void spawnZombie();
void updateZombies();
void renderZombies();

#endif
