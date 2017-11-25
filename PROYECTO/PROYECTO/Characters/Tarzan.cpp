//
//  Tarzan.cpp
//  PROYECTO
//
//  Created by Alex Paredes on 3/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#include "Tarzan.hpp"

namespace DevJAD {
    Tarzan::Tarzan(GameDataRef _data): data(_data){
        this->tarzanTexture = this->data->assets.GetTexture("character 01");
        this->tarzanTexture.setSmooth(true);
        this->tarzanSprite.setTexture(this->tarzanTexture);
        this->tarzanSprite.setTextureRect(sf::IntRect(0,0, 56, 32));
        //this->tarzanSprite.setScale(180 / 56, 150 / 32);
        this->tarzanSprite.setPosition(100, this->data->window.getSize().y - this->tarzanSprite.getGlobalBounds().height * 2);
        
        
        this->state = IS_SWIMMING;
        framesInterator = 0;
        this->movementX = 0;
        this->movementY = 0;
    }
    
    void Tarzan::Draw(){
        this->data->window.draw(this->tarzanSprite);
    }
    
    void Tarzan::Animate(float dt){
        
        if(this->clock.getElapsedTime().asSeconds() > 0.1f){
            if(framesInterator > 6){
                framesInterator = 0;
            }else{
                framesInterator++;
            }
            
            this->tarzanSprite.setTextureRect(sf::IntRect(framesInterator * 56, 0, 56, 32));
            this->clock.restart();
        }
    }
    
    const sf::Sprite &Tarzan::GetSprite() const{
        return this->tarzanSprite;
    }
    
    void Tarzan::Update(float dt){
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
        
        if(this->tarzanSprite.getPosition().x < 0){
            
        }
        
        this->tarzanSprite.setPosition(this->data->window.getView().getCenter().x+ this->movementX, (this->data->window.getSize().y - this->data->window.getSize().y/4) + this->movementY );
        
    }
    
    int Tarzan::GetState(){
        return this->state;
    }
    
    void Tarzan::SetState(int _state){
        this->state = _state;
    }
}
