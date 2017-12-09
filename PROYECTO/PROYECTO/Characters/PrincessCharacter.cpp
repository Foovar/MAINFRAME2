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
			this->spriteCharacter.setTextureRect(sf::IntRect((this->frameInterator * 125) + this->framePosX, this->framePosY, 125, 139));
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
			case CHARACTER__PRINCESS_STATE_RUNING:
				this->framePosY = 0;
				this->totalFrames = 13;
				this->switchTime = 0.08;
				break;
			case CHARACTER__PRINCESS_STATE_SLEEP:
				this->framePosY = 140;
				this->totalFrames = 6;
				this->switchTime = 0.08;
				break;
			}
			this->spriteCharacter.setPosition(this->data->window.getSize().x - this->spriteCharacter.getGlobalBounds().width, this->data->window.getSize().y - this->spriteCharacter.getGlobalBounds().height*2.5);

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