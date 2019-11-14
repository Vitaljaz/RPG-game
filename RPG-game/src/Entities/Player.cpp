#include "Player.h"

Player::Player(float x, float y, sf::Texture* texture)
{
	initVariables();
	initComponets();

	createSprite(texture);
	setPosition(x, y);
}


Player::~Player()
{
}

void Player::initComponets()
{
}

void Player::initVariables()
{
}
