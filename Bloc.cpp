#include "Bloc.hpp"
#include "Serpent.hpp"

#include <iostream>

using namespace std;

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
		SDL_SetRenderDrawColor(fenetreAct.getRenderer(), 200, 0, 200, 255);
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

void Block::etreMange(Serpent& serp) const
{
	if (m_type != "pomme") {
		cerr << "Erreur: ce block n'est pas une pomme" << endl;
		return;
	}
	serp.manger();
}