//
//  SeaGameState.cpp
//  PROYECTO
//
//  Created by Alex Paredes on 4/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#include "SeaGameState.hpp"

namespace DevJAD {
    
    SeaGameState::SeaGameState(GameDataRef data){
        this->data = data;
        this->viewScreen = sf::View(this->data->window.getDefaultView());
        this->maxDuration = this->viewScreen.getSize().x;
        this->gameState = IS_PLAYING;
        this->fontPoints.loadFromFile("Assets/fonts/display.ttf");
    }
    
    void SeaGameState::Init(){
        this->data->assets.LoadTexture("shark", SHARK_FILEPATH);
        this->data->assets.LoadTexture("sea coral", SEA_CORAL_FILEPATH);
        this->musicBackground.openFromFile(SEA_MUSIC_BACKGROUND);
        
        this->background.setTexture(this->data->assets.GetTexture("sea background"));
        this->coral.setTexture(this->data->assets.GetTexture("sea coral"));
        
        this->marioCharacter = new MarioCharacter(this->data);
        this->marioCharacter->SetDefaultState(CHARACTER_STATE_SWIM);
        
        this->sharks = new SharkController(this->data);
        this->flash = new Flash(this->data, this->background.getGlobalBounds().width, this->data->window.getSize().y);
        this->score = new ScoreBar(this->data);
        
        if(this->data->screenType == SCREEN_SIZE_TYPE_MEDIUM){
            this->background.setScale(this->background.getScale().x, 0.6);
            this->coral.setScale(this->coral.getScale().x, 0.6);
            this->sharks->SetScale(0.5, 0.5);
        }
        this->coral.setPosition(0, this->background.getGlobalBounds().height - this->coral.getGlobalBounds().height);
        this->musicBackground.setVolume(50.f);
        this->musicBackground.play();
    }
    
    void SeaGameState::HandleInput(){
        sf::Event event;
        
        while (this->data->window.pollEvent(event)) {
            if(sf::Event::Closed == event.type) this->data->window.close();
            
            if(sf::Event::KeyPressed == event.type || sf::Event::KeyReleased == event.type){
                float originalXPos = this->viewScreen.getCenter().x - this->marioCharacter->GetSprite().getPosition().x;
                
                if(event.key.code == sf::Keyboard::Up){
                    if(this->marioCharacter->GetSprite().getPosition().y > this->background.getGlobalBounds().height / 2)
                        this->marioCharacter->Move(CHARACTER_MOVE_UP);
                }else if(event.key.code == sf::Keyboard::Down){
                    if(this->marioCharacter->GetSprite().getPosition().y < this->background.getGlobalBounds().height - (this->coral.getGlobalBounds().height / 2))
                        this->marioCharacter->Move(CHARACTER_MOVE_DOWN);
                }else if(event.key.code == sf::Keyboard::Left){
                    if(this->viewScreen.getSize().x / 2 - originalXPos > 0)
                        this->marioCharacter->Move(CHARACTER_MOVE_LEFT);
                }else if(event.key.code == sf::Keyboard::Right){
                    if(originalXPos * -1 < (this->viewScreen.getSize().x / 2 - this->marioCharacter->GetSprite().getLocalBounds().width))
                        this->marioCharacter->Move(CHARACTER_MOVE_RIGTH);
                }else if(event.key.code == sf::Keyboard::X){
                    this->marioCharacter->SetState(CHARACTER_STATE_ATTACK);
                }
            }
        }
    }
    
