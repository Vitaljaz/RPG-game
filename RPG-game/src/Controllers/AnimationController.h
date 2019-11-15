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
	AnimationController(sf::Sprite& sprite, sf::Texture& textureSheet);

	virtual ~AnimationController();

	void addAnimation(const std::string& key);

	void startAnimation(const std::string& animation);
	void pauseAnimation(const std::string& animation);
	void resetAnimation(const std::string& animation);

	void update();

private:
	class Animation {
	public:
		sf::Sprite& sprite;
		sf::Texture& textureSheet;

		int width;
		int height;

		float animationTimer;
		float timer;

		sf::IntRect startRect;
		sf::IntRect currentRect;
		sf::IntRect endRect;

		Animation(sf::Sprite& sprite, sf::Texture& textureSheet, float animationTimer, int start_x, int start_y, int end_x, int end_y, int width, int height)
			: sprite(sprite), textureSheet(textureSheet), animationTimer(animationTimer), width(width), height(height)
		{
			startRect = sf::IntRect(start_x, start_y, width, height);
			currentRect = startRect;
			endRect = sf::IntRect(end_x, end_y, width, height);

			sprite.setTexture(textureSheet, true);
			sprite.setTextureRect(startRect);
		}
		
		void update(const float dt)
		{
			timer = 10.f * dt;
			if (timer >= animationTimer)
			{
				timer = 0.f;
				if (currentRect != endRect)
				{
					currentRect.left += width;
				}
				else
				{
					currentRect.left = startRect.left;
				}
			}

		}

		void play();
		void pause();
		void reset();
	};

	sf::Sprite& sprite;
	sf::Texture& textureSheet;

	std::map<std::string, Animation> animations;
};

