#pragma once
#include <iostream>
#include <string>
#include <map>

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

class AnimationController
{
public:
	AnimationController();
	virtual ~AnimationController();

private:
	class Animation {
	public:
		sf::Texture& textureSheet;

		int width;
		int height;

		float animationTimer;
		float timer;

		sf::IntRect startRect;
		sf::IntRect endRect;

		Animation(sf::Texture& textureSheet, float animationTimer, int start_x, int start_y, int end_x, int end_y, int width, int height)
			: textureSheet(textureSheet), animationTimer(animationTimer), width(width), height(height)
		{
			startRect = sf::IntRect(start_x, start_y, width, height);
			endRect = sf::IntRect(end_x, end_y, width, height);
		}
		
		void update(const float dt)
		{
			timer = 10.f * dt;
			if (timer >= animationTimer)
			{

			}

		}

		void play();
		void pause();
		void reset();
	};

	std::map<std::string, Animation> animations;
};

