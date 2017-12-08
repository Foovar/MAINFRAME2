#include "MountainGameState.hpp"
#include <iostream>
#include "../GameEntities/StoneEntity.hpp"
namespace DevJAD {

	MountainGameState::MountainGameState(GameDataRef data) {
		this->data = data;
		this->viewScreen = sf::View(this->data->window.getDefaultView());
		this->gameState = IS_PLAYING;
	}
	void MountainGameState::Init() {
		this->data->assets.LoadTexture("character 02", GAME_CHARACTER02_PATH);
		this->spritebackground.setTexture(this->data->assets.GetTexture("mt background"));
		this->spriteColine.setTexture(this->data->assets.GetTexture("mt coline"));
		this->data->assets.GetTexture("mt coline").setSmooth(true);
		this->data->assets.GetTexture("mt background").setSmooth(true);

		this->musicBackground.openFromFile(MT_MUSIC_BACKGROUND);

		this->marioCharacter = new MarioCharacter(this->data);
		this->marioCharacter->SetDefaultState(CHARACTER_STATE_WALK);

		this->stoneEntity = new StoneEntity(this->data);

		if (this->data->screenType == SCREEN_SIZE_TYPE_MEDIUM) {
			this->spritebackground.setScale(0.2, 0.3);
			this->spriteColine.setScale(0.5,0.5);
		}
	
		this->spriteColine.setPosition(this->data->window.getSize().x- this->spriteColine.getGlobalBounds().width, this->data->window.getSize().y- this->spriteColine.getGlobalBounds().height/2);
		this->musicBackground.setVolume(50.f);
		this->musicBackground.play();
		this->shape.setFillColor(sf::Color(255, 214,165));

		this->shape.setRadius(40);
		this->shape.setPosition(10, 10);
	}
	void MountainGameState::HandleInput() {
		sf::Event event;

		while (this->data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) this->data->window.close();
			
			if (sf::Event::KeyPressed == event.type || sf::Event::KeyReleased == event.type) {

				if (event.key.code == sf::Keyboard::X) {
					this->marioCharacter->SetState(CHARACTER_STATE_ATTACK);
				}
				if (event.key.code == sf::Keyboard::Space) {
					this->marioCharacter->SetState(CHARACTER_STATE_JUMPING);
					//this->marioCharacter->Move(CHARACTER_MOVE_JUMP);
				}
			}
		}
	}
	void MountainGameState::Update(float dt) {
		if (this->marioCharacter->GetState() != CHARACTER_STATE_DEAD) {
			this->marioCharacter->Update(dt);
			this->marioCharacter->Animate(dt);
		}
		
		this->shape.setPosition(shape.getPosition().x+ (0.1 *dt), shape.getPosition().y + (0.1*dt));

		this->stoneEntity->Animate(dt);
		this->stoneEntity->Update(dt);

	}
	void MountainGameState::Draw(float dt) {
		this->data->window.clear(sf::Color::White);
		this->data->window.setView(this->viewScreen);
		this->data->window.draw(spritebackground);
		this->data->window.draw(shape);
		this->data->window.draw(this->spriteColine);
		this->marioCharacter->Draw();
		this->stoneEntity->Draw();
		this->data->window.display();
	}

}