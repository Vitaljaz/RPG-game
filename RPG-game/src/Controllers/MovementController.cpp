#include "MovementController.h"

MovementController::MovementController(sf::Sprite& sprite, float maxVelocity) :
	sprite(sprite), maxVelocity(maxVelocity) {}


MovementController::~MovementController()
{
}

void MovementController::move(const float dir_x, const float dir_y, const float dt)
{
	velocity.x = maxVelocity * dir_x;
	velocity.y = maxVelocity * dir_y;

	sprite.move(velocity * dt);
}

void MovementController::update(const float dt)
{

}

const sf::Vector2f & MovementController::getVelocity() const
{
	return velocity;
}
