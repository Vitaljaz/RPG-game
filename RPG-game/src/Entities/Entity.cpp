#include "Entity.h"

Entity::Entity()
{
	sprite = nullptr;
	texture = nullptr;
	movementSpeed = 100.f;
}

Entity::~Entity()
{
	delete sprite;
}

void Entity::createSprite(sf::Texture * texture)
{
	this->texture = texture;
	this->sprite->setTexture(*this->texture);
}

void Entity::move(const float dt, const float x, const float y)
{
	if (sprite)
		sprite->move(x * movementSpeed * dt, y * movementSpeed * dt); 
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
	if (sprite)
		target->draw(*this->sprite);
}
