#include "AnimationController.h"

AnimationController::AnimationController(sf::Sprite& sprite, sf::Texture& textureSheet) 
	: sprite(sprite), textureSheet(textureSheet) {}


AnimationController::~AnimationController()
{
}
