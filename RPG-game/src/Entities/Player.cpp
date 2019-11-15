#include "Player.h"

Player::Player(float x, float y, sf::Texture& textureSheet)
{
	initVariables();

	setTexture(textureSheet);
	setPosition(x, y);

	createMovementController(300.f, 15.f, 5.f);
	createAnimationController(sprite, textureSheet);

	animationController->addAnimation("IDLE_LEFT", 100.f, 1, 1, 6, 1, 100, 96);
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
