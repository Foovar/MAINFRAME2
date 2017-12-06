

#include "WinState.hpp"

namespace DevJAD {
    
    WinState::WinState(GameDataRef data, int score){
        this->data = data;
        this->score = score;
    }
    
    void WinState::Init(){
        this->winCharacter.setTexture(this->data->assets.GetTexture("character 02"));
        this->winText.setTexture(this->data->assets.GetTexture("you win"));
        this->finishMusic.openFromFile(FINISH_MUSIC);
        
        this->winCharacter.setTextureRect(sf::IntRect(0, 715, 110, 90));
        this->winCharacter.setPosition(this->data->window.getView().getCenter().x - this->winCharacter.getGlobalBounds().width / 2, this->data->window.getView().getCenter().y - this->winCharacter.getGlobalBounds().height / 2);
        
        this->winText.setPosition(this->data->window.getView().getCenter().x - this->winText.getGlobalBounds().width / 2, this->data->window.getView().getCenter().y - this->winText.getGlobalBounds().height);
        this->textScore.setFont(this->data->assets.GetFont("ka1"));
        this->textScore.setString("SCORE: "+ std::to_string(this->score));
        
        this->textScore.setPosition(this->winCharacter.getPosition().x - this->textScore.getGlobalBounds().width / 3, this->winCharacter.getPosition().y + this->winCharacter.getGlobalBounds().height + 100);
        
        this->finishMusic.play();
        this->frameInterator = 0;
    }
    
    void WinState::HandleInput(){
        sf::Event event;
        
        while (this->data->window.pollEvent(event)) {
            if(sf::Event::Closed == event.type) this->data->window.close();
        }
    }
    
    void WinState::Update(float dt){
        if(this->clock.getElapsedTime().asSeconds() > 0.1){
            this->winCharacter.setTextureRect(sf::IntRect( this->frameInterator * 110, 715, 110, 90 ));
            if(this->frameInterator > 6 - 2){
                this->frameInterator = 0;
            }else{
                this->frameInterator++;
            }
            this->clock.restart();
        }
    }
    
    void WinState::Draw(float dt){
        this->data->window.clear(sf::Color::Black);
        this->data->window.draw(this->winText);
        this->data->window.draw(this->winCharacter);
        this->data->window.draw(this->textScore);
        this->data->window.display();
    }
    
}
