#include <iostream>
#include <SDL.h>
#include <cmath>

#include "window.h"
#include "Serpent.hpp"
#include "Bloc.hpp"
#include "direction.hpp"

using namespace std;

Window::Window(const string& titre, int largeur, int hauteur) 
	:m_nom{titre}, m_largeur{largeur}, m_hauteur{hauteur}
{
	m_fermé = !init();
}

int Window::getHauteur() const
{
	return m_hauteur;
}

int Window::getLargeur() const
{
	return m_largeur;
}

SDL_Renderer* Window::getRenderer() const
{
	return m_renderer;
}

bool Window::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		cerr << "Failed to initialize SDL" << endl;
		return false;
	}
	m_Window = SDL_CreateWindow(m_nom.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_largeur, m_hauteur, SDL_WINDOW_RESIZABLE);
	if (m_Window == nullptr) {
		cerr << "Failed to create a window" << endl;
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_PRESENTVSYNC);
	if (m_renderer == nullptr) {
		return false;
	}

	return true;
}

bool Window::isClosed() const
{
	return m_fermé;
}

void Window::reactEvent(Serpent& serp) {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			m_fermé = true;
			break;

		case SDL_WINDOWEVENT:
			switch (event.window.event) {
			case SDL_WINDOWEVENT_MAXIMIZED: {
				m_largeur = 1920;
				m_hauteur = 1080;
				serp.renderSerp(this);
				break;
			}
		}
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_UP:
				serp.changerDirection(Haut);
				break;
			case SDLK_DOWN:
				serp.changerDirection(Bas);
				break;
			case SDLK_LEFT:
				serp.changerDirection(Gauche);
				break;
			case SDLK_RIGHT:
				serp.changerDirection(Droite);
				break;
				}
		default:
			break;
		}
	}
}

void Window::renderFond() const
{
	SDL_SetRenderDrawColor(m_renderer, 144, 238, 144, 255);
	SDL_RenderClear(m_renderer);  
}

Window::~Window()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_Window);
	SDL_Quit();
}
