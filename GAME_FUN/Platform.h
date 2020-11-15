#pragma once
#include<SFML/Graphics.hpp>
#include"Collider.h"
using namespace std;
using namespace sf;

class Platform
{
public:
	Platform();
	Platform(Texture* texture,Vector2f size,Vector2f position);
	~Platform();

	void draw(RenderWindow& window);

	Collider GetCollider() {
		return Collider(body);
	}
private:
	RectangleShape body;

};

