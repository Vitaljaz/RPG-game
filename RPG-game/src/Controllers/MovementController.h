#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

class MovementController
{
public:
	MovementController(sf::Sprite& sprite, float maxVelocity, float acceleration, float deceleration);
	virtual ~MovementController();
	
	void move(const float dir_x, const float dir_y, const float dt);
	void update(const float dt);

	const bool idle() const;
	const bool movingRight() const;
	const bool movingLeft() const;
	const bool moving() const;

	const float getMaxVelocity() const;
	const sf::Vector2f& getVelocity() const;
	
private:
	float maxVelocity;
	float acceleration;
	float deceleration;

	sf::Vector2f velocity;
	sf::Sprite& sprite;
};

