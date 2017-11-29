//
//  MarioCharacter.cpp
//  PROYECTO
//
//  Created by Alex Paredes on 26/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#include "MarioCharacter.hpp"
#include "iostream"

namespace DevJAD {
    MarioCharacter::MarioCharacter(GameDataRef _data): data(_data) {
        this->characterStatus = CHARACTER_STATE_WALK;
        this->frameInterator = 0;
        this->movementX = 0;
        this->movementY = 0;
        this->switchTime = 0.08;
        sf::Texture * marioTexture = new sf::Texture(this->data->assets.GetTexture("character 02"));
        marioTexture->setSmooth(true);
        this->spriteCharacter.setTexture(*marioTexture);
        this->spriteCharacter.setTextureRect(sf::IntRect(0, 0, 0, 0));
        if(this->data->screenType == SCREEN_SIZE_TYPE_MEDIUM)
            this->spriteCharacter.setScale(0.7, 0.7);
        else
            this->spriteCharacter.setScale(1.3, 1.3);
        
        this->totalFrames = 12;
        this->attackCompleted = false;
        this->shotEntity = new ShotEntity(this->data);
    }
    
    void MarioCharacter::Draw(){
        this->data->window.draw(this->spriteCharacter);
        this->shotEntity->Draw();
    }
    
    void MarioCharacter::Move(int type){
        if(this->characterStatus == CHARACTER_STATE_ATTACK) return;
        this->moveAmount = type == this->moveType ? this->moveAmount + 5 : 5;
        this->moveType = type;
    }
    
    void MarioCharacter::Animate(float dt){
        if(this->clock.getElapsedTime().asSeconds() > this->switchTime){
            this->spriteCharacter.setTextureRect(sf::IntRect(this->frameInterator * 110, this->framePosY, 110, 90));
            
            if(this->characterStatus == CHARACTER_STATE_ATTACK && this->frameInterator > this->totalFrames / 3){
                this->shotEntity->Shoot(this->spriteCharacter.getPosition());
            }
            
            if(this->frameInterator >= this->totalFrames - 1){
                this->frameInterator = 0;
                if(this->characterStatus == CHARACTER_STATE_ATTACK)
                    this->attackCompleted = true;
            }else this->frameInterator++;
            
            this->clock.restart();
        }
    }
    
    void MarioCharacter::Update(float dt){
        if(this->characterStatus != CHARACTER_STATE_DEAD){
            this->shotEntity->Animate(dt);
            this->shotEntity->Update(dt);
        
        
        switch (this->characterStatus) {
            case CHARACTER_STATE_SWIM:
                this->framePosY = 0;
                this->totalFrames = 12;
                this->switchTime = 0.08;
                break;
            case CHARACTER_STATE_ATTACK:
                this->framePosY = 90;
                this->totalFrames = 21;
                this->switchTime = 0.03;
                if(this->frameInterator > this->totalFrames - 3 && !this->attackCompleted){
                    float originalXPos = this->data->window.getView().getCenter().x - (this->spriteCharacter.getPosition().x - (dt * 1000));
                    if(this->data->window.getView().getSize().x / 2 - originalXPos > 0){
                        this->spriteCharacter.move(-(dt * 1000), 0);
                        this->movementX -= dt * 1000;
                    }
                }
                break;
            case CHARACTER_STATE_DEAD:
                this->clock.restart();
                this->spriteCharacter.setColor(sf::Color(255,0,0,128));
                break;
            default:
                this->totalFrames = 10;
                this->switchTime = 0.08;
                break;
        }
        
        if(this->characterStatus != CHARACTER_STATE_ATTACK)
            this->characterStatus = this->defaultState;
        else if(this->attackCompleted){
            this->characterStatus = this->defaultState;
            this->attackCompleted = false;
        }
        
        if(this->moveAmount > 0){
            switch (this->moveType) {
                case CHARACTER_MOVE_UP:
                    this->spriteCharacter.move(0, -(dt * CHARACTER_MOVE_SPEED ));
                    this->movementY -= dt * CHARACTER_MOVE_SPEED;
                    break;
                case CHARACTER_MOVE_DOWN:
                    this->spriteCharacter.move(0, (dt * CHARACTER_MOVE_SPEED ));
                    this->movementY += dt * CHARACTER_MOVE_SPEED;
                    break;
                case CHARACTER_MOVE_LEFT:
                    this->spriteCharacter.move(-(dt * CHARACTER_MOVE_SPEED ), 0);
                    this->movementX -= dt * CHARACTER_MOVE_SPEED;
                    break;
                case CHARACTER_MOVE_RIGTH:
                    this->spriteCharacter.move((dt * CHARACTER_MOVE_SPEED ), 0);
                    this->movementX += dt * CHARACTER_MOVE_SPEED;
                    break;
            }
            this->moveAmount -= 1.5;
        }
        
        this->spriteCharacter.setPosition(this->data->window.getView().getCenter().x + this->movementX, (this->data->window.getSize().y - this->data->window.getSize().y/4) + this->movementY );
        }
    }
    
    void MarioCharacter::SetDefaultState(int state){
        this->defaultState = state;
    }
    const sf::Sprite &MarioCharacter::GetSprite() const {
        return this->spriteCharacter;
    }
    const sf::Sprite &MarioCharacter::GetShootSprite() const {
        return this->shotEntity->GetSprite();
    }
    void MarioCharacter::SetState(int state){
        if(state == CHARACTER_STATE_ATTACK && this->characterStatus != CHARACTER_STATE_ATTACK){
            this->frameInterator = 0;
            this->clock.restart();
        }
        this->characterStatus = state;
    }
    
    int MarioCharacter::GetState(){
        return this->characterStatus;
    }
    
    bool MarioCharacter::hasShoot(){
        return this->shotEntity->hasShoot();
    }
    
}
