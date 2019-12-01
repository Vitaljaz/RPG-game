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

	void play(const std::string& key, const float dt, const bool priority = false);
	void play(const std::string& key, const float dt, const float modifier, const float modifier_max, const bool priority = false);


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
			timer = 0.f;
			startRect = sf::IntRect(start_frame_x * width, start_frame_y * height, width, height);
			currentRect = startRect;
			endRect = sf::IntRect(frame_x * width, frame_y * height, width, height);

			sprite.setTexture(textureSheet, true);
			sprite.setTextureRect(startRect);
		}
		
		bool play(const float dt)
		{
			bool done = false;
			timer += 300.f * dt;
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
					done = true;
				}

				sprite.setTextureRect(currentRect);
			}
			return done;
		}

		bool play(const float dt, float mod_p)
		{
			if (mod_p < 0.5f)
				mod_p = 0.5f;

			bool done = false;
			timer += mod_p * 300.f * dt;
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
					done = true;
				}

				sprite.setTextureRect(currentRect);
			}
			
			return done;
		}

		void reset()
		{
			currentRect = startRect;
			timer = animationTimer;
		}
	};

	sf::Sprite& sprite;
	sf::Texture& textureSheet;

	Animation* lastAnimation;
	Animation* priorityAnimation;

	std::map<std::string, Animation*> animations;
};

