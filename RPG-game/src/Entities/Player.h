#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(float x, float y, sf::Texture& textureSheet);
	virtual ~Player();

	virtual void update(const float dt) override;

private:
	void initComponets();
	void initVariables();

	bool attacking;
};

