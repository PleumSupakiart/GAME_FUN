#pragma once
#include<SFML/Graphics.hpp>
class Platform
{
private:
	sf::RectangleShape shape;
public:
	Platform(float x, float y, float width, float height);
	virtual ~Platform();

	sf::RectangleShape getShape() const;
};

