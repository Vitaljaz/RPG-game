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

#define LOG(x) std::cout<< x << std::endl;

class State
{
public:
	State(sf::RenderWindow *window, std::stack<State*>* states);
	
	const bool& getEnd() const;
	void endState();

	virtual void updateMousePositions();

	virtual void updateKeybinds(const float dt) = 0;
	virtual void update(const float dt) = 0;
	virtual void render(sf::RenderTarget *target = nullptr) = 0;

	virtual ~State();

protected:
	std::stack<State*>* states;

	sf::RenderWindow *window;
	std::vector<sf::Texture*> textures;

	sf::Vector2i mousePositionScreen;
	sf::Vector2i mousePositionWindow;
	sf::Vector2f mousePositionView;

	bool isEnd;
};

