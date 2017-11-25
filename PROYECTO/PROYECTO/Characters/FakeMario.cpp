//
//  FakeMario.cpp
//  PROYECTO
//
//  Created by Alex Paredes on 25/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#include "FakeMario.hpp"
#include "iostream"
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
        this->timeAttack = 0;
    }
    
    void FakeMario::Draw(){
        this->data->window.draw(this->fakeMarioSprite);
        // Show collision border
        /*
        sf::RectangleShape border;
        border.setSize(sf::Vector2f(this->fakeMarioSprite.getGlobalBounds().width - 30, this->fakeMarioSprite.getGlobalBounds().height - 20));
        border.setPosition(this->fakeMarioSprite.getPosition().x + 15, this->fakeMarioSprite.getPosition().y+10);
        border.setFillColor(sf::Color(255,255,255,128));
        this->data->window.draw(border);*/
    }
    
    void FakeMario::Animate(float dt){
        if(this->clock.getElapsedTime().asSeconds() > 0.1f){
            if(this->state != IS_ATTACKING){
                if(framesInterator > 10){
                    framesInterator = 0;
                }else
                    framesInterator++;
                this->fakeMarioSprite.setTextureRect(sf::IntRect(framesInterator * 110, 0, 110, 85));
            }else{
                this->timeAttack = this->timeAttack > 0 ? this->timeAttack : 19.0;
                if(framesInterator > 19){
                    framesInterator = 0;
                }else
                    framesInterator++;
                std::cout << "Intervalo " << this->timeAttack  << std::endl;
                this->fakeMarioSprite.setTextureRect(sf::IntRect(framesInterator * 110, 85, 110, 87));
                this->timeAttack--;
            }
            
            this->clock.restart();
        }
    }
    
    const sf::Sprite &FakeMario::GetSprite() const{
        return this->fakeMarioSprite;
    }
    
    void FakeMario::Update(float dt){
        int speed = 850 * dt;
        if(IS_SWIMMING != this->state && this->state != IS_ATTACKING){
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
            
        }else if(this->state == IS_ATTACKING){
            if(this->timeAttack <= 0)
                this->state = IS_SWIMMING;
        }
        
        this->fakeMarioSprite.setPosition(this->data->window.getView().getCenter().x + this->movementX, (this->data->window.getSize().y - this->data->window.getSize().y/4) + this->movementY );
        
    }
    
    int FakeMario::GetState(){
        return this->state;
    }
    
    void FakeMario::SetState(int _state){
        this->state = _state;
    }
}
