#include "GameState.h"

GameState::GameState(sf::RenderWindow *window) : State(window)
{
}

void GameState::endState()
{
}

void GameState::update(const float dt)
{
	std::cout << "Hi from GameState" << std::endl;
}

void GameState::render(sf::RenderTarget * target)
{
}


GameState::~GameState()
{
}
