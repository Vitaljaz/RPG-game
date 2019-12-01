#include "MovementController.h"

MovementController::MovementController(sf::Sprite& sprite, float maxVelocity,
	float acceleration, float deceleration) :
	sprite(sprite), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration) {}


MovementController::~MovementController()
{
}

void MovementController::move(const float dir_x, const float dir_y, const float dt)
{
	velocity.x += acceleration * dir_x;

	velocity.y += acceleration * dir_y;
}

void MovementController::update(const float dt)
{
	if (velocity.x > 0.f)
	{
		if (velocity.x > maxVelocity)
			velocity.x = maxVelocity;

		velocity.x -= deceleration;
		if (velocity.x < 0.f)
			velocity.x = 0.f;
	}
	else if (velocity.x < 0.f)
	{
		if (velocity.x < -maxVelocity)
			velocity.x = -maxVelocity;

		velocity.x += deceleration;
		if (velocity.x > 0.f)
			velocity.x = 0.f;
	}

	if (velocity.y > 0.f)
	{
		if (velocity.y > maxVelocity)
			velocity.y = maxVelocity;

		velocity.y -= deceleration;
		if (velocity.y < 0.f)
			velocity.y = 0.f;
	}
	else if (velocity.y < 0.f)
	{
		if (velocity.y < -maxVelocity)
			velocity.y = -maxVelocity;

		velocity.y += deceleration;
		if (velocity.y > 0.f)
			velocity.y = 0.f;
	}

	sprite.move(velocity * dt);
}

const bool MovementController::idle() const
{
	if (velocity.x == 0.f && velocity.y == 0.f)
		return true;

	return false;
}

const bool MovementController::movingRight() const
{
	if (velocity.x > 0.f)
		return true;

	return false;
}

const bool MovementController::movingLeft() const
{
	if (velocity.x < 0.f)
		return true;

	return false;
}

const bool MovementController::moving() const
{
	if (velocity.x != 0.f || velocity.y != 0.f)
		return true;

	return false;
}

const float MovementController::getMaxVelocity() const
{
	return maxVelocity;
}

const sf::Vector2f & MovementController::getVelocity() const
{
	return velocity;
}
