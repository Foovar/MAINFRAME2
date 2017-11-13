//
//  Collision.cpp
//  PROYECTO
//
//  Created by Alex Paredes on 5/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#include "Collision.hpp"
namespace DevJAD {
    Collision::Collision(){
        
    }
    Collision::~Collision(){
        
    }
    
    bool Collision::CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2)
    {
        return sprite1.getGlobalBounds().intersects(sprite2.getGlobalBounds());
    }
    
    bool Collision::CheckSpriteCollision(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2)
    {
        sprite1.setScale(scale1, scale1);
        sprite2.setScale(scale2, scale2);
        
        return sprite1.getGlobalBounds().intersects(sprite2.getGlobalBounds());
    }
}
