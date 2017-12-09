//
//  StoneEntity.cpp
//  PROYECTO
//
//  Created by Alex Paredes on 8/12/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#include "StoneEntity.hpp"

namespace DevJAD {
    StoneEntity::StoneEntity(GameDataRef _data) {
        this->data = _data;
        this->totalFrames = 7;
        this->frameInterator = 0;
        this->switchTime = 0.1f;
        
        this->data->assets.LoadTexture("mt_rock", MT_ROCK_FILEPATH);
        
        this->StoneSprite.setTexture(this->data->assets.GetTexture("mt_rock"));
        
        this->data->assets.GetTexture("mt_rock").setSmooth(true);
        
        if (this->data->screenType == SCREEN_SIZE_TYPE_MEDIUM) {
            this->StoneSprite.setScale(0.7f, 0.7f);
        }
        this->StoneSprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
        /*this->StoneSprite.setPosition(this->data->window.getSize().x - StoneSprite.getGlobalBounds().width/7, this->data->window.getSize().y - StoneSprite.getGlobalBounds().height);*/
        
        
    }
    void StoneEntity::Animate(float dt) {
        if (this->clock.getElapsedTime().asSeconds() > this->switchTime) {
            this->StoneSprite.setTextureRect(sf::IntRect(this->frameInterator * 100, 0, 100, 90));
            if (this->frameInterator >= this->totalFrames-1) {
                this->frameInterator = 0;
            }else this->frameInterator++;
            this->clock.restart();
        }
    }
    
    void StoneEntity::Update(float dt) {
        
    }
    
    void StoneEntity::Draw() {
        this->data->window.draw(StoneSprite);
        
    }
    void StoneEntity::Move(float x,float y) {
        this->StoneSprite.move(x, y);
        
    }
    void StoneEntity::setPosition(float x, float y) {
        this->StoneSprite.setPosition(x, y);
    }
    const sf::Sprite &StoneEntity::GetSprite() const {
        return this->StoneSprite;
    }
}

