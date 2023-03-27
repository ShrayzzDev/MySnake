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

public:
	Serpent(const Window & fenetre, int taille = 4);
	void renderSerp(Window * fenetreAct) const;
	void Avancer(Window * fenetre);
	void changerDirection(const std::string & dir);
	//void manger();
};

