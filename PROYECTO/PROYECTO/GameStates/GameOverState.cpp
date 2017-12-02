//
//  GameOverState.cpp
//  PROYECTO
//
//  Created by Alex Paredes on 3/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#include "GameOverState.hpp"
#include "MainMenuState.hpp"
#include "../Game.hpp"

namespace DevJAD {
    
    GameOverState::GameOverState(GameDataRef data, int score){
        this->data = data;
        this->score = score;
    }
    
    void GameOverState::Init(){
        this->data->window.setView(this->data->window.getDefaultView());
        this->data->assets.LoadTexture("main background", MAIN_BACKGROUND_FILEPATH);
        this->data->assets.LoadTexture("game over", GAME_OVER_BOX_FILEPATH);
        this->data->assets.LoadTexture("game over buttons", GAME_OVER_BUTTONS_FILEPATH);
        this->buttonExit.setTexture(this->data->assets.GetTexture("game over buttons"));
        this->buttonExit.setTextureRect(sf::IntRect(0, 0, 145.f, 64.f));
        this->buttonReStart.setTexture(this->data->assets.GetTexture("game over buttons"));
        this->buttonReStart.setTextureRect(sf::IntRect(145.f, 0, 145.f, 64.f));
        this->background.setTexture(this->data->assets.GetTexture("main background"));
        this->box.setTexture(this->data->assets.GetTexture("game over"));
         this->background.setScale(1.5, 1.5);
        
        this->buttonExit.setOrigin(this->buttonExit.getLocalBounds().width / 2, 0);
        this->buttonReStart.setOrigin(this->buttonReStart.getLocalBounds().width / 2, 0);
        
        this->box.setPosition(this->data->window.getSize().x / 2 - (this->box.getGlobalBounds().width / 2), this->data->window.getSize().y / 2 - (this->box.getLocalBounds().height / 2));
        
        this->buttonExit.setPosition((this->box.getPosition().x + this->box.getLocalBounds().width / 2) - this->buttonExit.getLocalBounds().width / 1.5 , this->box.getPosition().y + this->box.getGlobalBounds().height - (this->buttonExit.getLocalBounds().height / 2));
        
        this->buttonReStart.setPosition((this->box.getPosition().x + this->box.getLocalBounds().width / 2) + this->buttonExit.getLocalBounds().width / 1.5, this->box.getPosition().y + this->box.getGlobalBounds().height - (this->buttonReStart.getLocalBounds().height / 2));
    
        this->scoreText.setFont(this->data->assets.GetFont("ka1"));
        this->scoreText.setString("SCORE: "+ std::to_string(this->score));
        this->scoreText.setPosition(this->data->window.getView().getCenter().x - this->scoreText.getLocalBounds().width /2, this->data->window.getView().getCenter().y + this->scoreText.getLocalBounds().height + 50);
    
    }
    
    void GameOverState::HandleInput(){
        sf::Event event;
        
        while (this->data->window.pollEvent(event)) {
            if(sf::Event::Closed == event.type) this->data->window.close();
            if(this->data->input.IsSpriteHover(this->buttonExit, this->data->window)){
                this->buttonExit.setTextureRect(sf::IntRect(0, 64.f, 145.f, 64.f));
            }else if(this->data->input.IsSpriteHover(this->buttonReStart, this->data->window)){
                this->buttonReStart.setTextureRect(sf::IntRect(145.f, 64.f, 145.f, 64.f));
            }else{
                this->buttonExit.setTextureRect(sf::IntRect(0, 0, 145.f, 64.f));
                this->buttonReStart.setTextureRect(sf::IntRect(145.f, 0, 145.f, 64.f));
            }
            
            if(this->data->input.IsSpriteClicked(this->buttonExit, sf::Mouse::Button::Left, this->data->window)){
                this->data->window.close();
            }else if(this->data->input.IsSpriteClicked(this->buttonReStart, sf::Mouse::Button::Left, this->data->window)){
                this->data->machine.AddState(StateRef(new MainMenuState(this->data)), true);
            }
            
        }
    }
    
    void GameOverState::Update(float dt){
        
    }
    
    void GameOverState::Draw(float dt){
       // this->data->window.clear(sf::Color::White);
        this->data->window.draw(this->background);
        this->data->window.draw(this->box);
        this->data->window.draw(this->buttonExit);
        this->data->window.draw(this->buttonReStart);
        this->data->window.draw(this->scoreText);
        this->data->window.display();
    }
    
}
