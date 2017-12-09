
//
//  StoneController.cpp
//  PROYECTO
//
//  Created by Alex Paredes on 9/12/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#include "StoneController.hpp"
namespace DevJAD {
    StoneController::StoneController(GameDataRef _data): data(_data){
        
    }
    
    void StoneController::SpawnStones(){
        // temporal
        if(this->stones.size() > 3){
            this->stones.erase(this->stones.begin() + 1);
        }
        this->stones.push_back(StoneEntity(this->data));
    }
    
    void StoneController::Draw(){
        for(unsigned int i = 0; i < this->stones.size(); i++){
            this->stones.at(i).Draw();
        }
    }
    
    void StoneController::Update(float dt){
        for(unsigned int i = 0; i < this->stones.size(); i++){
            this->stones.at(i).Update(dt);
            this->stones.at(i).Animate(dt);
        }
    }
    
    void StoneController::Move(unsigned int i, float x, float y){
        this->stones.at(i).Move(x, y);
    }
    
    void StoneController::SetPosition(int i, sf::Vector2f p){
        this->stones.at(i).setPosition(p.x, p.y);
    }
    
    sf::Vector2f StoneController::GetPosition(int i){
        return this->stones.at(i).GetSprite().getPosition();
    }
    size_t StoneController::size(){
        return this->stones.size();
    }
    const sf::Sprite &StoneController::GetSprite(int i) const {
        return this->stones.at(i).GetSprite();
    }
}
