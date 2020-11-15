#include<iostream>
#include "Game.cpp"

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