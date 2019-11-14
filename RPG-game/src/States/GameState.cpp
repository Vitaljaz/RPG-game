#include "GameState.h"

GameState::GameState(sf::RenderWindow *window, std::stack<State*>* states)
	: State(window, states)
{
	initTextures();
	initPlayer();
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
	player->update(dt);
}

void GameState::render(sf::RenderTarget * target)
{
	player->render(window);
}


GameState::~GameState()
{
	delete player;
}

void GameState::initPlayer()
{
	player = new Player(0, 0, textures["P_I"]);
}

void GameState::initTextures()
{
	textures["P_I"].loadFromFile("src/Resources/images/sprites/Player/player_idle.png");
}
