#include "..\stdafx.h"
#include "Player.h"

Player::Player(float x, float y, sf::Texture& textureSheet)
{
	initVariables();
	initComponets(textureSheet);
	setPosition(x, y);
}

Player::~Player()
{
}

void Player::update(const float dt)
{
	movementController->update(dt);
	updateAnimations(dt);
	hitboxController->update();
}

void Player::setAttack()
{
	attacking = true;
}

void Player::initComponets(sf::Texture& textureSheet)
{
	createHitboxController(sprite, 18.f, 18.f, 50.f, 60.f);
	createMovementController(300.f, 15.f, 5.f);
	createAnimationController(textureSheet);

	animationController->addAnimation("IDLE", 70.f, 0, 0, 5, 0, 128, 96);
	animationController->addAnimation("WALK", 20.f, 0, 1, 10, 1, 128, 96);
	animationController->addAnimation("ATTACK", 20.f, 0, 2, 8, 2, 128, 96);
}

void Player::initVariables()
{
	attacking = false;
	health = 100;
	visibleRange = 300;
	attackRange = 50;
	damage = 30;
}

void Player::updateAnimations(const float dt)
{
	if (attacking)
	{
		if (animationController->play("ATTACK", dt, true))
			attacking = false;
	}

	if (movementController->idle())
		animationController->play("IDLE", dt, movementController->getVelocity().x, movementController->getMaxVelocity());
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
		animationController->play("WALK", dt, movementController->getVelocity().x, movementController->getMaxVelocity());
	}
	else if (movementController->moving())
	{
		animationController->play("WALK", dt, movementController->getVelocity().y, movementController->getMaxVelocity());
	}
}
