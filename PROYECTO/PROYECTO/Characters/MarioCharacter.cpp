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
        sf::Texture * marioTexture = new sf::Texture(this->data->assets.GetTexture("character 02"));
        marioTexture->setSmooth(true);
        
        this->soundAttack.setBuffer(this->data->assets.GetSoundBuffer("sea attack"));
        this->characterStatus = CHARACTER_STATE_WALK;
        this->frameInterator = 0;
        this->movementX = 0;
        this->movementY = 0;
        this->switchTime = 0.08;
        this->framePosX = 0;
        this->timeJump = 0;
        this->spriteCharacter.setTexture(*marioTexture);
        this->spriteCharacter.setTextureRect(sf::IntRect(0, 0, 0, 0));
        if(this->data->screenType == SCREEN_SIZE_TYPE_MEDIUM)
            this->spriteCharacter.setScale(0.8, 0.8);
        else
            this->spriteCharacter.setScale(1.3, 1.3);
        
        this->totalFrames = 12;
        this->attackCompleted = false;
        this->shotEntity = new ShotEntity(this->data);
    }
    
    void MarioCharacter::ResetAnimation(){
        this->frameInterator = 0;
        this->clock.restart();
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
            this->spriteCharacter.setTextureRect(sf::IntRect((this->frameInterator * 110) + this->framePosX, this->framePosY, 110, 90));
            
            if(this->characterStatus == CHARACTER_STATE_ATTACK && this->frameInterator > this->totalFrames / 3){
                this->shotEntity->Shoot(this->spriteCharacter.getPosition());
            }
            
            if(this->frameInterator >= this->totalFrames - 1){
                this->frameInterator = 0;
                if(this->characterStatus == CHARACTER_STATE_ATTACK)
                    this->attackCompleted = true;
                if(this->characterStatus == CHARACTER_STATE_JUMPING)
                    this->framePosX = 110;
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
                    if(this->attackCompleted)
                        this->soundAttack.play();
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
                case CHARACTER_STATE_HANG:
                    this->framePosY = 445;
                    this->totalFrames = 11;
                    break;
                case CHARACTER_STATE_JUMPING:
                    if(this->defaultState == CHARACTER_STATE_HANG){
                        if(this->framePosX == 0){
                            this->totalFrames = 15;
                        }else this->totalFrames = 14;
                        this->framePosY = 535;
                        
                        this->spriteCharacter.setPosition( this->physics->GetPosAtTime( this->timeJump ).x, this->physics->GetPosAtTime( this->timeJump ).y );
                        this->timeJump+=0.2;
                    }
                    break;
				case CHARACTER_STATE_WALK:
					this->framePosY = 265;
					this->totalFrames = 3;
					this->switchTime = 0.15;
					break;
                default:
                    this->totalFrames = 9;
                    this->switchTime = 0.08;
                    break;
            }
            if(this->characterStatus != CHARACTER_STATE_ATTACK  && this->characterStatus != CHARACTER_STATE_JUMPING)
                this->characterStatus = this->defaultState;
            else if(this->attackCompleted || this->jumpCompleted){
                this->characterStatus = this->defaultState;
                this->attackCompleted = false;
                this->jumpCompleted = false;
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
        
        if(this->characterStatus == CHARACTER_STATE_SWIM || this->characterStatus == CHARACTER_STATE_ATTACK)
            this->spriteCharacter.setPosition(this->data->window.getView().getCenter().x + this->movementX, (this->data->window.getSize().y - this->data->window.getSize().y/4) + this->movementY );
        }else {
            
            if(CHARACTER_STATE_HANG == this->defaultState) {
                this->framePosY = 625;
                this->totalFrames = 6;
                this->spriteCharacter.move(0, dt * 200);
			}
        }
    }
    
    void MarioCharacter::Jump(){
        if(CHARACTER_STATE_JUMPING != this->GetState()){
            this->SetState(CHARACTER_STATE_JUMPING);
            this->physics = new Physics(this->spriteCharacter.getPosition().x , this->spriteCharacter.getPosition().y, 45, 50, 0, 9.8);
            this->frameInterator = 0;
            this->timeJump = 0;
            this->jumpClock.restart();
            this->clock.restart();
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
            this->framePosX = 0;
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
    
    float MarioCharacter::GetMoveAmount(){
        return this->moveAmount;
    }
    
    void MarioCharacter::SetPosition(float x, float y){
        this->spriteCharacter.setPosition(x, y);
    }
    
    void MarioCharacter::SetPosition(sf::Vector2f position){
        this->spriteCharacter.setPosition(position);
    }
    
    sf::Vector2f MarioCharacter::GetPosition(){
        return this->spriteCharacter.getPosition();
    }
}
