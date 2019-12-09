#pragma once
#include "Entity.h"
#include "Player.h"

class Enemy : public Entity
{
public:
	Enemy();
	Enemy(float x, float y, Player* target);
	virtual ~Enemy();

	virtual void update(const float dt) override;

protected:
	bool attacking;
	Player* target;
};

