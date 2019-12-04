#include "..\stdafx.h"
#include "MenuState.h"

MenuState::MenuState(sf::RenderWindow *window, std::stack<State*>* states)
	: State(window, states)
{
	initBackground();
	initButtons();
}

void MenuState::updateKeybinds(const float dt)
{
}

void MenuState::update(const float dt)
{
	updateMousePositions();
	updateKeybinds(dt);
	updateButtons();
}

void MenuState::updateButtons()
{
	for (auto& it : buttons)
		it.second->update(mousePositionView);

	if (buttons[MenuButtons::GAME_STATE]->isPressed())
	{
		states->push(new GameState(window, states));
	}

	if (buttons[MenuButtons::EXIT_STATE]->isPressed())
	{
		endState();
		isEnd = true;
	}
}

void MenuState::renderButtons(sf::RenderTarget * target)
{
	for (auto& it : buttons)
		it.second->render(target);
}

void MenuState::render(sf::RenderTarget * target)
{
	if (!target)
		target = window;

	target->draw(background);

	renderButtons(target);
}


MenuState::~MenuState()
{
	for (auto it = buttons.begin(); it != buttons.end(); ++it)
		delete it->second;
}

void MenuState::initBackground()
{
	background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));

	if (!backgroundTexture.loadFromFile("src/Resources/images/backgrounds/bg1.png"))
	{
		throw("ERROR: FAILED TO LOAD MENU BACKGROUND");
	}

	background.setTexture(&backgroundTexture);
}

void MenuState::initButtons()
{
	buttons[MenuButtons::GAME_STATE] = new Button(437, 250, 150, 50, "New Game");
	buttons[MenuButtons::SETTINGS_STATE] = new Button(437, 350, 150, 50, "Settings");
	buttons[MenuButtons::EXIT_STATE] = new Button(437, 450, 150, 50, "Quit");
}
