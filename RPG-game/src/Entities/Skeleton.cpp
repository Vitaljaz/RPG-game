#include "..\stdafx.h"
#include "Skeleton.h"

Skeleton::Skeleton(float x, float y, sf::Texture& textureSheet, Player* target)
{
	initVariables(target);
	initComponets(textureSheet);
	setPosition(x, y);
}

Skeleton::~Skeleton()
{
}

void Skeleton::update(const float dt)
{
	movementController->update(dt);
	updateAnimations(dt);
	hitboxController->update();
}

void Skeleton::updateAnimations(const float dt)
{
	animationController->play("IDLE", dt, movementController->getVelocity().x, movementController->getMaxVelocity());
}

void Skeleton::initComponets(sf::Texture & textureSheet)
{
	createHitboxController(sprite, 18.f, 36.f, 50.f, 60.f);
	createMovementController(300.f, 15.f, 5.f);
	createAnimationController(textureSheet);

	animationController->addAnimation("IDLE", 70.f, 0, 0, 3, 0, 128, 96);
	animationController->addAnimation("WALK", 20.f, 0, 1, 5, 1, 128, 96);
	animationController->addAnimation("ATTACK", 20.f, 0, 2, 7, 2, 128, 96);
}

void Skeleton::initVariables(Player * target)
{
	this->target = target;
	attacking = false;
	health = 100;
	visibleRange = 300;
	attackRange = 60;
	damage = 20;
}
