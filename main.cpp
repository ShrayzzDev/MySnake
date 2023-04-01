#include <string>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <SDL.h>
#include <ctime>

#include "window.h"
#include "Serpent.hpp"
#include "Bloc.hpp"

using namespace std;

void testBase(Window& fentre)
{
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
}

int main(int argc, char **argv)
{
    Window fentre("test", 800, 600);
    Serpent serpi(fentre, 42);
    serpi.renderSerp(&fentre);
    //unsigned int i = 0;
    unsigned int temps = clock();
    while (!fentre.isClosed()){
        while (temps%700 != 0) {
            fentre.reactEvent(serpi);
            temps = clock();
        }
        temps = clock();
        serpi.Avancer(&fentre);
    }
    //testBase(fentre);
    //char temp;
    //temp = _getch();
    return 0;
}