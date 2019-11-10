#include "Button.h"



Button::Button()
{
}

Button::Button(float x, float y, float w, float h, sf::Font * font, std::string text)
{
	shape.setPosition(sf::Vector2f(x, y));
	shape.setSize(sf::Vector2f(w, h));
	
	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(12);
	this->text.setPosition(
		shape.getPosition().x / 2.f - this->text.getGlobalBounds().width / 2.f,
		shape.getPosition().y / 2.f - this->text.getGlobalBounds().height / 2.f
	);

	idleColor = sf::Color::Black;
	hoverColor = sf::Color::Green;
	activeColor = sf::Color::Cyan;

	shape.setFillColor(idleColor);
}


Button::~Button()
{
}

void Button::update(const sf::Vector2f mousePosition)
{
	if (shape.getGlobalBounds().contains(mousePosition))
	{

	}
}

void Button::render(sf::RenderTarget * target)
{
	target->draw(shape);
}
