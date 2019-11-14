#pragma once
#include "../Controllers/MovementController.h"

class Entity
{
public:
	Entity();
	virtual ~Entity();

	void setTexture(sf::Texture& texture);
	void createMovementController(const float maxVelocity);

	virtual void setPosition(const float x, const float y);
	virtual void move(const float dt, const float x, const float y);
	virtual void update(const float dt);
	virtual void render(sf::RenderTarget *target = nullptr);

protected:
	sf::Sprite sprite;

	MovementController* movementController;
};

