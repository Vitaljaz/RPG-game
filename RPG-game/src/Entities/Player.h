#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(float x, float y, sf::Texture& textureSheet);
	virtual ~Player();

private:
	void initComponets();
	void initVariables();
};

