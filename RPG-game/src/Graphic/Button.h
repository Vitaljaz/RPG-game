#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"

class Button
{
public:
	Button();
	Button(float x, float y, float w, float h, sf::Font *font, std::string text);
	virtual ~Button();

	void update(const sf::Vector2f mousePosition);
	void render(sf::RenderTarget *target);

public:
	sf::RectangleShape shape;
	sf::Font *font;
	sf::Text text;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;
};

