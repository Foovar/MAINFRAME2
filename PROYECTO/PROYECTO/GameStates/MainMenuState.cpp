

#include <sstream>
#include "../Constants.hpp"
#include "MainMenuState.hpp"
#include "GameState.hpp"
#include "SeaGameState.hpp"
#include <iostream>

namespace DevJAD {
    
    MainMenuState::MainMenuState(GameDataRef data){
        this->data = data;
    }
    
    void MainMenuState::Init(){
        this->menu.setTexture(this->data->assets.GetTexture("main menu"));
        this->background.setTexture(this->data->assets.GetTexture("main background"));
        this->title.setTexture(this->data->assets.GetTexture("main title"));
        this->musicBackground.openFromFile(MAIN_MUSIC_BACKGROUND);
        this->soundClick.setBuffer(this->data->assets.GetSoundBuffer("main click"));
        this->soundHover.setBuffer(this->data->assets.GetSoundBuffer("main hover"));
        this->musicBackground.setLoop(true);
        this->musicBackground.play();
        
        if(this->data->screenType == SCREEN_SIZE_TYPE_MEDIUM){
            this->background.setScale(0.9, 0.9);
            this->title.setScale(0.5, 0.5);
            this->menu.setScale(0.5, 0.5);
            this->menuItemStart.setScale(this->menu.getScale());
            this->menuItemOptions.setScale(this->menu.getScale());
            this->menuItemCredits.setScale(this->menu.getScale());
            this->menuItemQuit.setScale(this->menu.getScale());
        }else
            this->background.setScale(1.5, 1.5);
        
        this->CreateMenu();
        
        this->title.setPosition(getCenterPosition(this->data->window.getSize(), this->title.getGlobalBounds()));
        this->title.setPosition(sf::Vector2f(this->title.getPosition().x, this->title.getPosition().y - this->menu.getGlobalBounds().height/4) );
        this->ResetHover();
    }
    
    void MainMenuState::CreateMenu(){
        sf::Vector2<unsigned int> menuSize =  sf::Vector2<unsigned int>(this->menu.getGlobalBounds().width * ( this->data->screenType == SCREEN_SIZE_TYPE_MEDIUM ? 2 : 1 ), this->menu.getGlobalBounds().height); //this->data->assets.GetTexture("main menu").getSize();
        
        startMenuPositionX = ((this->data->window.getSize().x / 2) - 8) - menuSize.x / ( this->data->screenType == SCREEN_SIZE_TYPE_MEDIUM ? 4 : 2 );
        if(this->data->screenType == SCREEN_SIZE_TYPE_MEDIUM){
            startMenuPositionX += 3;
        }
        startMenuPositionY = this->data->window.getSize().y / 2 - 60 /( this->data->screenType == SCREEN_SIZE_TYPE_MEDIUM ? 2 : 1 );
        
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
    void MainMenuState::ResetHover(){
        this->startHover = false;
        this->quitHover = false;
        this->optionsHover = false;
        this->creditsHover = false;
    }
    void MainMenuState::HandleInput(){
        sf::Event event;
        sf::Vector2i mpos;
         sf::Vector2<unsigned int> menuSize = this->data->assets.GetTexture("main menu").getSize();
        
        while (this->data->window.pollEvent(event)) {
            if(sf::Event::Closed == event.type) this->data->window.close();
            
            mpos = this->data->input.GetMousePosition(this->data->window);
            
            if(sf::Event::MouseMoved == event.type){
                this->CreateMenu();
                if(this->data->input.IsSpriteHover(this->menuItemStart, this->data->window)){
                    if(!this->startHover)
                        this->soundHover.play();
                    this->ResetHover();
                    this->startHover = true;
                    this->menuItemStart.setTextureRect(sf::IntRect(0, 20 + menuSize.y / 2, menuSize.x, 90));
                }else if(this->data->input.IsSpriteHover(this->menuItemOptions, this->data->window)){
                    if(!this->optionsHover)
                        this->soundHover.play();
                    this->ResetHover();
                    this->optionsHover = true;
                    this->menuItemOptions.setTextureRect(sf::IntRect(0, 20+90+ menuSize.y / 2, menuSize.x, 95));
                }else if(this->data->input.IsSpriteHover(this->menuItemCredits, this->data->window)){
                    if(!this->creditsHover)
                        this->soundHover.play();
                    this->ResetHover();
                    this->creditsHover = true;
                    this->menuItemCredits.setTextureRect(sf::IntRect(0, 20+90+95+ menuSize.y / 2, menuSize.x, 86));
                }else if(this->data->input.IsSpriteHover(this->menuItemQuit, this->data->window)){
                    if(!this->quitHover)
                        this->soundHover.play();
                    this->ResetHover();
                    this->quitHover = true;
                    this->menuItemQuit.setTextureRect(sf::IntRect(0, 20+90+95+86+ menuSize.y / 2, menuSize.x, 120));
                }
            }
            
            if(this->data->input.IsSpriteClicked(this->menuItemQuit, sf::Mouse::Button::Left, this->data->window)){
                this->data->window.close();
                this->soundClick.play();
                //this->data->machine.AddState(StateRef(new GameState(this->data)), true);
                //this->data->machine.AddState(StateRef(new SeaGameState(this->data)), true);
            }else if(this->data->input.IsSpriteClicked(this->menuItemStart, sf::Mouse::Button::Left, this->data->window)){
                this->soundClick.play();
                this->musicBackground.setLoop(false);
                this->musicBackground.stop();
                //this->data->machine.AddState(StateRef(new SeaGameState(this->data)), true);
                this->data->machine.AddState(StateRef(new GameState(this->data)), true);
            }else if(this->data->input.IsSpriteClicked(this->menuItemCredits, sf::Mouse::Button::Left, this->data->window)){
                this->soundClick.play();
                //this->musicBackground.setLoop(false);
                //this->musicBackground.stop();
                //this->data->machine.AddState(StateRef(new SeaGameState(this->data)), true);
                this->musicBackground.setLoop(false);
                this->musicBackground.stop();
                this->data->machine.AddState(StateRef(new CreditsState(this->data)), true);
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
