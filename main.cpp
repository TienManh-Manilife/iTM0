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
#include "event.h"

using namespace std;

int main(int argc, char* argv[])
{
    srand(time(0));
    game();
    return 0;
}
