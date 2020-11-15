#pragma once

#include<iostream>
#include<vector>
#include<ctime>
#include<sstream>

#include"Player.h"
#include"Platform.h"


//using namespace std;
using namespace sf;

class Game
{
private:
	RenderWindow* window;
	VideoMode videomode;
	Event ev;

	bool endGame;
	int health;
	Player player;

	

public:
	Game();
	virtual ~Game();
	void initVariables();
	void innitWindow();
	void platform();
	const bool running() const;
	const bool getEndGame() const;
	void pollEvent();
	void update();
	void render();
};

