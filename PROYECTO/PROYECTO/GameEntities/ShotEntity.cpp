

#include "../GameEntities/ShotEntity.hpp"
#include "iostream"

namespace DevJAD {
    ShotEntity::ShotEntity(GameDataRef _data){
        this->data = _data;
        this->totalFrames = 10;
        this->frameInterator = 0;
        this->switchTime = 0.1f;
        this->hasShot = true;
        this->shotSprite.setTexture(this->data->assets.GetTexture("character 02"));
        this->shotSprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
        if(this->data->screenType == SCREEN_SIZE_TYPE_MEDIUM)
            this->shotSprite.setScale(0.7f, 0.7f);
    }
    
    void ShotEntity::Draw(){
        this->data->window.draw(this->shotSprite);
    }
    void ShotEntity::Shoot(sf::Vector2f pos){
        if(!this->hasShot) return;
        this->shotSprite.setPosition(pos);
        this->hasShot = false;
    }
    void ShotEntity::Animate(float dt){
        if(!this->hasShot) {
            if(this->clock.getElapsedTime().asSeconds() > this->switchTime){
                this->shotSprite.setTextureRect(sf::IntRect( this->frameInterator * 110, 175, 110, 90 ));
                if(this->frameInterator > this->totalFrames - 1){
                    this->frameInterator = 0; this->hasShot = true;
                }else this->frameInterator++;
                this->clock.restart();
            }
            if(this->data->screenType == SCREEN_SIZE_TYPE_MEDIUM)
                this->shotSprite.move(dt * 300, 0);
            else
                this->shotSprite.move(dt * 600, 0);
        }
    }
    void ShotEntity::Update(float dt){
        
    }
    void ShotEntity::Move(float x, float y, float dt){
        
    }
    const sf::Sprite &ShotEntity::GetSprite() const {
        return this->shotSprite;
    }
    
    bool ShotEntity::hasShoot(){
        return this->hasShot;
    }
}
