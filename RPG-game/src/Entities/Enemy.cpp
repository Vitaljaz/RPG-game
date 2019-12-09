#include "..\stdafx.h"
#include "Enemy.h"

Enemy::Enemy()
{
	movementController = nullptr;
	animationController = nullptr;
	hitboxController = nullptr;
	target = nullptr;
}

Enemy::Enemy(float x, float y, Player* target)
{
	setPosition(x, y);
	this->target = target;
	createMovementController(300.f, 15.f, 5.f);
}

Enemy::~Enemy()
{
}

void Enemy::update(const float dt)
{
}

