#include "Bloc.hpp"

Block::Block(int x, int y, int largeur, int hauteur)
	:m_x{ x }, m_y{ y }
{
	m_block.x = x;
	m_block.y = y;
	m_block.w = largeur;
	m_block.h = hauteur;
}

void Block::renderBlock(Window & fenetreAct) const
{

	SDL_SetRenderDrawColor(fenetreAct.getRenderer(), 200, 0, 200, 255);;
	SDL_RenderFillRect(fenetreAct.getRenderer(), &m_block);

}

void Block::setX(int chgmnt)
{
	m_x += chgmnt;
	m_block.x += chgmnt;
}

int Block::getX()
{
	return m_x;
}

void Block::setY(int chgmnt)
{
	m_y += chgmnt;
	m_block.y += chgmnt;
}

int Block::getY()
{
	return m_y;
}