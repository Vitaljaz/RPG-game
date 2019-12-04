#include "..\stdafx.h"
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

	// player actions
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		player->setAttack();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		player->move(0.f, -1.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		player->move(-1.f, 0.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		player->move(0.f, 1.f, dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		player->move(1.f, 0.f, dt);
}

void GameState::update(const float dt)
{
	updateMousePositions();
	updateKeybinds(dt);
	player->update(dt);
	skeleton->update(dt);
}

void GameState::render(sf::RenderTarget * target)
{
	player->render(window);
	skeleton->render(window);
}


GameState::~GameState()
{
	delete player;
	delete skeleton;
}

void GameState::initPlayer()
{
	player = new Player(0, 0, textures["PLAYER_SHEET"]);
	skeleton = new Skeleton(100, 100, textures["SKELETON_SHEET"]);
}

void GameState::initTextures()
{
	textures["PLAYER_SHEET"].loadFromFile("src/Resources/images/sprites/Player/player_sheet_2.png");
	textures["SKELETON_SHEET"].loadFromFile("src/Resources/images/sprites/Enemy/skeleton_sheet.png");
}
