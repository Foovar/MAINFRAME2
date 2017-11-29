//
//  LianaController.cpp
//  PROYECTO
//
//  Created by Alex Paredes on 26/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#include "LianaController.hpp"

namespace DevJAD {
    LianaController::LianaController(GameDataRef _data): data(_data){
        
    }
    
    void LianaController::SpawnLianas(){
        float x = this->lianas.size() == 0  ? 120.0f : ( this->lianas.size() * 520 );
        LianaEntity liana(this->data, sf::Vector2f(x, 0.0f), 175, 1 * ((this->lianas.size() & 1) == 0 ? -1: 1) );
        this->lianas.push_back(liana);
        
    }
    
    void LianaController::SetPosition(int i, sf::Vector2f p){
        this->lianas.at(i).SetPosition(p);
    }
    
    void LianaController::Update(float dt){
        for(unsigned int i = 0; i < this->lianas.size(); i++){
            this->lianas.at(i).Update(dt);
        }
    }
    
    void LianaController::Draw(){
        for (unsigned int i = 0; i < this->lianas.size(); i++) {
            this->lianas.at(i).Draw();
        }
    }
}
