#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(float x, float y, sf::Texture& textureSheet);
	virtual ~Player();

	virtual void update(const float dt) override;

	void setAttack();

private:
	void initComponets(sf::Texture& textureSheet);
	void initVariables();

	void updateAnimations(const float dt);

	bool attacking;
};

