//
//  FinalState.cpp
//  PROYECTO
//
//  Created by Alex Paredes on 9/12/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#include "FinalState.hpp"

namespace DevJAD {
    FinalState::FinalState(GameDataRef data, int score){
        this->data = data;
    }
    void FinalState::Init(){
        
        this->is_SetPosition = true;
        
        this->background.setTexture(this->data->assets.GetTexture("final background"));
        
        this->marioSprite = new MarioCharacter(this->data);
        
        this->marioSprite->SetDefaultState(CHARACTER_STATE_WALK);
        
        if (this->data->screenType == SCREEN_SIZE_TYPE_MEDIUM) {
            this->background.setScale(0.2, 0.3);
        }
    
    }
    void FinalState::HandleInput(){
        sf::Event event;
        while (this->data->window.pollEvent(event)) {
            if(sf::Event::Closed == event.type) this->data->window.close();
        }
    }
    void FinalState::Update(float dt){
        if(this->is_SetPosition){
            this->marioSprite->SetPosition(10,  this->data->window.getSize().y - 175);
            this->is_SetPosition = false;
        }
        
        
        
        if(this->marioSprite->GetPosition().x < 400){
            this->marioSprite->Move(CHARACTER_MOVE_RIGTH);
            this->marioSprite->Update(dt);
            this->marioSprite->Animate(dt);
        }else {
            this->marioSprite->SetState(CHARACTER_STATE_WALK);
            this->marioSprite->Animate(dt);
            
        };
        
    }
    void FinalState::Draw(float dt){
        this->data->window.clear(sf::Color::White);
        this->data->window.draw(this->background);
        this->marioSprite->Draw();
        this->data->window.display();
    }
}
