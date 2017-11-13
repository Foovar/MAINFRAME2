//
//  MainMenuState.cpp
//  PROYECTO
//
//  Created by DevJAD on 2/11/17.
//  Copyright © 2017 DevJAD. All rights reserved.
//

#include <sstream>
#include "Constants.hpp"
#include "MainMenuState.hpp"
#include "GameState.hpp"
#include "SeaGameState.hpp"
#include <iostream>

namespace DevJAD {
    
    MainMenuState::MainMenuState(GameDataRef data){
        this->data = data;
    }
    
    void MainMenuState::Init(){
        this->data->assets.LoadTexture("main background", MAIN_BACKGROUND_FILEPATH);
        this->data->assets.LoadTexture("main menu", MAIN_MENU_FILEPATH);
        this->data->assets.LoadTexture("main title", MAIN_TITLE_FILEPATH);
        
        this->background.setTexture(this->data->assets.GetTexture("main background"));
        this->title.setTexture(this->data->assets.GetTexture("main title"));
        
        this->CreateMenu();
        
        this->background.setScale(1.5, 1.5);
        this->title.setPosition(sf::Vector2f(
             SCREEN_WIDTH / 2 - this->title.getGlobalBounds().width / 2,
             (SCREEN_HEIGHT / 2 - this->title.getGlobalBounds().height / 2 ) - this->data->assets.GetTexture("main menu").getSize().y/4) );
    }
    
    void MainMenuState::CreateMenu(){
        sf::Vector2<unsigned int> menuSize =this->data->assets.GetTexture("main menu").getSize();
        startMenuPositionX = ((SCREEN_WIDTH / 2) - 8) - menuSize.x / 2;
        startMenuPositionY = SCREEN_HEIGHT / 2 - 60;
        
        this->menuItemStart.setTexture(this->data->assets.GetTexture("main menu"));
        this->menuItemStart.setTextureRect(sf::IntRect(0, 20, menuSize.x, 90));
        this->menuItemStart.setPosition(startMenuPositionX, startMenuPositionY);
        
        this->menuItemOptions.setTexture(this->data->assets.GetTexture("main menu"));
        this->menuItemOptions.setTextureRect(sf::IntRect(0, 20+90, menuSize.x, 95));
        this->menuItemOptions.setPosition(this->menuItemStart.getPosition().x, this->menuItemStart.getPosition().y + this->menuItemStart.getGlobalBounds().height);
        
        this->menuItemCredits.setTexture(this->data->assets.GetTexture("main menu"));
        this->menuItemCredits.setTextureRect(sf::IntRect(0, 20+90+95, menuSize.x, 86));
        this->menuItemCredits.setPosition(this->menuItemOptions.getPosition().x, this->menuItemOptions.getPosition().y + this->menuItemOptions.getGlobalBounds().height);
        
        this->menuItemQuit.setTexture(this->data->assets.GetTexture("main menu"));
        this->menuItemQuit.setTextureRect(sf::IntRect(0, 20+90+95+86, menuSize.x, 120));
        this->menuItemQuit.setPosition(this->menuItemCredits.getPosition().x, this->menuItemCredits.getPosition().y + this->menuItemCredits.getGlobalBounds().height);
    }
    
    void MainMenuState::HandleInput(){
        sf::Event event;
        sf::Vector2i mpos;
         sf::Vector2<unsigned int> menuSize =this->data->assets.GetTexture("main menu").getSize();
        
        while (this->data->window.pollEvent(event)) {
            if(sf::Event::Closed == event.type) this->data->window.close();
            
            mpos = this->data->input.GetMousePosition(this->data->window);
            
            if(sf::Event::MouseMoved == event.type){
                this->CreateMenu();
                if(this->data->input.IsSpriteHover(this->menuItemStart, this->data->window)){
                    this->menuItemStart.setTextureRect(sf::IntRect(0, 20 + menuSize.y / 2, menuSize.x, 90));
                }else if(this->data->input.IsSpriteHover(this->menuItemOptions, this->data->window)){
                    this->menuItemOptions.setTextureRect(sf::IntRect(0, 20+90+ menuSize.y / 2, menuSize.x, 95));
                }else if(this->data->input.IsSpriteHover(this->menuItemCredits, this->data->window)){
                    this->menuItemCredits.setTextureRect(sf::IntRect(0, 20+90+95+ menuSize.y / 2, menuSize.x, 86));
                }else if(this->data->input.IsSpriteHover(this->menuItemQuit, this->data->window)){
                    this->menuItemQuit.setTextureRect(sf::IntRect(0, 20+90+95+86+ menuSize.y / 2, menuSize.x, 120));
                }
                
            }
            
            if(this->data->input.IsSpriteClicked(this->menuItemQuit, sf::Mouse::Button::Left, this->data->window)){
                this->data->window.close();
                //this->data->machine.AddState(StateRef(new GameState(this->data)), true);
                //this->data->machine.AddState(StateRef(new SeaGameState(this->data)), true);
            }else if(this->data->input.IsSpriteClicked(this->menuItemStart, sf::Mouse::Button::Left, this->data->window)){
                this->data->machine.AddState(StateRef(new SeaGameState(this->data)), true);
            }
        }
    }
    
    void MainMenuState::Update(float dt){
       
    }
    
    void MainMenuState::Draw(float dt){
        this->data->window.clear(sf::Color::Red);
        this->data->window.draw(this->background);
        this->data->window.draw(this->title);
        this->data->window.draw(this->menuItemStart);
        this->data->window.draw(this->menuItemOptions);
        this->data->window.draw(this->menuItemCredits);
        this->data->window.draw(this->menuItemQuit);
        this->data->window.display();
    }
    
}
