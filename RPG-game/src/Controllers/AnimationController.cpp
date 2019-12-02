#include "../stdafx.h"
#include "AnimationController.h"

AnimationController::AnimationController(sf::Sprite& sprite, sf::Texture& textureSheet) 
	: sprite(sprite), textureSheet(textureSheet), lastAnimation(nullptr), priorityAnimation(nullptr) {}


AnimationController::~AnimationController()
{
	for (auto& i : animations)
		delete i.second;
}

void AnimationController::addAnimation(const std::string & key,	float animationTimer, int start_frame_x, 
	int start_frame_y, int frame_x, int frame_y,
	int width, int height)
{
	std::cout << "add new animation : " << key << std::endl;
	animations[key] = new Animation(sprite, textureSheet, animationTimer, 
		start_frame_x, start_frame_y, frame_x, frame_y, width, height);
}

const bool& AnimationController::play(const std::string & key, const float dt, const bool priority)
{
	if (priority)
		priorityAnimation = animations[key];

	if (priorityAnimation)
	{
		if (priorityAnimation == animations[key])
		{
			if (lastAnimation != animations[key])
			{
				if (lastAnimation == nullptr)
					lastAnimation = animations[key];
				else
				{
					lastAnimation->reset();
					lastAnimation = animations[key];
				}
			}

			if (animations[key]->play(dt))
			{
				priorityAnimation = nullptr;
			}
		}
	}
	else
	{
		if (lastAnimation != animations[key])
		{
			if (lastAnimation == nullptr)
				lastAnimation = animations[key];
			else
			{
				lastAnimation->reset();
				lastAnimation = animations[key];
			}
		}
		animations[key]->play(dt);
	}

	return animations[key]->isDone();
}

const bool& AnimationController::play(const std::string & key, const float dt, const float modifier, const float modifier_max, const bool priority)
{
	if (priority)
		priorityAnimation = animations[key];

	if (priorityAnimation)
	{
		if (priorityAnimation == animations[key])
		{
			if (lastAnimation != animations[key])
			{
				if (lastAnimation == nullptr)
					lastAnimation = animations[key];
				else
				{
					lastAnimation->reset();
					lastAnimation = animations[key];
				}
			}
			if (animations[key]->play(dt))
			{
				priorityAnimation = nullptr;
			}
		}
	}
	else
	{
		if (lastAnimation != animations[key])
		{
			if (lastAnimation == nullptr)
				lastAnimation = animations[key];
			else
			{
				lastAnimation->reset();
				lastAnimation = animations[key];
			}
		}
		animations[key]->play(dt, abs(modifier / modifier_max));
	}

	return animations[key]->isDone();
}

const bool & AnimationController::isDone(const std::string & key)
{
	return animations[key]->isDone();
}
