#include "MenuState.h"

MenuState::MenuState(sf::RenderWindow *window) : State(window)
{
	background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	background.setFillColor(sf::Color::Blue);
}

void MenuState::endState()
{
	std::cout << "Menu is finished" << std::endl;
}

void MenuState::updateKeybinds(const float dt)
{
	checkEndState();
}

void MenuState::update(const float dt)
{
	updateKeybinds(dt);
}

void MenuState::render(sf::RenderTarget * target)
{
	if (!target)
		target = window;

	target->draw(background);
}


MenuState::~MenuState()
{
}
