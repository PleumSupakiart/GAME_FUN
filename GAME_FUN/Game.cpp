#include "Game.h"

void Game::initVariables()
{
	this->window = nullptr;
	this->endGame = false;

	this->health = 10;
	wall.push_back(new Platform(200, 000, 200, 200));
}

void Game::innitWindow()
{
	this->videomode.width = 1520;
	this->videomode.height = 720;
	
	this->window = new RenderWindow(this->videomode, "^^", Style::Titlebar | Style::Close);

	this->window->setFramerateLimit(60);
}

const bool Game::running() const
{
	return this->window->isOpen();
}

const bool Game::getEndGame() const
{
	return this->endGame;
}

void Game::pollEvent()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case Event::Closed:
			this->window->close();
			break;
		case Event::KeyPressed:
			if (this->ev.key.code == Keyboard::Escape)
			{
				this->window->close();
			}
			break;
		default:
			break;
		}
	}
}

void Game::update()
{
	this->pollEvent();
	if (this->endGame == false)
	{
		this->player->update(this->window);
	}

	if (this->health <= 0)
	{
		this->endGame = true;
	}
}

void Game::render()
{
	this->window->clear(Color(150,150,150));
	this->player->render(this->window);
	for (auto Wall : wall) {
		this->window->draw(Wall->getShape());
	}
	this->window->display();
}

Game::Game()
{
	this->initVariables();
	this->innitWindow();
	
}

Game::~Game()
{
	delete this->window;
	delete this->player;
	for (int i = 0; i < wall.size(); i++) {
		delete wall[i];
	}
}
