//
//  Game.cpp
//  PROYECTO
//
//  Created by Alex Paredes on 2/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#include "Game.hpp"
#include "SplashState.hpp"

namespace DevJAD {
    
    Game::Game(std::string title, int screen_type){
        if(screen_type == SCREEN_SIZE_TYPE_MEDIUM){
            this->data->window.create(sf::VideoMode(MEDIUM_SCREEN_SIZE_WIDTH, MEDIUM_SCREEN_SIZE_HEIGHT), title, sf::Style::Close | sf::Style::Titlebar);
        }else{
            this->data->window.create(sf::VideoMode(LARGE_SCREEN_SIZE_WIDTH, LARGE_SCREEN_SIZE_HEIGHT), title, sf::Style::Close | sf::Style::Titlebar);
        }
        this->data->window.setFramerateLimit(60);
        this->data->screenType = SCREEN_SIZE_TYPE_MEDIUM;
        this->data->machine.AddState(StateRef(new SplashState(this->data)));
        //this->data->machine.AddState(StateRef(new GameOverState(this->data)));
        this->Run();
    }
    
    void Game::Run(){
        float newTime, frameTime, interpolation;
        float currentTime = this->clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;
        
        while (this->data->window.isOpen()) {
            this->data->machine.ProcessStateChanges();
            newTime = this->clock.getElapsedTime().asSeconds();
            frameTime = newTime - currentTime;
            
            if(frameTime > 0.25f){
                frameTime = 0.25f;
            }
            
            currentTime = newTime;
            accumulator += frameTime;
            
            while (accumulator >= dt) {
                this->data->machine.GetActiveState()->HandleInput();
                this->data->machine.GetActiveState()->Update(dt);
                accumulator -= dt;
            }
            
            interpolation = accumulator / dt;
            this->data->machine.GetActiveState()->Draw(interpolation);
            
        }
    }
    
}
