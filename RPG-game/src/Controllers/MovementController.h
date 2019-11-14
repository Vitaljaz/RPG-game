#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

class MovementController
{
public:
	MovementController(sf::Sprite& sprite, float maxVelocity);
	virtual ~MovementController();
	
	void move(const float dir_x, const float dir_y, const float dt);
	void update(const float dt);

	const sf::Vector2f& getVelocity() const;
	
private:
	float maxVelocity;
	
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	sf::Vector2f deceleration;
	
	sf::Sprite& sprite;
};

