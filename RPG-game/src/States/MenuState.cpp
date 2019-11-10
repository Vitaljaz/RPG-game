#include "MenuState.h"

MenuState::MenuState(sf::RenderWindow *window) : State(window)
{
	background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	background.setFillColor(sf::Color::Blue);

	btnGameState = new Button(100, 100, 150, 50, "Game");
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
	updateMousePositions();
	updateKeybinds(dt);

	btnGameState->update(mousePositionView);
}

void MenuState::render(sf::RenderTarget * target)
{
	if (!target)
		target = window;

	target->draw(background);
	
	btnGameState->render(target);
}


MenuState::~MenuState()
{
	delete btnGameState;
}
