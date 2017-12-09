#include "FinalState.hpp"
#include <iostream>
namespace DevJAD {
	FinalState::FinalState(GameDataRef data){
		this->data = data;
	}
	void FinalState::Init(){
		this->marioSprite = new MarioCharacter(this->data);
		this->marioSprite->SetDefaultState(CHARACTER_STATE_WALK);
		this->marioSprite->SetPosition(10, (this->data->window.getSize().y - this->marioSprite->GetSprite().getGlobalBounds().height * 2.40));

		this->princesaSprite = new princessCharacter(this->data);
		this->princesaSprite->SetDefaultState(CHARACTER__PRINCESS_STATE_SLEEP);

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
		this->marioSprite->Update(dt);
		this->marioSprite->Animate(dt);
		
		this->princesaSprite->Update(dt);
		this->princesaSprite->Animate(dt);

			
		if (this->marioSprite->GetPosition().x < this->data->window.getSize().x / 2) {
			std::cout << "POS X: " << marioSprite->GetPosition().x  << " \t POS Y: " << this->marioSprite->GetPosition().y  <<" \t Tamanio X: "<< this->data->window.getSize().x / 2 << std::endl;
			marioSprite->Move(CHARACTER_MOVE_RIGTH);
			this->marioSprite->SetPosition(marioSprite->GetPosition().x, (this->data->window.getSize().y - this->marioSprite->GetSprite().getGlobalBounds().height * 2.40));
		}
		else {
			marioSprite->SetState(CHARACTER_STATE_STAND);
			marioSprite->Move(CHARACTER_STAND);
			if (this->princesaSprite->GetPosition().x > (this->data->window.getSize().x / 2 ) + 100) {
				princesaSprite->SetState(CHARACTER__PRINCESS_STATE_RUNING);
				princesaSprite->Move(CHARACTER_MOVE_LEFT);
			}else {
				princesaSprite->SetState(CHARACTER__PRINCESS_STATE_STAND);
				princesaSprite->Move(CHARACTER_STAND);
			}
			
		}
	}	
	void FinalState::Draw(float dt){
		this->data->window.clear(sf::Color::White);
		this->data->window.draw(this->spriteBackground);
		this->marioSprite->Draw();
		this->princesaSprite->Draw();


		this->data->window.display();
	}
}