#include "FinalState.hpp"
namespace DevJAD {
	FinalState::FinalState(GameDataRef data){
		this->data = data;
	}
	void FinalState::Init(){
		this->marioSprite = new MarioCharacter(this->data);
		this->marioSprite->SetDefaultState(CHARACTER_STATE_WALK);

		this->princesaSprite = new princessCharacter(this->data);
		this->princesaSprite->SetDefaultState(CHARACTER__PRINCESS_STATE_RUNING);

		this->data->assets.LoadTexture("fs background", FS_BACKGROUND_FILEPATH);
		this->spriteBackground.setTexture(this->data->assets.GetTexture("fs background"));
		
		if (this->data->screenType == SCREEN_SIZE_TYPE_MEDIUM) {
			this->spriteBackground.setScale(0.2, 0.3);
		}
	}
	void FinalState::HandleInput(){
		sf::Event event;
		while (this->data->window.pollEvent(event)) {
			if (event.type = sf::Event::Closed) this->data->window.close();
		}
	}
	void FinalState::Update(float dt) {
		this->marioSprite->Animate(dt);
		this->marioSprite->Update(dt);
		
		this->princesaSprite->Animate(dt);
		this->princesaSprite->Update(dt);
	}
	void FinalState::Draw(float dt){
		this->data->window.clear(sf::Color::White);
		this->data->window.draw(this->spriteBackground);
		this->marioSprite->Draw();
		this->princesaSprite->Draw();
		this->data->window.display();
	}
}