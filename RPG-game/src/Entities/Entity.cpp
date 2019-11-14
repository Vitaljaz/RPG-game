#include "Entity.h"

Entity::Entity()
{
	movementController = nullptr;
}

Entity::~Entity()
{
}

void Entity::setTexture(sf::Texture & texture)
{
	this->sprite.setTexture(texture);
}

void Entity::createMovementController(const float maxVelocity)
{
	movementController = new MovementController(sprite, maxVelocity);
}

void Entity::setPosition(const float x, const float y)
{
	sprite.setPosition(x, y);
}

void Entity::move(const float dt, const float x, const float y)
{
	if (movementController)
	{
		movementController->move(x, y, dt);
	}
		
}

void Entity::update(const float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		move(dt, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		move(dt, 0.f, 1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		move(dt, 1.f, 0.f);
}

void Entity::render(sf::RenderTarget * target)
{
	target->draw(this->sprite);
}
