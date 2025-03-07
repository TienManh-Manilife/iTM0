#ifndef DICHUYEN_H_INCLUDED
#define DICHUYEN_H_INCLUDED

void DiChuyenMuot(SDL_Event &event,bool &up, bool &down, bool &left, bool &right);

void TranhThoatManHinh(SDL_Rect &rect,int SP, bool up, bool down, bool left, bool right, int S_W, int S_H);

#endif // DICHUYEN_H_INCLUDED
