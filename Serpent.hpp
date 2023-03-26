#pragma once
#include <SDL.h>
#include <list>
#include <string>

#include "window.h"
#include "Block.hpp"

class Serpent
{
	int m_taille;
	std::string m_direction;
	std::list<Block> m_serp;

public:
	Serpent(int taille = 4);
	void renderUnBloc(Window& fenetreAct) const;
	void renderSerp(Window & fenetreAct) const;
	void Avancer();
	void changerDirection();
	void manger();
};

