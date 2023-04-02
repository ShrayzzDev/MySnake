#pragma once

#include <string>
#include <SDL.h>

class Serpent;

class Window {
	std::string m_nom;
	int m_largeur = 800;
	int m_hauteur = 600;
	bool m_ferm� = false;

	SDL_Window* m_Window = nullptr;
	SDL_Renderer* m_renderer = nullptr;

public:

	Window(const std::string& titre, int largeur, int hauteur);
	int getHauteur() const;
	int getLargeur() const;
	SDL_Renderer* getRenderer() const;
	bool init();
	bool isClosed() const;
	void reactEvent(Serpent& serp);
	void renderFond() const;
	~Window();
};