#pragma once
#include "Entity.h"

class Skeleton : public Entity
{
public:
	Skeleton(float x, float y, sf::Texture& textureSheet);
	virtual ~Skeleton();

	virtual void update(const float dt) override;

private:
	void updateAnimations(const float dt);

	bool attacking;
};

