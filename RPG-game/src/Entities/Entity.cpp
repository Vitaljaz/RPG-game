#include "Entity.h"

Entity::Entity()
{
	movementController = nullptr;
}

Entity::~Entity()
{
	delete movementController;
}

void Entity::setTexture(sf::Texture & texture)
{
	this->sprite.setTexture(texture);
}

void Entity::createMovementController(const float maxVelocity, const float acceleration, const float deceleration)
{
	movementController = new MovementController(sprite, maxVelocity, acceleration, deceleration);
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
	if (movementController)
		movementController->update(dt);
}

void Entity::render(sf::RenderTarget * target)
{
	target->draw(this->sprite);
}
