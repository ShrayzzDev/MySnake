#pragma once
#include <SDL.h>

#include "window.h"

class Serpent;

class Block
{
	SDL_Rect m_block;
	int m_x;
	int m_y;
	std::string m_type;
public:
	Block(int x, int y, int largeur, int hauteur, const std::string & type);
	void renderBlock(Window & fenetreAct) const;
	void setX(int chgmnt);
	int getX() const;
	void setY(int chgmnt);
	int getY() const;
	void etreMange(Serpent& serp) const;
};

bool operator!=(const Block& b1, const Block& b2);

