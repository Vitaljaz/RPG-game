#include "Button.h"

Button::Button(float x, float y, float w, float h, std::string text)
{
	initFont();

	shape.setPosition(sf::Vector2f(x, y));
	shape.setSize(sf::Vector2f(w, h));
	
	buttonState = ButtonStates::BTN_IDLE;

	this->text.setFont(this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(12);
	this->text.setPosition(
		shape.getPosition().x + (shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		shape.getPosition().y + (shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
	);

	idleColor = sf::Color(100, 100, 100, 200);
	hoverColor = sf::Color(150, 150, 150, 255);
	activeColor = sf::Color(20, 20, 20, 200);

	shape.setFillColor(idleColor);
}


Button::~Button()
{
}

void Button::update(const sf::Vector2f mousePosition)
{
	buttonState = ButtonStates::BTN_IDLE;

	if (shape.getGlobalBounds().contains(mousePosition))
	{
		buttonState = ButtonStates::BTN_HOVER;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			buttonState = ButtonStates::BTN_PRESSED;
		}
	}

	switch (buttonState)
	{
	case ButtonStates::BTN_IDLE:
		shape.setFillColor(idleColor);
		break;

	case ButtonStates::BTN_HOVER:
		shape.setFillColor(hoverColor);
		break;

	case ButtonStates::BTN_PRESSED:
		shape.setFillColor(activeColor);
		break;

	default:
		break;
	}
}

void Button::render(sf::RenderTarget * target)
{
	target->draw(shape);
	target->draw(text);
}

const bool Button::isPressed()
{
	if (buttonState == ButtonStates::BTN_PRESSED)
		return true;

	return false;
}

void Button::initFont()
{
	if (!font.loadFromFile("src/Resources/fonts/Robot.ttf"))
	{
		throw("ERROR: COULD NOT LOAD FONT");
	}
}
