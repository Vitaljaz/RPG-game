#pragma once
#include "State.h"
#include "GameState.h"

#include "../Graphic/Button.h"

enum class MenuButtons : int {GAME_STATE = 0, EXIT_STATE};

class MenuState : public State
{
public:
	MenuState(sf::RenderWindow *window);

	void endState() override;

	void updateKeybinds(const float dt) override;
	void update(const float dt) override;
	void updateButtons();

	void renderButtons(sf::RenderTarget *target = nullptr);
	void render(sf::RenderTarget *target = nullptr) override;

	virtual ~MenuState();
	
private:
	sf::RectangleShape background;
	sf::Font font;

	Button *btnGameState;

	std::map<MenuButtons, Button*> buttons;

	void initButtons();
};

