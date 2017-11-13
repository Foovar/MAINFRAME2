//
//  GameState.cpp
//  PROYECTO
//
//  Created by Alex Paredes on 3/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#include <sstream>
#include "GameState.hpp"
#include "Constants.hpp"
#include <iostream>

namespace DevJAD {
    
    GameState::GameState(GameDataRef data){
        this->data = data;
    }
    
    void GameState::Init(){
        //this->data->assets.LoadTexture("game background", GAME_BACKGROUND_PATH);
        //this->background.setTexture(this->data->assets.GetTexture("game background"));
        //this->data->assets.LoadTexture("thorn", GAME_THORN_FILEPATH);
        //this->data->assets.LoadTexture("tarzan character", GAME_CHARACTER_FILEPATH);
        //this->tarzan = new Tarzan(this->data);
    }
    
    void GameState::HandleInput(){
        sf::Event event;
        
        while (this->data->window.pollEvent(event)) {
            if(sf::Event::Closed == event.type) this->data->window.close();
            if(event.key.code == sf::Keyboard::Right){
                 //this->tarzan->Move();
            }
        }
    }
    
    void GameState::Update(float dt){
        
        this->tarzan->Update(dt);
    }
    
    void GameState::Draw(float dt){
        //this->data->window.clear(sf::Color::White);
        this->data->window.draw(this->background);
        //this->tarzan->Draw();
        this->data->window.display();
    }
    
}
