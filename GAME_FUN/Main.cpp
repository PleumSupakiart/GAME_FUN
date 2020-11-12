#include<iostream>
#include "Game.h"

int main()
{
	Game game;
	while (game.running() && !game.getEndGame())
	{
		game.update();
		game.render();
	}
	return 0;
}