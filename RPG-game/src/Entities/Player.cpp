#include "Player.h"

Player::Player(float x, float y, sf::Texture& textureSheet)
{
	initVariables();

	setPosition(x, y);

	createMovementController(300.f, 15.f, 5.f);
	createAnimationController(textureSheet);

	animationController->addAnimation("IDLE_LEFT", 70.f, 0, 0, 5, 0, 100, 96);
	animationController->addAnimation("WALK", 20.f, 0, 1, 10, 1, 100, 96);
}


Player::~Player()
{
}

void Player::update(const float dt)
{
	movementController->update(dt);

	if (movementController->idle())
		animationController->play("IDLE_LEFT", dt);
	else if (movementController->movingLeft())
	{
		sprite.setOrigin(88.f, 0.f);
		sprite.setScale(-1.f, 1.f);
		animationController->play("WALK", dt);
	}
	else if (movementController->movingRight())
	{
		sprite.setOrigin(0.f, 0.f);
		sprite.setScale(1.f, 1.f);
		animationController->play("WALK", dt);
	}
	else if (movementController->moving())
	{
		animationController->play("WALK", dt);
	}
		

	
}

void Player::initComponets()
{
}

void Player::initVariables()
{
}
