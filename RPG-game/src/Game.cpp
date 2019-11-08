#include "Game.h"

Game::Game()
{
	initWindow();
	initStates();
}

Game::~Game()
{
	delete window;
	
	while (!states.empty())
	{
		delete states.top();
		states.pop();
	}
}

void Game::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "RPG");
	window->setFramerateLimit(120);
	window->setVerticalSyncEnabled(true);
}

void Game::initStates()
{
	states.push(new GameState(window));
}

void Game::run()
{
	while (window->isOpen())
	{
		updateDt();
		update();
		render();
	}
}

void Game::update()
{
	updateSFMLEvents();

	if (!states.empty())
		states.top()->update(this->dt);
}

void Game::render()
{
	window->clear();

	if (!states.empty())
		states.top()->render();

	window->display();
}

void Game::updateDt()
{
	dt = dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents()
{
	while (window->pollEvent(sfEvent))
	{
		if (sfEvent.type == sf::Event::Closed)
			window->close();
	}
}
