//24020220
#ifndef DICHUYEN_H_INCLUDED
#define DICHUYEN_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

extern int trangthai;

extern int frame, frame_zb, zb_w, zb_h;

extern int nv_x, nv_y , nv_w, nen_w, nen_h, dan_x, dan_y;

extern SDL_Rect rect_nv;

extern SDL_Rect rect_nen;

extern SDL_Rect rect_anh;

extern Uint32 zombie_time;

void capnhattrangthai (SDL_Event &event, int &trangthai, bool &run);

void hanhdongnhanvat ();

extern Uint32 time_zb;

const int ZOMBIE_SPEED = 1;


// Code ben duoi tham khao CHAT GPT
class Zombie {
public:
    int x, y, health;
    SDL_Texture* texture;
    SDL_Rect rect;
    Zombie(int type, int startX, int startY) {
        texture = zombieTextures[type];
        x = startX;
        y = startY;
        health = getHealthByType(type);
    }

    void move() {
        x -= ZOMBIE_SPEED;
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
        return x < -50;
    }

    // Hàm xử lý khi zombie chết
    void onDeath()
    {
        // Xóa zombie khỏi danh sách
        std::cout << "Zombie loại " << type << " đã chết!\n";
    }

private:
    int type;
    int getHealthByType(int type)
    {
        switch (type)
        {
            case 0: return 3;
            case 1: return 5;
            case 2: return 5;
            case 3: return 7;
            case 4: return 7;
            default: return 5;
        }
    }
};

void spawnZombie();
void updateZombies();
void renderZombies();

#endif
