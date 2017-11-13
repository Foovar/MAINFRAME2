//
//  SharkEntity.hpp
//  PROYECTO
//
//  Created by Alex Paredes on 8/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#ifndef SharkEntity_hpp
#define SharkEntity_hpp
#include "Constants.hpp"
#include <SFML/Graphics.hpp>
#include <math.h>
#include "iostream"

namespace DevJAD {
    
    struct AnimationEntityData {
        sf::Sprite sprite;
        unsigned int totalFrames;
        sf::IntRect sizes;
        float switchTime;
        
        AnimationEntityData(sf::Sprite a, sf::IntRect b, unsigned int d, float e = 0.1){
            sprite = a;
            sprite.setTextureRect(b);
            sprite.setScale(0.8, 0.8);
            totalFrames = d;
            switchTime = e;
            sizes = b;
        }
    };
    
    class SharkEntity {
        int entityState;
        unsigned frameInterator;
        sf::Clock clock;
        sf::Clock clockSin;
        float switchTime;
        sf::IntRect entityRect;
        sf::Sprite entitySprite;
        AnimationEntityData * attack;
        AnimationEntityData * swimming;
        AnimationEntityData * die;
        
    public:
        SharkEntity(sf::Texture &texture);
        
        AnimationEntityData * GetCurrentAnimationData();
        void SetPosition(float x, float y);
        void SetState(int state);
        void Update(float dt);
        void Animate(float dt);
        void Move(float x, float y);
        int GetState();
        const sf::Sprite &GetSprite() const;
    };

}
#endif /* SharkEntity_hpp */
