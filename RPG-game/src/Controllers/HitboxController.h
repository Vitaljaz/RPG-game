#pragma once
#include <iostream>
#include <string>
#include <map>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

class HitboxController
{
public:
	HitboxController(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height);
	virtual ~HitboxController();

	bool checkCollision(const sf::FloatRect frect);
private:
	sf::RectangleShape hitbox;
	sf::Sprite& sprite;

	void update();
	void render(sf::RenderTarget& target);

	float offsetX;
	float offsetY;
};

