#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"

enum class ButtonStates : int { BTN_IDLE, BTN_HOVER, BTN_PRESSED };

class Button
{
public:
	Button(float x, float y, float w, float h, std::string text);
	virtual ~Button();

	void update(const sf::Vector2f mousePosition);
	void render(sf::RenderTarget *target);

	const bool isPressed();

private:
	bool pressed;
	bool hover;

	ButtonStates buttonState;

	sf::RectangleShape shape;
	sf::Font font;
	sf::Text text;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

	void initFont();
};

