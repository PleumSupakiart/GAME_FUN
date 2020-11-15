#include "Platform.h"

Platform::Platform()
{
}

Platform::Platform(Texture* texture, Vector2f size, Vector2f position)
{
	body.setSize(size);
	body.setOrigin(size / 2.f);
	body.setPosition(position);
	body.setTexture(texture);
}

Platform::~Platform()
{
}

void Platform::draw(RenderWindow& window)
{
	window.draw(body);
}