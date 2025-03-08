#ifndef DICHUYEN_H_INCLUDED
#define DICHUYEN_H_INCLUDED

void hanhdong(SDL_Event &event, int &trangthai);

void chontexture(int &trangthai,
                 SDL_Texture* texture_nvdungyen,
                 SDL_Texture* texture_nvdibo,
                 SDL_Texture* texture_nvbungno,
                 SDL_Texture* texture_nvnhay,
                 SDL_Texture* texture_nvtancong,
                 SDL_Texture* texture_thannam,
                 SDL_Texture* texture_thannu);

#endif
