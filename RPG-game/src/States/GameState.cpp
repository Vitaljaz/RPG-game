#include "GameState.h"

GameState::GameState(sf::RenderWindow *window, std::stack<State*>* states)
	: State(window, states)
{
}

void GameState::updateKeybinds(const float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		endState();
}

void GameState::update(const float dt)
{
	updateMousePositions();
	updateKeybinds(dt);
	player.update(dt);
}

void GameState::render(sf::RenderTarget * target)
{
	player.render(window);
}


GameState::~GameState()
{
}
