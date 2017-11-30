//
//  SplashState.cpp
//  PROYECTO
//
//  Created by Alex Paredes on 2/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//
#include <sstream>
#include "SplashState.hpp"
#include "../Constants.hpp"
#include "MainMenuState.hpp"
#include <iostream>
#include "../Utils.hpp"

namespace DevJAD {
    
    SplashState::SplashState(GameDataRef data){
        this->data = data;
    }
    
    void SplashState::Init(){
        this->StartLoad();
        this->data->assets.LoadTexture("splash_logo", SPLASH_LOGO_FILEPATH);
        this->data->assets.LoadTexture("splash_extra", SPLASH_EXTRA_FILEPATH);
        this->data->assets.LoadTexture("sea background", SEA_BACKGROUND_FILEPATH);
        this->data->assets.LoadTexture("scorebar", SCOREBAR_FILEPATH);
        this->data->assets.LoadFont("display", SCOREBAR_FONT_FILEPATH);
        this->data->assets.LoadTexture("forest background", FOREST_BACKGROUND_FILEPATH);
        this->data->assets.LoadSoundBuffer("main sound", MAIN_SOUND_BACKGROUND);
        this->data->assets.LoadSoundBuffer("main click", MAIN_SOUND_CLICK);
        this->data->assets.LoadSoundBuffer("main hover", MAIN_SOUND_HOVER);
        this->data->assets.LoadSoundBuffer("sea background sound", SEA_SOUND_BACKGROUND);
        this->data->assets.LoadSoundBuffer("sea attack", SEA_ATTACK);
        this->data->assets.LoadTexture("mt background", MT_BACKGROUND_FILEPATH);
        this->data->assets.LoadTexture("mt coline", MT_COLINE_FILEPATH);
        
        this->logo.setTexture(this->data->assets.GetTexture("splash_logo"));
        this->extra.setTexture(this->data->assets.GetTexture("splash_extra"));
        this->extra.setPosition(sf::Vector2f(this->data->window.getSize().x / 2 - this->extra.getGlobalBounds().width/2, -120));
        
        if(this->data->screenType == SCREEN_SIZE_TYPE_MEDIUM){
            this->extra.setScale(0.7, 0.7);
            this->extra.setPosition(this->extra.getPosition().x + this->extra.getGlobalBounds().width / 3, this->extra.getPosition().y);
            this->logo.setScale(0.7f, 0.7f);
        }
        
        this->logo.setPosition(getCenterPosition(this->data->window.getSize(), this->logo.getGlobalBounds()));
        this->FinishLoad();
    }
    
    void SplashState::HandleInput(){
        sf::Event event;
        
        while (this->data->window.pollEvent(event)) {
            if(sf::Event::Closed == event.type) this->data->window.close();
        }
    }
    
    void SplashState::Update(float dt){
        std::cout << " Time "<< dt <<std::endl;
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
    
    void SplashState::StartLoad(){
        std::cout << "Iniciando la carga " << std::endl;
    }
    
    void SplashState::FinishLoad(){
        std::cout << "Fin de la carga " << std::endl;
        //this->data->machine.AddState( StateRef(new MainMenuState(this->data)), true );
    }
    
}
