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
	
	virtual void endState() = 0;
	virtual void update(const float dt) = 0;
	virtual void render(sf::RenderTarget *target = nullptr) = 0;

	virtual ~State();

private:
	sf::RenderWindow *window;
	std::vector<sf::Texture*> textures;
};

