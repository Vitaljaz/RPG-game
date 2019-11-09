#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

class Entity
{
public:
	Entity();
	virtual ~Entity();

	virtual void move(const float dt, const float x, const float y);

	virtual void update(const float dt);
	virtual void render(sf::RenderTarget *target = nullptr);

protected:
	sf::RectangleShape shape;

	float movementSpeed;
};

