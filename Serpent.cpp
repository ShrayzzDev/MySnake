#include <list>
#include <algorithm>
#include <iterator>
#include <iostream>

#include "Serpent.hpp"
#include "window.h"
#include "Bloc.hpp"
#include "direction.hpp"

using namespace std;

Serpent::Serpent( const Window & fenetre, int taille)
	: m_direction{ Haut }, m_serp{}, m_buffer{ 0,0,0,0,"serpent"}, m_buffer_1{ 0,0,0,0,"serpent" }
{
	int x_init = (fenetre.getLargeur() / 2);
	int y_init = (fenetre.getHauteur() / 2);
	for (int rep = 0; rep < taille; ++rep) {
		Block temp(x_init, y_init + (rep * 40), 40, 40, "serpent");
		m_serp.push_back(temp);
	}
}

void Serpent::renderSerp(Window * fenetreAct) const
{
	for (const Block & blockAct : m_serp)
		blockAct.renderBlock(*fenetreAct);
}

void Serpent::Avancer(Window * fenetre)
{

	m_serp.push_front(m_serp.front());
	m_buffer_1 = m_buffer;
	m_buffer = m_serp.back();
	m_serp.pop_back();

	switch (m_direction)
	{
		case Haut:
			m_serp.front().setY(-20);
			break;

		case Bas:
			m_serp.front().setY(20);
			break;

		case Droite:
			m_serp.front().setX(20);
			break;

		case Gauche:
			m_serp.front().setX(-20);
			break;

	}
	collisionWithHimself();
	renderSerp(fenetre);
}

void Serpent::changerDirection(Direction dir)
{

	if ((m_direction == Haut && dir == Bas) || (m_direction == Bas && dir == Haut) || (m_direction == Droite && dir == Gauche) || (m_direction == Gauche && dir == Droite) ) {
		return;
	}

	m_direction = dir;
}

void Serpent::manger()
{
	m_serp.push_back(m_buffer_1);
}

void Serpent::collisionWithWall(const Window& fenetre) const
{
	if (m_serp.front().getX() >= fenetre.getLargeur() || m_serp.front().getX() <= 0 || m_serp.front().getY() >= fenetre.getHauteur() || m_serp.front().getY() <= 0) {
			exit(1);
	}
}

void Serpent::collisionWithHimself() const
{
	list<Block>::const_iterator it = m_serp.cbegin();
	for (++it; it != m_serp.end(); ++it)
	{
		if (m_serp.front().getX() == it->getX() && m_serp.front().getY() == it->getY())
			exit(2);
	}
}

int Serpent::getX() const
{
	return m_serp.front().getX();
}

int Serpent::getY() const
{
	return m_serp.front().getY();
}