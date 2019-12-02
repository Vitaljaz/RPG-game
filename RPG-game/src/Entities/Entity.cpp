#include "../stdafx.h"
#include "Entity.h"

Entity::Entity()
{
	movementController = nullptr;
	animationController = nullptr;
	hitboxController = nullptr;
}

Entity::~Entity()
{
	delete movementController;
	delete animationController;
	delete hitboxController;
}

void Entity::setTexture(sf::Texture & texture)
{
	this->sprite.setTexture(texture);
}

void Entity::createHitboxController(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height)
{
	hitboxController = new HitboxController(sprite, offset_x, offset_y, width, height);
}

void Entity::createMovementController(const float maxVelocity, const float acceleration, const float deceleration)
{
	movementController = new MovementController(sprite, maxVelocity, acceleration, deceleration);
}

void Entity::createAnimationController(sf::Texture & textureSheet)
{
	animationController = new AnimationController(sprite, textureSheet);
}

void Entity::setPosition(const float x, const float y)
{
	sprite.setPosition(x, y);
}

void Entity::move(const float x, const float y, const float dt)
{
	if (movementController)
	{
		movementController->move(x, y, dt);
	}
		
}

void Entity::update(const float dt)
{
}

void Entity::render(sf::RenderTarget * target)
{
	target->draw(this->sprite);

	if (hitboxController)
		hitboxController->render(target);
}
