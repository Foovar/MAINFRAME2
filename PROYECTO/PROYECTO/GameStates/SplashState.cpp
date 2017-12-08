
#include <sstream>
#include "SplashState.hpp"
#include "../Constants.hpp"
#include "MainMenuState.hpp"
#include <iostream>
#include "../Utils.hpp"
#include "MountainGameState.hpp"

namespace DevJAD {
    
    SplashState::SplashState(GameDataRef data){
        this->data = data;
    }
    
    void SplashState::Init(){
        this->StartLoad();
        this->data->assets.LoadTexture("character 02", GAME_CHARACTER02_PATH);
        this->data->assets.LoadTexture("splash_logo", SPLASH_LOGO_FILEPATH);
        this->data->assets.LoadTexture("splash_extra", SPLASH_EXTRA_FILEPATH);
        this->data->assets.LoadTexture("scorebar", SCOREBAR_FILEPATH);
        this->data->assets.LoadTexture("mt coline", MT_COLINE_FILEPATH);
        this->data->assets.LoadTexture("main menu", MAIN_MENU_FILEPATH);
        this->data->assets.LoadTexture("main title", MAIN_TITLE_FILEPATH);
        this->data->assets.LoadTexture("you win", WIN_TEXT_PATH);
        
        this->data->assets.LoadFont("display", SCOREBAR_FONT_FILEPATH);
        this->data->assets.LoadFont("credits", CREDITS_FONT_FILEPATH);
        this->data->assets.LoadFont("ka1", SCORE_GAMEOVER_FONT_FILEPATH);
        
        this->data->assets.LoadSoundBuffer("main click", MAIN_SOUND_CLICK);
        this->data->assets.LoadSoundBuffer("main hover", MAIN_SOUND_HOVER);
        this->data->assets.LoadSoundBuffer("sea attack", SEA_ATTACK);
        this->data->assets.LoadSoundBuffer("dead sound", DEAD_SOUND_FILEPATH);
        
        this->logo.setTexture(this->data->assets.GetTexture("splash_logo"));
        this->extra.setTexture(this->data->assets.GetTexture("splash_extra"));
        
        this->extra.setPosition(sf::Vector2f(this->data->window.getSize().x / 2 - this->extra.getGlobalBounds().width/2, -120));
        
        if(this->data->screenType == SCREEN_SIZE_TYPE_MEDIUM){
            this->extra.setScale(0.7, 0.7);
            this->extra.setPosition(this->extra.getPosition().x + this->extra.getGlobalBounds().width / 3, this->extra.getPosition().y);
            this->logo.setScale(0.7f, 0.7f);
        }
        this->transparent = 0;
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
        if(this->isFinishLoad){
            float seconds = this->clock.getElapsedTime().asSeconds();
            if(seconds > SPLASH_DURATION){
                if(seconds < (float)(SPLASH_DURATION + 1.0)){
                    this->transparent = 255 - ((seconds - (float)SPLASH_DURATION ) * 255.0);
                    this->extra.setColor(sf::Color(255, 255, 255, this->transparent ));
                    this->logo.setColor(sf::Color(255, 255, 255, this->transparent ));
                   // this->logo.move(-(dt * 500), 0);
                }
                if(this->transparent <= 5)
                    this->data->machine.AddState( StateRef(new MountainGameState(this->data)), true );
            }
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
        this->isFinishLoad = false;
    }
    
    void SplashState::FinishLoad(){
        this->isFinishLoad = true;
        this->data->assets.LoadTexture("main background", MAIN_BACKGROUND_FILEPATH);
        this->data->assets.LoadTexture("sea background", SEA_BACKGROUND_FILEPATH);
        this->data->assets.LoadTexture("forest background", FOREST_BACKGROUND_FILEPATH);
        this->data->assets.LoadTexture("mt background", MT_BACKGROUND_FILEPATH);
        this->clock.restart();
    }
    
}
