#include "Bloc.hpp"
#include "Serpent.hpp"
#include "window.h"

#include <cstdlib>
#include <ctime>
#include <iostream>


using namespace std;

ostream& operator<<(ostream& os, Block& b1)
{
	return os << "Ce block est de type " << b1.getType() << " et a pour coordonées : X = " << b1.getX() << " et Y = " << b1.getY() << endl;
}

ostream& operator<<(ostream& os, list<Block> list_block)
{
	for (Block& bAct : list_block) {
		os << bAct;
	}
	return os;
}

Block::Block(int x, int y, int largeur, int hauteur, const std::string & type)
	:m_x{ x }, m_y{ y }, m_type{type}
{
	m_block.x = x;
	m_block.y = y;
	m_block.w = largeur;
	m_block.h = hauteur;
}

void Block::renderBlock(Window & fenetreAct) const
{
	if (m_type == "serpent") {
		SDL_SetRenderDrawColor(fenetreAct.getRenderer(), 200, 0, 200, 255);
	}

	if (m_type == "pomme") {
		SDL_SetRenderDrawColor(fenetreAct.getRenderer(), 255, 0, 0, 255);
	}
	SDL_RenderFillRect(fenetreAct.getRenderer(), &m_block);

}

void Block::setX(int chgmnt)
{
	m_x += chgmnt;
	m_block.x += chgmnt;
}

int Block::getX() const
{
	return m_x;
}

void Block::setY(int chgmnt)
{
	m_y += chgmnt;
	m_block.y += chgmnt;
}

int Block::getY() const
{
	return m_y;
}

bool operator!=(const Block& b1, const Block& b2)
{
	return b1.getY() != b2.getY() || b1.getX() != b2.getX() ;
}

bool Block::etreMange(Serpent& serp, Window & fenetre)
{
	if (m_type != "pomme") {
		cerr << "Erreur: ce block n'est pas une pomme" << endl;
		return false;
	}
	if (serp.getX() >= m_x - 20 && serp.getX() <= m_x + 20 && serp.getY() >= m_y - 20 && serp.getY() <= m_y + 20) {
		serp.manger();
		generateCoord(fenetre,serp);
		return true;
	}
	return false;
}

void Block::generateCoord(const Window & fenetre, const Serpent & serp)
{
	srand(time(nullptr));
	m_y = 1 + rand() / ((RAND_MAX + 1u) / fenetre.getHauteur());
	m_block.y = m_y;
	m_x = 1 + rand() / ((RAND_MAX + 1u) / fenetre.getLargeur());
	m_block.x = m_x;
}

const string& Block::getType() const
{
	return m_type;
}