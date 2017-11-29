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
        this->data->assets.LoadTexture("rope", "Assets/images/cuerda.png");
        this->viewScreen = sf::View(this->data->window.getDefaultView());
        sf::Sprite background(this->data->assets.GetTexture("forest background"));
        background.setScale(0.5, 0.5);
        if(this->data->screenType == SCREEN_SIZE_TYPE_MEDIUM)
            background.setScale(0.3, 0.30);
        
        this->backgroundChange.push_back(background);
        background.setPosition(background.getGlobalBounds().width, 0);
        this->backgroundChange.push_back(background);
        
        this->backgrounSize = background.getGlobalBounds().width;
        this->viewAccum = 0;
        
        this->lianas = new LianaController(this->data);
        this->lianas->SpawnLianas();
        //this->lianas->SpawnLianas();
        //this->lianas->SpawnLianas();
    }
    
    void GameState::HandleInput(){
        sf::Event event;
        
        while (this->data->window.pollEvent(event)) {
            if(sf::Event::Closed == event.type) this->data->window.close();
        }
    }
    
    void GameState::Update(float dt){
        this->lianas->Update(dt);
        //if(this->clock.getElapsedTime().asSeconds() > 0.1f){
        //this->viewScreen.move(dt * 100, 0);
        //this->viewAccum += dt * 100;
        /*if(this->viewAccum >= this->backgrounSize - this->viewScreen.getSize().x){
            
        }*/
         //  this->clock.restart();
        //}
    }
    
    void GameState::Draw(float dt){
        this->data->window.clear(sf::Color::White);
        this->data->window.setView(this->viewScreen);
        for(unsigned int i = 0; i < this->backgroundChange.size(); i++){
            this->data->window.draw( this->backgroundChange.at(i) );
        }
        this->lianas->Draw();
        this->data->window.display();
    }
    
}
