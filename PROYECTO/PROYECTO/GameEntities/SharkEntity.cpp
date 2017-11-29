//
//  SharkEntity.cpp
//  PROYECTO
//
//  Created by Alex Paredes on 8/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#include "SharkEntity.hpp"

namespace DevJAD {
    SharkEntity::SharkEntity(sf::Texture &texture, sf::Vector2f scale){
        this->entityState = SHARK_SWIMMING;
        this->frameInterator = 0;
        texture.setSmooth(true);
        this->swimming = new AnimationEntityData(sf::Sprite(texture), sf::IntRect(0,0,143.f,95.f), 15, scale);
        this->attack = new AnimationEntityData(sf::Sprite(texture), sf::IntRect(0,95.f,143.f,100.f), 4, scale);
        this->die = new AnimationEntityData(sf::Sprite(texture), sf::IntRect(0,95.f + 100.f, 143.f, 100.f), 9, scale);
    }
    
    void SharkEntity::SetState(int state){
        this->entityState = state;
    }
    
    void SharkEntity::Update(float dt){
        switchTime = this->GetCurrentAnimationData()->switchTime;
    }
    
    void SharkEntity::Animate(float dt){
        if(clock.getElapsedTime().asSeconds() >= switchTime){
            
            if(frameInterator > this->GetCurrentAnimationData()->totalFrames - 2){
                frameInterator = 0;
            }else frameInterator++;
            
            this->entityRect.width = this->GetCurrentAnimationData()->sizes.width;
            this->entityRect.height = this->GetCurrentAnimationData()->sizes.height;
            this->entityRect.top = this->GetCurrentAnimationData()->sizes.top;
            this->entityRect.left = this->GetCurrentAnimationData()->sizes.left + (this->frameInterator * this->entityRect.width);
            this->entitySprite = this->GetCurrentAnimationData()->sprite;
            this->entitySprite.setTextureRect(this->entityRect);
            if(SHARK_DIE != this->entityState)
                this->entitySprite.move(0, cos(this->clockSin.getElapsedTime().asSeconds()) * 17);
            else{
                this->die->sprite.move(0, -(dt * 220.0));
            }
            clock.restart();
        }
    }
    
    void SharkEntity::Move(float x, float y){
        this->attack->sprite.move(x, y);
        this->swimming->sprite.move(x, y);
        this->die->sprite.move(x, y);
    }
    
    void SharkEntity::SetPosition(float x, float y){
        //this->GetCurrentAnimationData()->sprite.setPosition(x, y);
        this->attack->sprite.setPosition(x, y);
        this->swimming->sprite.setPosition(x, y);
        this->die->sprite.setPosition(x, y);
    }
    
    AnimationEntityData * SharkEntity::GetCurrentAnimationData() {
        return SHARK_SWIMMING == this->entityState ? this->swimming : SHARK_DIE == this->entityState ? this->die : this->attack;
    }
    int SharkEntity::GetState(){
        return this->entityState;
    }
    const sf::Sprite &SharkEntity::GetSprite() const {
        return this->entitySprite;
    }
}
