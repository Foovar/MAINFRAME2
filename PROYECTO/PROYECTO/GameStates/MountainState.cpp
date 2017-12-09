//
//  MountainState.cpp
//  PROYECTO
//
//  Created by Alex Paredes on 8/12/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#include "MountainState.hpp"

namespace DevJAD {
    
    MountainState::MountainState(GameDataRef data){
        this->data = data;
    }
    
    void MountainState::Init(){
        this->coline.setTexture(this->data->assets.GetTexture("mt coline"));
        this->background.setTexture(this->data->assets.GetTexture("mt background"));
        if(this->data->screenType == SCREEN_SIZE_TYPE_MEDIUM){
            this->background.setScale(0.2, 0.3);
            this->coline.setPosition(0, this->data->window.getSize().y - (this->coline.getGlobalBounds().height / 2.5));
        }
        this->stones = new StoneController(this->data);
        this->mario = new MarioCharacter(this->data);
        this->collision = new Collision;
        this->mario->SetDefaultState(CHARACTER_STATE_WALK);
        this->mario->SetPosition(300, this->coline.getPosition().y + 250);
        this->mario->SetRotate(-13);
        this->colineRotate = true;
        //this->coline.setOrigin(this->coline.getGlobalBounds().width/2, this->coline.getLocalBounds().height/2);
    }
    
    void MountainState::HandleInput(){
        sf::Event event;
        while (this->data->window.pollEvent(event)) {
            if(sf::Event::Closed == event.type) this->data->window.close();
            if(this->data->input.IsJumping(event.key.code)){
                this->mario->Jump();
            }
        }
    }
    
    void MountainState::Update(float dt){
        
        if(this->mario->GetState() != CHARACTER_STATE_DEAD){
            
            this->stones->Update(dt);
            
            for (unsigned int i = 0; i < this->stones->size(); i++) {
                if(this->stones->GetPosition(i).x < this->data->window.getSize().x / 2){
                    this->stones->Move(i, -(dt * 230), 0.4);
                }else{
                    this->stones->Move(i, -(dt * 230), 1.1);
                }
            }
            if(this->clockStone.getElapsedTime().asSeconds() > 2){
                this->stones->SpawnStones();
                this->stones->SetPosition(this->stones->size() - 1.f, sf::Vector2f(this->data->window.getSize().x, this->coline.getPosition().y + 130));
                this->clockStone.restart();
            }
            
            if(this->mario->GetSprite().getPosition().y > (this->coline.getPosition().y + 250) ){
                this->mario->SetPosition(this->mario->GetSprite().getPosition().x, this->coline.getPosition().y + 250);
                this->mario->SetState(CHARACTER_STATE_WALK);
            }
            
            for(unsigned int i = 0; i < this->stones->size(); i++){
                if(this->collision->CheckSpriteCollision(this->mario->GetSprite(), this->stones->GetSprite(i),20, 10, 40, 10 )){
                    this->mario->SetState(CHARACTER_STATE_DEAD);
                    this->data->machine.AddState(StateRef(new GameOverState(this->data)), true);
                }
            }
            
            
            
            this->mario->Update(dt);
            this->mario->Animate(dt);
        }
    }
    
    void MountainState::Draw(float dt){
        //this->data->window.clear(sf::Color::White);
        this->data->window.draw(this->background);
        this->data->window.draw(this->coline);
        this->mario->Draw();
        this->stones->Draw();
        this->data->window.display();
    }
    
}
