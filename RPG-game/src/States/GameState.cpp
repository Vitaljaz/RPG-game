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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		player->move(0.f, -1.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		player->move(-1.f, 0.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		player->move(0.f, 1.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		player->move(1.f, 0.f, dt);
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
	player = new Player(0, 0, textures["PLAYER_SHEET"]);
}

void GameState::initTextures()
{
	textures["PLAYER_SHEET"].loadFromFile("src/Resources/images/sprites/Player/idle_anim.png");
}
