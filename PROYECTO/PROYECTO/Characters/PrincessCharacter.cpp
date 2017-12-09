#include "PrincessCharacter.hpp"
#include <iostream>
namespace DevJAD {
	princessCharacter::princessCharacter(GameDataRef data) {
		this->data = data;
		this->data->assets.LoadTexture("fs princess", "Assets/images/character03.png");
		this->data->assets.GetTexture("fs princess").setSmooth(true);
		this->spriteCharacter.setTexture(this->data->assets.GetTexture("fs princess"));
		this->frameInterator = 0;
		this->movementX = 0;
		this->switchTime = 0.0;
		this->framePosX = 0;
		if (this->data->screenType == SCREEN_SIZE_TYPE_MEDIUM) {
			this->spriteCharacter.setScale(0.5, 0.5);
		}
	}
	void princessCharacter::Animate(float dt) {
		if (this->clock.getElapsedTime().asSeconds() > this->switchTime) {
			if (CHARACTER__PRINCESS_STATE_SLEEP == this->characterStatus) {
				this->spriteCharacter.setTextureRect(sf::IntRect((this->frameInterator * 190) + this->framePosX, this->framePosY, 190, 80));
			}
			else if (CHARACTER__PRINCESS_STATE_RUNING == this->characterStatus) {
				this->spriteCharacter.setTextureRect(sf::IntRect((this->frameInterator * 125) + this->framePosX, this->framePosY, 125, 139));
			}
			else if (CHARACTER__PRINCESS_STATE_STAND == this->characterStatus) {
				this->spriteCharacter.setTextureRect(sf::IntRect((this->frameInterator * 86) + this->framePosX, this->framePosY, 86, 148));
			}

			if (this->frameInterator >= this->totalFrames - 1) {
				this->frameInterator = 0;
			}
			else this->frameInterator++;

			this->clock.restart();
		}

	}
	void princessCharacter::SetDefaultState(int state) {
			this->characterStatus = state;
	}
	void princessCharacter::Draw() {
		this->data->window.draw(this->spriteCharacter);
	}
	void princessCharacter::Update(float dt) {

			switch (this->characterStatus) {
			case CHARACTER__PRINCESS_STATE_STAND:
				this->framePosY = 248;
				this->totalFrames = 9;
				this->switchTime = 0.2;
				break;
			case CHARACTER__PRINCESS_STATE_RUNING:
				this->framePosY = 0;
				this->totalFrames = 13;
				this->switchTime = 0.08;
				break;
			case CHARACTER__PRINCESS_STATE_SLEEP:
				this->framePosY = 146;
				this->totalFrames = 6;
				this->switchTime = 0.08;
				break;
			}

			switch (this->moveType) {
			case CHARACTER_MOVE_LEFT:
				this->spriteCharacter.move(-(dt * CHARACTER_MOVE_SPEED), 0);
				this->movementX -= dt * CHARACTER_MOVE_SPEED;
				break;
			case CHARACTER_STAND:
				this->spriteCharacter.move((dt * 0), 0);
				this->movementX += dt * 0;
				break;
			}if (CHARACTER__PRINCESS_STATE_RUNING == characterStatus) {
				this->spriteCharacter.setPosition ( (this->data->window.getSize().x - this->spriteCharacter.getGlobalBounds().width) + movementX, this->data->window.getSize().y - this->spriteCharacter.getGlobalBounds().height*2.4);
			}
			else if (CHARACTER__PRINCESS_STATE_SLEEP == characterStatus) {
				this->spriteCharacter.setPosition((this->data->window.getSize().x - this->spriteCharacter.getGlobalBounds().width) + movementX, this->data->window.getSize().y - this->spriteCharacter.getGlobalBounds().height*3.5);
			}
			else if (CHARACTER__PRINCESS_STATE_STAND== characterStatus) {
				this->spriteCharacter.setPosition((this->data->window.getSize().x - this->spriteCharacter.getGlobalBounds().width) + movementX, this->data->window.getSize().y - this->spriteCharacter.getGlobalBounds().height*2.35);
			}
	}
	void princessCharacter::Move(int type) {
		if (this->characterStatus == CHARACTER_STATE_ATTACK) return;
		this->moveAmount = type == this->moveType ? this->moveAmount + 5 : 5;
		this->moveType = type;
	}
	void princessCharacter::SetState(int state) {
		this->characterStatus = state;
	}
	const sf::Sprite &princessCharacter::GetSprite() const {
		return this->spriteCharacter;
	}
	void princessCharacter::SetPosition(float x, float y) {
		this->spriteCharacter.setPosition(x, y);
	}
	sf::Vector2f princessCharacter::GetPosition() {
		return this->spriteCharacter.getPosition();
	}

}