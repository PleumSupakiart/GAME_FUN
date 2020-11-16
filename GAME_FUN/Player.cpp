#include "Player.h"
#include<string>

bool Player::isHit() {
	for (auto Wall : *wall) {
		if (this->hitBox.getGlobalBounds().intersects(Wall->getShape().getGlobalBounds())) {
			return true;
		}
	}
	return false;
}

Platform* Player::hitWith() {
	for (auto Wall : *wall) {
		if (this->hitBox.getGlobalBounds().intersects(Wall->getShape().getGlobalBounds())) {
			return Wall;
		}
	}
}

string Player::hitSide() {
	if (Player::isHit()) {
		if (Player::hitWith()->getShape().getGlobalBounds().contains(corner[0]) && Player::hitWith()->getShape().getGlobalBounds().contains(corner[1])) {
			return "Top";
		}
		else if (Player::hitWith()->getShape().getGlobalBounds().contains(corner[2]) && Player::hitWith()->getShape().getGlobalBounds().contains(corner[3])) {
			return "Bottom";
		}
		else if (Player::hitWith()->getShape().getGlobalBounds().contains(corner[0]) && Player::hitWith()->getShape().getGlobalBounds().contains(corner[2])) {
			return "Left";
		}
		else if (Player::hitWith()->getShape().getGlobalBounds().contains(corner[1]) && Player::hitWith()->getShape().getGlobalBounds().contains(corner[3])) {
			return "Right";
		}
	}
	else{
		return "None";
	}
}

void Player::initVariables()
{
	this->movementSpeed = 10.f;
	this->preWidth = 4.f;
	this->preHeight = 1.f;
	this->width = 30.f;
	this->height = 38.f;
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
	this->sprite.scale(3.f, 3.f);
	this->sprite.setPosition(0.f, 0.f);
	
}

void Player::initAnimetion()
{
	this->aniTime.restart();
}

Player::Player(vector<Platform*>* Wall)
{
	this->wall = Wall;
	this->initVariables();
	this->initSprite();
	this->initAnimetion();
	this->hitBox.setPosition(sf::Vector2f(this->sprite.getPosition()));
	this->hitBox.setSize(sf::Vector2f(90.f, 120.f));
	this->hitBox.setFillColor(sf::Color::Transparent);
	this->hitBox.setOutlineColor(sf::Color::Green);
	this->hitBox.setOutlineThickness(1.f);
}

Player::~Player()
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
			this->preHeight = 1.f;
			this->preWidth = 4.f;
			switch (this->standNum)
			{
			case 1: this->preWidth = 4.f;
				break;
			case 2: this->preWidth = 35.f;
				break;
			case 3: this->preWidth = 64.f;
				break;

			}
			
			this->standNum++;
		}
		else if (this->moving == true)
		{
			this->standNum = 3;
			this->preHeight = 1.f;
			this->preWidth = 103.f;
			switch (this->moveNum)
			{
			case 1: this->preWidth = 104.f;
				break;
			case 2: this->preWidth = 139.f;
				break;
			case 3: this->preWidth = 168.f;
				break;
			case 4: this->preWidth = 201.f;
				break;
			case 5: this->preWidth = 235.f;
				break;
			case 6: this->preWidth = 266.f;
				break;
			case 7: this->preWidth = 298.f;
				break;
			case 8: this->preWidth = 330.f;
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
	this->hitBox.setPosition(sf::Vector2f(this->sprite.getPosition()));
	this->corner[0] = this->hitBox.getPosition();
	this->corner[1] = { this->hitBox.getPosition().x, this->hitBox.getPosition().y + this->hitBox.getSize().y };
	this->corner[2] = { this->hitBox.getPosition().x + this->hitBox.getSize().x , this->hitBox.getPosition().y};
	this->corner[3] = { this->hitBox.getPosition().x + this->hitBox.getSize().x , this->hitBox.getPosition().y + this->hitBox.getSize().y };
	

}

void Player::render(RenderTarget* target)
{
	target->draw(this->sprite);
	target->draw(this->hitBox);
}
