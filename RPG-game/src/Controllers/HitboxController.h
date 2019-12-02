#pragma once

class HitboxController
{
public:
	HitboxController(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height);
	virtual ~HitboxController();

	bool checkCollision(const sf::FloatRect& frect);

	void update();
	void render(sf::RenderTarget* target);

private:
	sf::RectangleShape hitbox;
	sf::Sprite& sprite;

	float offsetX;
	float offsetY;
};

