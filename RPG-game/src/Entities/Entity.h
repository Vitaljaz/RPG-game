#pragma once
#include "../Controllers/MovementController.h"
#include "../Controllers/AnimationController.h"
#include "../Controllers/HitboxController.h"

class Entity
{
public:
	Entity();
	virtual ~Entity();

	void setTexture(sf::Texture& texture);
	void createHitboxController(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height);
	void createMovementController(const float maxVelocity, const float acceleration, const float deceleration);
	void createAnimationController(sf::Texture& textureSheet);

	virtual void setPosition(const float x, const float y);
	virtual void move(const float x, const float y, const float dt);
	virtual void update(const float dt);
	virtual void render(sf::RenderTarget *target = nullptr);

protected:
	sf::Sprite sprite;

	HitboxController* hitboxController;
	MovementController* movementController;
	AnimationController* animationController;

	int health;
	int visibleRange;
	int attackRange;
	int damage;
};

