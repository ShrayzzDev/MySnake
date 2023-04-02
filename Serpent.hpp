#pragma once
#include <SDL.h>
#include <list>
#include <string>

#include "Bloc.hpp"

class Window;

class Serpent
{
	int m_taille;
	std::string m_direction;
	std::list<Block> m_serp;
	Block m_buffer;

public:
	Serpent(const Window & fenetre, int taille = 4);
	void renderSerp(Window * fenetreAct) const;
	void Avancer(Window * fenetre);
	void changerDirection(const std::string & dir);
	void collisionWithWall(const Window & fenetre) const;
	void collisionWithHimself() const;
	int getX() const;
	int getY() const;
	void manger();
};

