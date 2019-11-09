#pragma once

#include "State.h"

class GameState : public State
{
public:
	GameState(sf::RenderWindow *window);

	void endState() override;
	void updateKeybinds(const float dt) override;
	void update(const float dt) override;
	void render(sf::RenderTarget *target = nullptr) override;

	virtual ~GameState();
private:

};

