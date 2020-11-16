#include "Platform.h"

Platform::Platform(float x, float y, float width, float height)
{
	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	this->shape.setFillColor(sf::Color::Transparent);
	this->shape.setOutlineColor(sf::Color::Green);
	this->shape.setOutlineThickness(1.f);
}

Platform::~Platform()
{
}

sf::RectangleShape Platform::getShape() const
{
	return this->shape;
}
