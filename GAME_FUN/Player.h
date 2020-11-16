#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include "Platform.h"

#include<iostream>

using namespace std;
using namespace sf;


class Player
{
private:
	Sprite sprite;
	Texture texture;
	IntRect currentFrame;
	Clock aniTime;

	float width;
	float height;
	float preWidth;
	float preHeight;
	float movementSpeed;

	bool moving;
	bool turnLeft;
	int standNum;
	int moveNum;
	

	void initVariables();
	void initSprite();
	void initAnimetion();
	bool isHit();
	string hitSide();
	Platform* hitWith();


public:
	RectangleShape hitBox;
	vector<Platform*>* wall;
	sf::Vector2f corner[4];
	Player(vector<Platform*>* Wall);
	virtual ~Player();

	void updateInput();
	void updateAnimation();
	void update(RenderTarget* target);
	void render(RenderTarget* target);
};

