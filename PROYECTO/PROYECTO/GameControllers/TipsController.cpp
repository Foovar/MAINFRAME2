//
//  TipsController.cpp
//  PROYECTO
//
//  Created by Alex Paredes on 2/12/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#include "TipsController.hpp"
namespace DevJAD {
    TipsController::TipsController(GameDataRef _data): data(_data){
        
    }
    
    void TipsController::SpawnTips(){
        sf::Sprite tip(this->data->assets.GetTexture("tip"));
        if(this->data->screenType == SCREEN_SIZE_TYPE_MEDIUM)
            tip.setScale(0.85, 0.85);
        tip.setPosition(this->tips.size() * tip.getGlobalBounds().width, this->data->window.getSize().y - tip.getGlobalBounds().height);
        this->tips.push_back(tip);
    }
    
    void TipsController::Draw(){
        for(unsigned int i = 0; i < this->tips.size(); i++){
            this->data->window.draw(this->tips.at(i));
        }
    }
    
    void TipsController::Update(float dt){
        
    }
    
    void TipsController::SetPosition(int i, sf::Vector2f p){
        this->tips.at(i).setPosition(p);
    }
    
    sf::Vector2f TipsController::GetPosition(int i){
        return this->tips.at(i).getPosition();
    }
}
