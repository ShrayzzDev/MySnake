#include <string>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <SDL.h>

#include "window.h"

using namespace std;

int main(int argc, char **argv)
{
    Window fentre("test", 800, 600);
    SDL_Rect rectangle;
    fentre.renderFond();
    rectangle.w = 120;
    rectangle.h = 80;
    rectangle.x = (fentre.getLargeur() / 2) - (rectangle.w / 2);
    rectangle.y = (fentre.getHauteur() / 2) - (rectangle.h / 2);
    fentre.clear(rectangle, 0, 0);
    while (!fentre.isClosed()) {
        fentre.reactEvent(rectangle);
    }
    //char temp;
    //temp = _getch();
    return 0;
}