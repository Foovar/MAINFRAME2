//
//  WinState.cpp
//  PROYECTO
//
//  Created by Alex Paredes on 2/12/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#include "WinState.hpp"

namespace DevJAD {
    
    WinState::WinState(GameDataRef data){
        this->data = data;
    }
    
    void WinState::Init(){
        this->winCharacter.setTexture(this->data->assets.GetTexture("character 02"));
        this->winText.setTexture(this->data->assets.GetTexture("you win"));
        
        this->winCharacter.setTextureRect(sf::IntRect(0, 715, 110, 90));
        this->winCharacter.setPosition(this->data->window.getView().getCenter().x - this->winCharacter.getGlobalBounds().width / 2, this->data->window.getView().getCenter().y - this->winCharacter.getGlobalBounds().height / 2);
        
        this->winText.setPosition(this->data->window.getView().getCenter().x - this->winText.getGlobalBounds().width / 2, this->data->window.getView().getCenter().y - this->winText.getGlobalBounds().height);
        
        
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
        this->data->window.display();
    }
    
}
