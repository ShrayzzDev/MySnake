#include "Bloc.hpp"

Block::Block(int x, int y, int largeur, int hauteur)
	:m_x{ x }, m_y{ y }
{
	m_block.w = largeur;
	m_block.h = hauteur;
}

void Block::renderBlock(Window & fenetreAct) const
{
	fenetreAct.renderFond();

	SDL_SetRenderDrawColor(m_renderer, 200, 0, 200, 255);
	SDL_RenderFillRect(m_renderer, &m_block);

	SDL_RenderPresent(m_renderer);
}