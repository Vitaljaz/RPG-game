#include "MenuState.h"

MenuState::MenuState(sf::RenderWindow *window, std::stack<State*>* states)
	: State(window, states)
{
	background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	background.setFillColor(sf::Color::Blue);

	initButtons();
}

void MenuState::endState()
{
	LOG("End MainMenu state!")
}

void MenuState::updateKeybinds(const float dt)
{
	checkEndState();
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

void MenuState::initButtons()
{
	buttons[MenuButtons::GAME_STATE] = new Button(100, 100, 150, 50, "START");
	buttons[MenuButtons::EXIT_STATE] = new Button(100, 200, 150, 50, "EXIT");
}
