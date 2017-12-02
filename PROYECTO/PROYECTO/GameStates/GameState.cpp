//
//  GameState.cpp
//  PROYECTO
//
//  Created by Alex Paredes on 3/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#include <sstream>
#include "GameState.hpp"
#include "../Constants.hpp"
#include <iostream>

namespace DevJAD {
    
    GameState::GameState(GameDataRef data){
        this->data = data;
    }
    
    void GameState::Init(){
        this->marioCharacter = new MarioCharacter(this->data);
        this->data->assets.LoadTexture("rope", "Assets/images/cuerda.png");
        this->viewScreen = sf::View(this->data->window.getDefaultView());
        sf::Sprite background(this->data->assets.GetTexture("forest background"));
        this->isGameOver = false;
        this->data->assets.LoadTexture("tip", TIPS_FILEPATH);
        this->data->assets.LoadTexture("branch", BRANCH_FILEPATH);
        
        this->musicBackground.openFromFile(FOREST_MUSIC_BACKGROUND);
        this->musicBackground.setLoop(true);
        this->musicBackground.play();
        this->alphaGameOver = 0;
        
        background.setScale(0.5, 0.5);
        if(this->data->screenType == SCREEN_SIZE_TYPE_MEDIUM)
            background.setScale(0.3, 0.30);
        this->backgroundChange.push_back(background);
        background.setPosition(background.getGlobalBounds().width, 0);
        this->backgroundChange.push_back(background);
        background.setPosition(background.getGlobalBounds().width * 2, 0);
        this->backgroundChange.push_back(background);
        background.setPosition(background.getGlobalBounds().width * 3, 0);
        
        this->shapeGameOver.setSize(sf::Vector2f(background.getGlobalBounds().width * this->backgroundChange.size(), this->data->window.getSize().y));
        this->isGameOver = false;
        this->isWon = false;
        
        this->tips = new TipsController(this->data);
        this->currentLiana = 0;
        this->backgrounSize = background.getGlobalBounds().width;
        this->viewAccum = 0;
        this->marioCharacter->SetDefaultState(CHARACTER_STATE_HANG);
        this->lianas = new LianaController(this->data);
        this->branches = new BranchesController(this->data);
        this->collision = new Collision;
        this->movingScreen = false;
        this->SpawnTipsAndBranches();
        for(int i = 0; i < 8; i++){
            this->lianas->SpawnLianas();
        }
        this->shapeGameOver.setFillColor(sf::Color(255, 255, 255, 0));
        this->deadSound.setBuffer(this->data->assets.GetSoundBuffer("dead sound"));
    }
    
    void GameState::SpawnTipsAndBranches(){
        for(int i = 0; i < 15; i++){
            this->tips->SpawnTips();
            this->branches->SpawnBranches();
        }
    }
    
    void GameState::MoveNextScreen(){
        if(this->movingScreen) return;
        //this->lianas->SpawnLianas();
        this->SpawnTipsAndBranches();
        this->movingScreen = true;
        this->clock.restart();
        this->currentLiana++;
    }
    
    void GameState::HandleInput(){
        sf::Event event;
        
        while (this->data->window.pollEvent(event)) {
            if(sf::Event::Closed == event.type) this->data->window.close();
            if(this->data->input.IsJumping(event.key.code) && !this->movingScreen){
                this->marioCharacter->Jump();
            }
        }
    }
    
    void GameState::Update(float dt){
        this->lianas->Update(dt);
        if(this->movingScreen){
            if(this->clock.getElapsedTime().asSeconds() < (this->currentLiana < 2 ? 0.6 : 0.8)){
                this->viewScreen.move(dt * 520, 0);
                this->viewAccum += dt * 520;
            }else {
                this->movingScreen = false;
            }
        }
        
        sf::Vector2f lposition = this->lianas->GetPosition(this->currentLiana);
        
        if(this->marioCharacter->GetState() == CHARACTER_STATE_HANG){
            
            this->marioCharacter->SetPosition(lposition.x - this->marioCharacter->GetSprite().getGlobalBounds().width / 2, lposition.y - this->marioCharacter->GetSprite().getGlobalBounds().height / 2);
        }else if(this->currentLiana < 7){
            lposition = this->lianas->GetPosition(this->currentLiana + 1);
            if(this->collision->CheckRectCollision(this->marioCharacter->GetSprite().getGlobalBounds(), sf::FloatRect( lposition.x, lposition.y - 10, 5, 20 ))){
                this->marioCharacter->SetState(CHARACTER_STATE_HANG);
                this->MoveNextScreen();
                if(this->currentLiana == 6) this->isWon = true;
            }
        }
        
        if(this->marioCharacter->GetPosition().y > this->data->window.getSize().y - 280){
            if(!this->isWon){
                this->marioCharacter->SetState(CHARACTER_STATE_DEAD);
                this->deadSound.play();
            }
            this->isGameOver = true;
            this->clock.restart();
        }
        
        this->marioCharacter->Update(dt);
        this->marioCharacter->Animate(dt);
        
        if(this->isGameOver && this->alphaGameOver >= 255){
            this->musicBackground.stop();
            if(!this->isWon)
                this->data->machine.AddState(StateRef(new GameOverState(this->data)));
            else
                this->data->machine.AddState(StateRef(new SeaGameState(this->data)), true);
        }
        
    }
    
    void GameState::Draw(float dt){
        this->data->window.clear(sf::Color::White);
        this->data->window.setView(this->viewScreen);
        for(unsigned int i = 0; i < this->backgroundChange.size(); i++){
            this->data->window.draw( this->backgroundChange.at(i) );
        }
        this->lianas->Draw();
        this->marioCharacter->Draw();
        this->tips->Draw();
        this->branches->Draw();
        if(this->isGameOver){
            this->shapeGameOver.setFillColor(sf::Color(255, 255, 255, this->alphaGameOver));
            this->data->window.draw(this->shapeGameOver);
            if(alphaGameOver < 255 - dt * 5)
                alphaGameOver += dt * 5;
            else
                alphaGameOver = 255;
        }
        this->data->window.display();
    }
    
}
