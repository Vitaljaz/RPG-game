#include "GameState.h"

GameState::GameState(sf::RenderWindow *window, std::stack<State*>* states)
	: State(window, states)
{
}

void GameState::endState()
{
	std::cout << "Game is finished" << std::endl;
}

void GameState::updateKeybinds(const float dt)
{
	checkEndState();
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
