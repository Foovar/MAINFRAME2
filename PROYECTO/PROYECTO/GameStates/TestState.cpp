//
//  TestState.cpp
//  PROYECTO
//
//  Created by Alex Paredes on 25/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#include "TestState.hpp"

namespace DevJAD {
    
    TestState::TestState(GameDataRef data){
        this->data = data;
    }
    
    void TestState::Init(){
        this->data->assets.LoadTexture("character 02", GAME_CHARACTER02_PATH);
        this->marioCharacter = new MarioCharacter(this->data);
        this->marioCharacter->SetDefaultState(CHARACTER_STATE_SWIM);
    }
    
    void TestState::HandleInput(){
        sf::Event event;
        
        while (this->data->window.pollEvent(event)) {
            if(sf::Event::Closed == event.type) this->data->window.close();
            if(sf::Event::KeyPressed == event.type || sf::Event::KeyReleased == event.type){
                if(event.key.code == sf::Keyboard::Up){
                    this->marioCharacter->Move(CHARACTER_MOVE_UP);
                }else if(event.key.code == sf::Keyboard::Down){
                    this->marioCharacter->Move(CHARACTER_MOVE_DOWN);
                }else if(event.key.code == sf::Keyboard::Left){
                    this->marioCharacter->Move(CHARACTER_MOVE_LEFT);
                }else if(event.key.code == sf::Keyboard::Right){
                    this->marioCharacter->Move(CHARACTER_MOVE_RIGTH);
                }else if(event.key.code == sf::Keyboard::X){
                    this->marioCharacter->SetState(CHARACTER_STATE_ATTACK);
                }
            }
        }
    }
    
    void TestState::Update(float dt){
        this->marioCharacter->Update(dt);
        this->marioCharacter->Animate(dt);
    }
    
    void TestState::Draw(float dt){
        this->data->window.clear(sf::Color::White);
        this->marioCharacter->Draw();
        this->data->window.display();
    }
    
}
