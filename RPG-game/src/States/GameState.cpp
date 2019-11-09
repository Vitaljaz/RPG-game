#include "GameState.h"

GameState::GameState(sf::RenderWindow *window) : State(window)
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
	updateKeybinds(dt);
}

void GameState::render(sf::RenderTarget * target)
{
}


GameState::~GameState()
{
}
