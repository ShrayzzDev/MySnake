#include "Serpent.hpp"
#include "window.h"

Serpent::Serpent(int taille)
	:m_taille{ taille }, m_direction{ "haut" }, m_serp{}
{
	for (int rep = 0; rep < taille; ++rep) {
		Block temp((1920 / 2) - (1080 / 2), (1920 / 2) - (1080 / 2) - (rep * 40), 40, 40);
		m_serp.push_back(temp);
	}
}

void Serpent::renderSerp(Window & fenetreAct) const
{

}

