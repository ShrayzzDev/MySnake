#include <string>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <SDL.h>
#include <ctime>
#include <cstdlib>

#include "window.h"
#include "Serpent.hpp"
#include "Bloc.hpp"

using namespace std;

int main(int argc, char **argv)
{
    Window fentre("test", 1600, 900);
    Serpent serpi(fentre, 32);
    Block Pomme(0,0,40,40,"pomme");
    serpi.renderSerp(&fentre);
    Pomme.generateCoord(fentre, serpi);
    Pomme.renderBlock(fentre);
    SDL_RenderPresent(fentre.getRenderer());
    unsigned int temps = clock();
    while (!fentre.isClosed()){
        
        while (temps%450 != 0) {
            fentre.reactEvent(serpi);
            temps = clock();
        }
        fentre.renderFond();
        temps = clock();
        serpi.Avancer(&fentre);
        serpi.collisionWithWall(fentre);
        Pomme.etreMange(serpi, fentre);
        serpi.renderSerp(&fentre);
        Pomme.renderBlock(fentre);
        SDL_RenderPresent(fentre.getRenderer());
    }
    return 0;
}