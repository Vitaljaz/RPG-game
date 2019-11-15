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

	void addAnimation(const std::string& key, float animationTimer, int start_frame_x, 
		int start_frame_y, int frame_x, int frame_y,  int width, int height);

	void play(const std::string& key, const float dt);

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

		Animation(sf::Sprite& sprite, sf::Texture& textureSheet, 
			float animationTimer, int start_frame_x, int start_frame_y, int frame_x, int frame_y,
			int width, int height)
			: sprite(sprite), textureSheet(textureSheet), animationTimer(animationTimer), width(width), height(height)
		{
			startRect = sf::IntRect(start_frame_x * width, start_frame_y * height, width, height);
			currentRect = startRect;
			endRect = sf::IntRect(frame_x * width, frame_y * height, width, height);

			sprite.setTexture(textureSheet, true);
			sprite.setTextureRect(startRect);
		}
		
		void play(const float dt)
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

				sprite.setTextureRect(currentRect);
			}

		}

		void reset()
		{
			currentRect = startRect;
			timer = 0.f;
		}
	};

	sf::Sprite& sprite;
	sf::Texture& textureSheet;

	std::map<std::string, Animation*> animations;
};

