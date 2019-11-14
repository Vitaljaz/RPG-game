#pragma once
#include "../Controllers/MovementController.h"

class Entity
{
public:
	Entity();
	virtual ~Entity();

	void setTexture(sf::Texture& texture);
	void createMovementController(const float maxVelocity, const float acceleration, const float deceleration);

	virtual void setPosition(const float x, const float y);
	virtual void move(const float x, const float y, const float dt);
	virtual void update(const float dt);
	virtual void render(sf::RenderTarget *target = nullptr);

protected:
	sf::Sprite sprite;

	MovementController* movementController;
};

