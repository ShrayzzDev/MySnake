#include <list>
#include <algorithm>
#include <iterator>
#include <iostream>

#include "Serpent.hpp"
#include "window.h"
#include "Bloc.hpp"

using namespace std;

Serpent::Serpent( const Window & fenetre, int taille)
	:m_taille{ taille }, m_direction{ "haut" }, m_serp{}
{
	int x_init = (fenetre.getLargeur() / 2) + taille/2;
	int y_init = (fenetre.getHauteur() / 2) + taille/2;
	for (int rep = 0; rep < taille; ++rep) {
		Block temp(x_init, y_init + (rep * 40), 40, 40, "serpent");
		m_serp.push_back(temp);
	}
}

void Serpent::renderSerp(Window * fenetreAct) const
{
	fenetreAct->renderFond();

	for (const Block & blockAct : m_serp)
		blockAct.renderBlock(*fenetreAct);

	SDL_RenderPresent(fenetreAct->getRenderer());

}

void Serpent::Avancer(Window * fenetre)
{
	/*int i = 0;
	list<Block>::reverse_iterator it = m_serp.rbegin();
	for (it; *it != m_serp.front() || i == m_serp.size(); ++it, ++i) {
		it->setX(next(it,1)->getX());
		it->setY(next(it,1)->getY());
		cout << "j'avance un bloc de un point" << endl;
	}*/

	m_serp.push_front(m_serp.front());

	m_serp.pop_back();

	if (m_direction == "haut") {
		m_serp.front().setY(-40);
	}

	if (m_direction == "bas") {
		m_serp.front().setY(40);
	}

	if (m_direction == "droite") {
		m_serp.front().setX(40);
	}

	if (m_direction == "gauche") {
		m_serp.front().setX(-40);
	}
	renderSerp(fenetre);
}

void Serpent::changerDirection(const string& dir)
{
	if (dir != "haut" && dir != "bas" && dir != "droite" && dir != "gauche") {
		cerr << "Erreur: direction incorrecte" << endl;
		return;
	}

	if (m_direction == "haut" && dir == "bas") {
		return;
	}

	if (m_direction == "bas" && dir == "haut") {
		return;
	}

	if (m_direction == "droite" && dir == "gauche") {
		return;
	}

	if (m_direction == "gauche" && dir == "droite") {
		return;
	}
	m_direction = dir;
}

void Serpent::manger()
{
	m_serp.push_back(m_serp.back());
}