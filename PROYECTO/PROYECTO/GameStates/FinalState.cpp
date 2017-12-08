#include "FinalState.hpp"
namespace DevJAD {
	FinalState::FinalState(GameDataRef data){
		this->data = data;
	}
	void FinalState::Init(){
		this->marioSprite = new MarioCharacter(this->data);
		this->data->assets.GetTexture("");
	}
	void FinalState::HandleInput(){
		sf::Event event;
		while (this->data->window.pollEvent(event)) {
			if (event.type = sf::Event::Closed) this->data->window.close();
		}

	}
	void FinalState::Update(float dt) {

	}
	void FinalState::Draw(float dt){
		this->data->window.clear(sf::Color::White);
		this->marioSprite->Draw();
	}
}