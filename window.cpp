#include <iostream>
#include <SDL.h>
#include <cmath>

#include "window.h"

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

void Window::reactEvent(SDL_Rect & rectangle) {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			m_fermé = true;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_UP:
				clear(rectangle, 0, -10);
				break;
			 
			case SDLK_DOWN:
				clear(rectangle, 0, 10);
				break;

			case SDLK_LEFT:
				clear(rectangle, -10, 0);
				break;

			case SDLK_RIGHT:
				clear(rectangle, 10, 0);
				break;
			}
		case SDL_WINDOWEVENT:
			switch (event.window.event) {
			case SDL_WINDOWEVENT_MAXIMIZED: {
				m_largeur = 1920;
				m_hauteur = 1080;
				clear(rectangle, 0, 0);
				break;
			}
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

void Window::clear(SDL_Rect & rectangle, int changeX, int changeY) const {

	//const int pi = acos(-1);
	//int x = 1,y = 0, max = 1000;
	//for (int rep = 0; rep < max; rep++)
	//{
	//	x -= (2 * pi)/max;
	//	y += (2 * pi)/max;
	//	SDL_SetRenderDrawColor(m_renderer, 200, 0, 200, 255);
	//	SDL_RenderDrawPoint(m_renderer, cos(x), sin(y));
	//}

	if (! (m_largeur <= rectangle.x)) {
		rectangle.x += changeX;
	}
	if (! (m_largeur <= rectangle.y)) {
		rectangle.y += changeY;
	}

	renderFond();

	SDL_SetRenderDrawColor(m_renderer, 200, 0, 200, 255);
	SDL_RenderFillRect(m_renderer, &rectangle);

	SDL_RenderPresent(m_renderer);
}

Window::~Window()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_Window);
	SDL_Quit();
}
