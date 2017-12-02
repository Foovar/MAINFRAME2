//
//  CreditsState.cpp
//  PROYECTO
//
//  Created by Alex Paredes on 2/12/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#include "CreditsState.hpp"
#include "iostream"

namespace DevJAD {
    
    CreditsState::CreditsState(GameDataRef data){
        this->data = data;
    }
    
    void CreditsState::Init(){
        this->text.setFont(this->data->assets.GetFont("credits"));
        this->text.setFillColor(sf::Color(255, 255, 255));
        this->text.setString("Paredes Enriquez Alex.");
    }
    
    void CreditsState::HandleInput(){
        sf::Event event;
        
        while (this->data->window.pollEvent(event)) {
            if(sf::Event::Closed == event.type) this->data->window.close();
        }
    }
    
    void CreditsState::Update(float dt){
        
    }
    
    void CreditsState::Draw(float dt){
        this->data->window.clear(sf::Color::Black);
        this->data->window.draw(this->text);
        this->data->window.display();
    }
    
}
