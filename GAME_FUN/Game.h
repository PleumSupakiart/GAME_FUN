#pragma once

#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include<ctime>
#include<sstream>

#include "Platform.h"
#include"Player.h"


using namespace std;
using namespace sf;

class Game
{
private:
	RenderWindow* window;
	VideoMode videomode;
	Event ev;

	bool endGame;
	int health;

	Player* player = new Player(&wall);

public:
	vector<Platform*> wall;
	Game();
	virtual ~Game();
	void initVariables();
	void innitWindow();
	const bool running() const;
	const bool getEndGame() const;
	void pollEvent();
	void update();
	void render();
};

