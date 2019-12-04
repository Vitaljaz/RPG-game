#include "..\stdafx.h"
#include "Skeleton.h"

Skeleton::Skeleton(float x, float y, sf::Texture & textureSheet)
{
	setPosition(x, y);

	createHitboxController(sprite, 18.f, 18.f, 50.f, 60.f);
	createMovementController(300.f, 15.f, 5.f);
	createAnimationController(textureSheet);

	animationController->addAnimation("IDLE", 70.f, 0, 0, 3, 0, 128, 96);
	animationController->addAnimation("WALK", 20.f, 0, 1, 5, 1, 128, 96);
	animationController->addAnimation("ATTACK", 20.f, 0, 2, 7, 2, 128, 96);
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
