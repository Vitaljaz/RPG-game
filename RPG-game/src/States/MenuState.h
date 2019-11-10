#pragma once
#include "State.h"
#include "GameState.h"

#include "../Graphic/Button.h"

class MenuState : public State
{
public:
	MenuState(sf::RenderWindow *window);

	void endState() override;
	void updateKeybinds(const float dt) override;
	void update(const float dt) override;
	void render(sf::RenderTarget *target = nullptr) override;

	virtual ~MenuState();
	
private:
	sf::RectangleShape background;
};

