#pragma once
#include <SDL.h>
#include <list>
#include <string>

#include "Bloc.hpp"
#include "direction.hpp"

class Window;

class Serpent
{
	Direction m_direction;
	std::list<Block> m_serp;
	Block m_buffer_1;
	Block m_buffer;

public:
	Serpent(const Window & fenetre, int taille = 4);
	void renderSerp(Window * fenetreAct) const;
	void Avancer(Window * fenetre);
	void changerDirection(Direction dir);
	void collisionWithWall(const Window & fenetre) const;
	void collisionWithHimself() const;
	int getX() const;
	int getY() const;
	void manger();
};

