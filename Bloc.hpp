#pragma once
#include <SDL.h>

#include "window.h"

class Block
{
	SDL_Rect m_block;
	int m_x;
	int m_y;
public:
	Block(int x, int y, int largeur, int hauteur);
	void renderBlock(Window & fenetreAct) const;
};

