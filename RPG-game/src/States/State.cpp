#include "State.h"

State::State(sf::RenderWindow *window)
{
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

State::~State()
{

}