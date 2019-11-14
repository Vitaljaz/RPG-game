#include "Player.h"

Player::Player(float x, float y, sf::Texture& texture)
{
	initVariables();
	initComponets();

	setTexture(texture);
	setPosition(x, y);
}


Player::~Player()
{
}

void Player::initComponets()
{
	createMovementController(100.f);
}

void Player::initVariables()
{
}
