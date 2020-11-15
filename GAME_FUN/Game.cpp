#include "Game.h"
#include "Player.h"
#include "Platform.h"
#include"Collider.h"

void Game::initVariables()
{
	this->window = nullptr;
	this->endGame = false;

	this->health = 10;
}

void Game::innitWindow()
{
	this->videomode.width = 1520;
	this->videomode.height = 720;
	
	this->window = new RenderWindow(this->videomode, "TT", Style::Titlebar | Style::Close);

	this->window->setFramerateLimit(60);
}

void Game::platform()
{
	vector<Platform> platforms;
	//platforms.push_back(Platform(nullptr, Vector2f(500.f, 100.f), Vector2f(100.f, 600.f)));
	platforms.push_back(Platform(nullptr, Vector2f(100.f, 700.f), Vector2f(800.f, 300.f)));

	for (Platform& platform : platforms)
		{
			platform.draw(*this->window);
		}
	Vector2f direction;

	for (Platform& platform : platforms)
	{
		
		//if (platform.GetCollider().CheckCollision(player.GetCollider(),1.0f));
		//printf("%f %f\n", player.collider.GetPosition().x, player.collider.GetPosition().y);

	}
		
	
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
		this->player.update(this->window);
	}

	if (this->health <= 0)
	{
		this->endGame = true;
	}
}

void Game::render()
{
	this->window->clear(Color(150, 150, 150));
	this->platform();
	
	this->player.render(this->window);
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
}
