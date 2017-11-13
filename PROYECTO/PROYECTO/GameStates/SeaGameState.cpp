//
//  SeaGameState.cpp
//  PROYECTO
//
//  Created by Alex Paredes on 4/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#include <sstream>
#include "SeaGameState.hpp"
#include "Constants.hpp"
#include <iostream>
#include "SharkEntity.hpp"

namespace DevJAD {
    
    SeaGameState::SeaGameState(GameDataRef data){
        this->data = data;
        this->viewScreen = sf::View(this->data->window.getDefaultView());
        this->maxDuration = this->viewScreen.getSize().x;
        this->gameState = IS_PLAYING;
    }
    
    void SeaGameState::Init(){
        this->data->assets.LoadTexture("character 01", GAME_CHARACTER01_PATH);
        this->data->assets.LoadTexture("shark", SHARK_FILEPATH);
        this->data->assets.LoadTexture("sea coral", SEA_CORAL_FILEPATH);
        
        this->background.setTexture(this->data->assets.GetTexture("sea background"));
        this->coral.setTexture(this->data->assets.GetTexture("sea coral"));
        this->coral.setPosition(0, this->background.getGlobalBounds().height - this->coral.getGlobalBounds().height);
        
        this->tarzan = new Tarzan(this->data);
        this->sharks = new SharkController(this->data);
        this->flash = new Flash(this->data, this->background.getGlobalBounds().width, this->data->window.getSize().y);
    }
    
    void SeaGameState::HandleInput(){
        sf::Event event;
        
        while (this->data->window.pollEvent(event)) {
            if(sf::Event::Closed == event.type) this->data->window.close();
            if(sf::Event::KeyPressed == event.type){
                if(event.key.code == sf::Keyboard::Left){
                    this->tarzan->SetState(GAME_MOVE_TO_LEFT);
                }else if(event.key.code == sf::Keyboard::Right){
                    this->tarzan->SetState(GAME_MOVE_TO_RIGTH);
                }else if(event.key.code == sf::Keyboard::Up){
                    this->tarzan->SetState(GAME_MOVE_TO_UP);
                }else if(event.key.code == sf::Keyboard::Down){
                    this->tarzan->SetState(GAME_MOVE_TO_DOWN);
                }else if(event.key.code == sf::Keyboard::X){
                    this->tarzan->SetState(IS_ATTACKING);
                }
            }
        }
    }
    
    void SeaGameState::Update(float dt){
        
        
        //this->sharks->IsCollide( this->tarzan->GetSprite() );
        
        if(this->gameState != IS_GAME_OVER){
            
            std::vector<SharkEntity> sharkEntities = this->sharks->GetEntities();
            for(unsigned short int i = 0; i< sharkEntities.size(); i++){
                if(this->collision.CheckSpriteCollision(sharkEntities.at(i).GetSprite(), this->tarzan->GetSprite())){
                    if(sharkEntities.at(i).GetState() != SHARK_DIE){
                        this->sharks->SetSharkState(i, SHARK_ATTACK);
                    }
                    
                    if(this->tarzan->GetState() == IS_ATTACKING){
                        this->sharks->SetSharkState(i, SHARK_DIE);
                    }else{
                        //this->tarzan->SetState(IS_DEAD);
                        this->gameState = IS_GAME_OVER;
                        this->clock.restart();
                    }
                }
            }
            
            
            this->sharks->UpdateSharks(dt);
            
            this->tarzan->Animate(dt);

            this->tarzan->Update(dt);
            
            if(this->clock.getElapsedTime().asSeconds() > 0.01) {
                if(this->maxDuration < this->background.getGlobalBounds().width){
                    this->viewScreen.move((dt*210), 0);
                    this->maxDuration+=dt*210;
                } // level terminado -> pasar al siguiente nivel.
                this->clock.restart();
            }
            
            
            if(this->coralClock.getElapsedTime().asSeconds() > 0.02){
                if(this->maxDuration < this->background.getGlobalBounds().width){
                    this->coral.move(dt * 100, 0);
                }
            }
            
            if(clockSpawn.getElapsedTime().asSeconds() > 1.5){
                this->sharks->SpawnSharks();
                clockSpawn.restart();
            }
        }
        
        if(this->gameState == IS_GAME_OVER){
            this->flash->Show(dt);
            if(this->clock.getElapsedTime().asSeconds() > GAME_OVER_AFTER_FLASH / 1000){
                this->data->machine.AddState(StateRef(new GameOverState(this->data)), true);
            }
        }
    }
    
    void SeaGameState::Draw(float dt){
        this->data->window.clear(sf::Color::White);
        this->data->window.setView(this->viewScreen);
        this->data->window.draw(this->background);
        this->data->window.draw(this->coral);
        this->tarzan->Draw();
        this->sharks->DrawSharks();
        this->flash->Draw();
        this->data->window.display();
    }
    
}
