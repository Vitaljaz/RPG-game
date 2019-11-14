#pragma once

#include "State.h"

#include "../Entities/Player.h"

class GameState : public State
{
public:
	GameState(sf::RenderWindow *window, std::stack<State*>* states);

	void updateKeybinds(const float dt) override;
	void update(const float dt) override;
	void render(sf::RenderTarget *target = nullptr) override;

	virtual ~GameState();

private:
	Player* player;

	void initPlayer();
	void initTextures();
};

