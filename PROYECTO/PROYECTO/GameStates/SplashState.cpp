//
//  SplashState.cpp
//  PROYECTO
//
//  Created by Alex Paredes on 2/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//
#include <sstream>
#include "SplashState.hpp"
#include "Constants.hpp"
#include "MainMenuState.hpp"
#include <iostream>
#include "Utils.hpp"

namespace DevJAD {
    
    SplashState::SplashState(GameDataRef data){
        this->data = data;
    }
    
    void SplashState::Init(){
        this->data->assets.LoadTexture("splash_logo", SPLASH_LOGO_FILEPATH);
        this->data->assets.LoadTexture("splash_extra", SPLASH_EXTRA_FILEPATH);
        this->data->assets.LoadTexture("sea background", SEA_BACKGROUND_FILEPATH);
        this->data->assets.LoadTexture("scorebar", SCOREBAR_FILEPATH);
        this->data->assets.LoadFont("display", SCOREBAR_FONT_FILEPATH);
        this->data->assets.LoadTexture("forest background", FOREST_BACKGROUND_FILEPATH);
        
        
        this->logo.setTexture(this->data->assets.GetTexture("splash_logo"));
        this->extra.setTexture(this->data->assets.GetTexture("splash_extra"));
        this->extra.setPosition(sf::Vector2f(this->data->window.getSize().x / 2 - this->extra.getGlobalBounds().width/2, -120));
        
        if(this->data->screenType == SCREEN_SIZE_TYPE_MEDIUM){
            this->extra.setScale(0.7, 0.7);
            this->extra.setPosition(this->extra.getPosition().x + this->extra.getGlobalBounds().width / 3, this->extra.getPosition().y);
            this->logo.setScale(0.7f, 0.7f);
        }
        
        this->logo.setPosition(getCenterPosition(this->data->window.getSize(), this->logo.getGlobalBounds()));
        
    }
    
    void SplashState::HandleInput(){
        sf::Event event;
        
        while (this->data->window.pollEvent(event)) {
            if(sf::Event::Closed == event.type) this->data->window.close();
        }
    }
    
    void SplashState::Update(float dt){
        
        if(this->clock.getElapsedTime().asSeconds() <= 1) {
            this->extra.setColor(sf::Color(255, 255, 255,this->clock.getElapsedTime().asSeconds() * 255));
            this->logo.setColor(sf::Color(255, 255, 255, this->clock.getElapsedTime().asSeconds() * 255));
        }else if(this->clock.getElapsedTime().asSeconds() > 3 && this->clock.getElapsedTime().asSeconds() < 4){
            this->extra.setColor(sf::Color(255, 255, 255, 255 - ((this->clock.getElapsedTime().asSeconds() - 3) * 255)));
            this->logo.setColor(sf::Color(255, 255, 255, 255 - ((this->clock.getElapsedTime().asSeconds() - 3) * 255)));
        }
        
        if(this->clock.getElapsedTime().asSeconds() > SPLASH_DURATION){
            this->data->machine.AddState( StateRef(new MainMenuState(this->data)), true );
        }
    }
    
    void SplashState::Draw(float dt){
        this->data->window.clear(sf::Color::White);
        //this->data->window.draw(this->background);
        this->data->window.draw(this->extra);
        this->data->window.draw(this->logo);
        this->data->window.display();
    }
    
}
