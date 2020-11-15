#include "Player.h"
#include"Collider.h"
#include"Platform.h"

void Player::initVariables()
{
	this->movementSpeed = 10.f;
	this->preWidth = 8.f;
	this->preHeight = 6.f;
	this->width = 30.f;
	this->height = 40.f;
	this->moving = false;
	this->standNum = 1;
	this->moveNum = 1;
	this->turnLeft = false;
}

void Player::initSprite()
{
	if (!this->texture.loadFromFile("sprite/marco.png"))
	{
		cout << "ERROR" << "\n";
	}
	this->currentFrame = IntRect(this->preWidth, this->preHeight, this->width, this->height);
	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.scale(2.f, 2.f);
	this->sprite.setPosition(0.f, 0.f);
	
}

void Player::initAnimetion()
{
	this->aniTime.restart();
}

Player::Player()
{
	this->initVariables();
	this->initSprite();
	this->initAnimetion();
	//Hitbox.setSize({ 32.f,32.f });
	//Hitbox.setOrigin({16.f,16.f});
}

Player::~Player()
{
}

void Player::playerplatform()
{
	
}



void Player::updateInput()
{
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		this->sprite.move(-this->movementSpeed, 0.f);
		this->moving = true;
		this->turnLeft = true;

		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			this->sprite.move(0.f, -this->movementSpeed);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S))
		{
			this->sprite.move(0.f, this->movementSpeed);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		this->sprite.move(this->movementSpeed, 0.f);
		this->moving = true;
		this->turnLeft = false;
		
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			this->sprite.move(0.f, -this->movementSpeed);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S))
		{
			this->sprite.move(0.f, this->movementSpeed);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::W))
	{
		this->sprite.move(0.f, -this->movementSpeed);
		this->moving = true;
		
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		this->sprite.move(0.f, this->movementSpeed);
		this->moving = true;
		
	}
	else
	{
		this->moving = false;
	}
}

void Player::updateAnimation()
{
	if (this->standNum >= 4)
	{
		this->standNum = 1;
	}
	if (this->moveNum >= 10)
	{
		this->moveNum = 1;
	}
	if (this->aniTime.getElapsedTime().asSeconds() >= 0.1f)
	{

		if (this->moving == false)
		{
			this->moveNum = 1;
			this->preHeight = 6.f;
			this->width = 32.f;
			switch (this->standNum)
			{
			case 1: this->preWidth = 52.f;
				break;
			case 2: this->preWidth = 97.f;
				break;
			case 3: this->preWidth = 7.f;
				break;

			}
			
			this->standNum++;
		}
		else if (this->moving == true)
		{
			this->standNum = 3;
			this->preHeight = 49.f;
			this->width = 37.f;
			switch (this->moveNum)
			{
			case 1: this->preWidth = 5.f;
				break;
			case 2: this->preWidth = 52.f;
				break;
			case 3: this->preWidth = 97.f;
				break;
			case 4: this->preWidth = 140.f;
				break;
			case 5: this->preWidth = 187.f;
				break;
			case 6: this->preWidth = 232.f;
				break;
			case 7: this->preWidth = 278.f;
				break;
			case 8: this->preWidth = 318.f;
				break;
			case 9: this->preWidth = 366.f;
				break;

			}
			
			this->moveNum++;
		}
		if (this->turnLeft == false)
		{
			this->currentFrame = IntRect(this->preWidth, this->preHeight, this->width, this->height);
		}
		else if (this->turnLeft == true)
		{
			this->currentFrame = IntRect(this->preWidth + this->width, this->preHeight, -this->width, this->height);
		}
		
		this->sprite.setTextureRect(this->currentFrame);
		this->aniTime.restart();
	}
}

void Player::update(RenderTarget* target)
{
	this->updateInput();
	this->updateAnimation();
}

void Player::render(RenderTarget* target)
{
	target->draw(this->sprite);
}
