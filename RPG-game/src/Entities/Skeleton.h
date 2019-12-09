#pragma once
#include "Enemy.h"
#include "Player.h"

class Skeleton : public Enemy
{
public:
	Skeleton(float x, float y, sf::Texture& textureSheet, Player* target);
	virtual ~Skeleton();

	virtual void update(const float dt) override;

private:
	void updateAnimations(const float dt);

	void initComponets(sf::Texture& textureSheet);
	void initVariables(Player* target);

	bool attacking;
};