    void SeaGameState::Update(float dt){
        if(this->marioCharacter->GetState() != CHARACTER_STATE_DEAD){
            this->marioCharacter->Update(dt);
            this->marioCharacter->Animate(dt);
        }
        
        if(this->gameState != IS_GAME_OVER){
            
            std::vector<SharkEntity> sharkEntities = this->sharks->GetEntities();
            
            for(unsigned short int i = 0; i< sharkEntities.size(); i++){
                if(this->sharks->GetSharkState(i) != SHARK_DIE){
                    sf::FloatRect sharkRect = sharkEntities.at(i).GetSprite().getGlobalBounds();
                    sharkRect.width += 100;
                    sharkRect.left -= 100;
                    if(this->collision.CheckRectCollision(sharkRect, this->marioCharacter->GetSprite().getGlobalBounds() )){
                        this->sharks->SetSharkState(i, SHARK_ATTACK);
                        this->sharks->MoveShark(i, -(dt * 130), 0);
                    }else this->sharks->SetSharkState(i, SHARK_SWIMMING);
                    
                    if(this->collision.CheckSpriteCollision(sharkEntities.at(i).GetSprite(), this->marioCharacter->GetSprite(), 20, 20, 30, 20 )){
                        this->sharks->SetSharkState(i, SHARK_ATTACK);
                        this->marioCharacter->SetState(CHARACTER_STATE_DEAD);
                        this->gameState = IS_GAME_OVER;
                        this->musicBackground.stop();
                        this->clock.restart();
                    }
                }
            }
            
            for(unsigned short int i = 0; i< sharkEntities.size(); i++){
                if(!this->marioCharacter->hasShoot() && this->sharks->GetSharkState(i) != SHARK_DIE){
                    if(this->collision.CheckSpriteCollision(this->marioCharacter->GetShootSprite(), sharkEntities.at(i).GetSprite())){
                        this->sharks->SetSharkState(i, SHARK_DIE);
                        
                        sf::Vector2f a = sf::Vector2f(this->marioCharacter->GetShootSprite().getPosition().x + this->marioCharacter->GetShootSprite().getGlobalBounds().width, this->marioCharacter->GetShootSprite().getPosition().y + this->marioCharacter->GetShootSprite().getGlobalBounds().height);
                        
                        sf::Vector2f b = sharkEntities.at(i).GetSprite().getPosition();
                        int points = (int) (50 + ((a.x - b.x) * (a.y - b.y)));
                        points > 300 && ( points = 300 );
                        sf::Text text(std::to_string((int)(points/2) ) , this->fontPoints);
                        this->score->AddScore((int)(points/2) );
                        
                        text.setCharacterSize(35);
                        text.setStyle(sf::Text::Bold);
                        text.setPosition( sharkEntities.at(i).GetSprite().getPosition() );
                        this->textPoints.push_back(text);
                    }
                }
            }
            
            for(unsigned int i = 0; i < this->textPoints.size(); i++){
                if(this->textPoints.at(i).getFillColor().a > 0)
                    this->textPoints.at(i).setFillColor(sf::Color(255, 255, 255, this->textPoints.at(i).getFillColor().a - 5 ));
                else
                    this->textPoints.erase(this->textPoints.begin() + i );
            }
            
            int maxDuration = this->data->screenType == SCREEN_SIZE_TYPE_MEDIUM ? 100 : 200;
            this->sharks->UpdateSharks(dt);
            
            if(this->clock.getElapsedTime().asSeconds() > 0.01) {
                if(this->maxDuration < this->background.getGlobalBounds().width){
                    this->viewScreen.move((dt*maxDuration), 0);
                    this->maxDuration+=dt*maxDuration;
                }else{
                    this->flash->Show(dt);
                    //this->gameState = IS_GAME_OVER;
                } // level terminado -> pasar al siguiente nivel.
                this->clock.restart();
            }
            
            
            if(this->coralClock.getElapsedTime().asSeconds() > 0.02){
                if(this->maxDuration < this->background.getGlobalBounds().width){
                    this->coral.move(dt * (maxDuration / 2), 0);
                }
            }
            
            if(clockSpawn.getElapsedTime().asSeconds() > 1){
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
        this->sharks->DrawSharks();
        this->marioCharacter->Draw();
        for(int i = 0; i < this->textPoints.size(); i++){
            this->data->window.draw(this->textPoints.at(i));
        }
        this->score->Draw();
        this->flash->Draw();
        this->data->window.display();
    }
    
}
