#pragma once
#include <SDL.h>
#include <string>
#include <iostream>
#include <list>

#include "window.h"

class Serpent;

class Block
{
	SDL_Rect m_block;
	int m_x;
	int m_y;
	std::string m_type;
public:
	Block(int x, int y, int largeur = 40, int hauteur = 40, const std::string & type = "Pomme");
	void renderBlock(Window & fenetreAct) const;
	void setX(int chgmnt);
	int getX() const;
	void setY(int chgmnt);
	int getY() const;
	const std::string& getType() const;
	bool etreMange(Serpent& serp, Window& fenetre);
	void generateCoord(const Window& fenetre, const Serpent& serp);
};

bool operator!=(const Block& b1, const Block& b2);
std::ostream& operator<<(std::ostream& os, Block& b1);
std::ostream& operator<<(std::ostream& os, std::list<Block> list_block);
