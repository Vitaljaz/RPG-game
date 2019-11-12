#include "State.h"

State::State(sf::RenderWindow *window, std::stack<State*>* states)
{
	this->states = states;
	this->window = window;
	isEnd = false;
}

const bool & State::getEnd() const
{
	return isEnd;
}

void State::checkEndState()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		isEnd = true;
	}
}

void State::updateMousePositions()
{
	mousePositionScreen = sf::Mouse::getPosition();
	mousePositionWindow = sf::Mouse::getPosition(*window);
	mousePositionView = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
}

State::~State()
{

}