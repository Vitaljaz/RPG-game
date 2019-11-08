#pragma once
#include "States/GameState.h"

class Game
{
public:
	Game();
	virtual ~Game();

	void run();
	void update();
	void render();
	void updateDt();
	void updateSFMLEvents();

private:
	sf::RenderWindow *window;
	sf::Event sfEvent;
	sf::Clock dtClock;

	std::stack<State*> states;

	float dt;

	void initWindow();
	void initStates();
};

