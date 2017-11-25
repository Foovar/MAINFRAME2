//
//  FakeMario.cpp
//  PROYECTO
//
//  Created by Alex Paredes on 25/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#include "FakeMario.hpp"

namespace DevJAD {
    FakeMario::FakeMario(GameDataRef _data): data(_data){
        this->fakeMarioTexture = this->data->assets.GetTexture("character 02");
        this->fakeMarioTexture.setSmooth(true);
        this->fakeMarioSprite.setTexture(this->fakeMarioTexture);
        this->fakeMarioSprite.setTextureRect(sf::IntRect(0,0, 110, 85));
        //this->tarzanSprite.setScale(180 / 56, 150 / 32);
        if(this->data->screenType == SCREEN_SIZE_TYPE_MEDIUM)
            this->fakeMarioSprite.setScale(0.5, 0.5);
        this->fakeMarioSprite.setPosition(100, this->data->window.getSize().y - this->fakeMarioSprite.getGlobalBounds().height * 2);
        
        
        this->state = IS_SWIMMING;
        framesInterator = 0;
        this->movementX = 0;
        this->movementY = 0;
    }
    
    void FakeMario::Draw(){
        this->data->window.draw(this->fakeMarioSprite);
    }
    
    void FakeMario::Animate(float dt){
        
        if(this->clock.getElapsedTime().asSeconds() > 0.1f){
            if(framesInterator > 10){
                framesInterator = 0;
            }else{
                framesInterator++;
            }
            
            this->fakeMarioSprite.setTextureRect(sf::IntRect(framesInterator * 110, 0, 110, 85));
            this->clock.restart();
        }
    }
    
    const sf::Sprite &FakeMario::GetSprite() const{
        return this->fakeMarioSprite;
    }
    
    void FakeMario::Update(float dt){
        int speed = 850 * dt;
        if(IS_SWIMMING != this->state){
            switch (this->state) {
                case GAME_MOVE_TO_UP:
                    this->movementY -=  speed;
                    break;
                case GAME_MOVE_TO_DOWN:
                    this->movementY += speed;
                    break;
                case GAME_MOVE_TO_LEFT:
                    this->movementX -= speed;
                    break;
                case GAME_MOVE_TO_RIGTH:
                    this->movementX += speed;
                    break;
            }
            this->state = IS_SWIMMING;
        }
        
        if(this->fakeMarioSprite.getPosition().x < 0){
            
        }
        
        this->fakeMarioSprite.setPosition(this->data->window.getView().getCenter().x+ this->movementX, (this->data->window.getSize().y - this->data->window.getSize().y/4) + this->movementY );
        
    }
    
    int FakeMario::GetState(){
        return this->state;
    }
    
    void FakeMario::SetState(int _state){
        this->state = _state;
    }
}
