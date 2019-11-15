#include "Player.h"

Player::Player(float x, float y, sf::Texture& textureSheet)
{
	initVariables();

	setPosition(x, y);

	createMovementController(300.f, 15.f, 5.f);
	createAnimationController(textureSheet);

	animationController->addAnimation("IDLE_LEFT", 100.f, 0, 0, 5, 0, 100, 96);
}


Player::~Player()
{
}

void Player::update(const float dt)
{
	movementController->update(dt);
	animationController->play("IDLE_LEFT", dt);
}

void Player::initComponets()
{
}

void Player::initVariables()
{
}
