//
//  SharkController.cpp
//  PROYECTO
//
//  Created by Alex Paredes on 8/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#include "SharkController.hpp"

namespace DevJAD {
    SharkController::SharkController(GameDataRef _data): data(_data) {
        srand((int)time(NULL));
    }
    
    void SharkController::SpawnSharks(){
        DevJAD::SharkEntity * sharkEntity;
        
        if(this->data->screenType == SCREEN_SIZE_TYPE_LARGE){
            sharkEntity = new SharkEntity(this->data->assets.GetTexture("shark"), sf::Vector2f(0.8,0.8));
        }else{
           sharkEntity = new SharkEntity(this->data->assets.GetTexture("shark"), sf::Vector2f(0.4,0.4));
        }
        int min = this->data->window.getSize().y / 2;
        int randomPosition = rand() % ((this->data->window.getSize().y - 100) - min + 1) + min;
        sharkEntity->SetPosition(this->data->window.getView().getCenter().x + (this->data->window.getView().getSize().x/2), randomPosition);
        this->sharks.push_back(*sharkEntity);
    }
    
    void SharkController::UpdateSharks(float dt){
        for (unsigned short int i = 0; i < this->sharks.size(); i++) {
            if(this->sharks.at(i).GetSprite().getPosition().x < -(this->sharks.at(i).GetSprite().getGlobalBounds().width) || (this->sharks.at(i).GetSprite().getPosition().y > 0 && this->sharks.at(i).GetCurrentAnimationData()->sprite.getPosition().y < this->data->window.getSize().y / 2)){
                this->sharks.erase(this->sharks.begin() + i);
            }else{
                this->sharks.at(i).Update(dt);
                this->sharks.at(i).Animate(dt);
            }
        }
    }
    
    void SharkController::MoveSharks(float dt){
        for (unsigned short int i = 0; i < this->sharks.size(); i++) {
            //this->sharks.at(i).Move(-(dt * 200), 0);
        }
    }
    
    void SharkController::DrawSharks(){
        for (unsigned short int i = 0; i < this->sharks.size(); i++) {
           this->data->window.draw(this->sharks.at(i).GetSprite());
            // Show collision border;
            /*
            sf::RectangleShape border;
            border.setSize(sf::Vector2f(this->sharks.at(i).GetSprite().getGlobalBounds().width - 20, this->sharks.at(i).GetSprite().getGlobalBounds().height - 20));
            border.setPosition(this->sharks.at(i).GetSprite().getPosition().x+10, this->sharks.at(i).GetSprite().getPosition().y+10);
            border.setFillColor(sf::Color(255,255,255,128));
            this->data->window.draw(border);*/
        }
    }
    
    bool SharkController::IsCollide(int i, sf::Sprite sprite){
        return this->collision.CheckSpriteCollision(sprite, this->sharks.at(i).GetSprite());
    }
    
    const std::vector<SharkEntity> &SharkController::GetEntities() const
    {
        return this->sharks;
    }
    
    void SharkController::SetSharkState(int shark, int state){
        this->sharks.at(shark).SetState(state);
    }
    
    void SharkController::SetScale(float x, float y){
        this->scale = sf::Vector2f(x, y);
    }
    
}
