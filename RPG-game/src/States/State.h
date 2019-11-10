#pragma once
#include <iostream>
#include <ctime>
#include <cstdio>
#include <vector>
#include <stack>
#include <map>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class State
{
public:
	State(sf::RenderWindow *window);
	
	const bool& getEnd() const;

	virtual void checkEndState();
	virtual void updateMousePositions();

	virtual void endState() = 0;
	virtual void updateKeybinds(const float dt) = 0;
	virtual void update(const float dt) = 0;
	virtual void render(sf::RenderTarget *target = nullptr) = 0;

	virtual ~State();

protected:
	sf::RenderWindow *window;
	std::vector<sf::Texture*> textures;

	sf::Vector2i mousePositionScreen;
	sf::Vector2i mousePositionWindow;
	sf::Vector2f mousePositionView;

	bool isEnd;
};

