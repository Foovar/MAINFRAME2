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
    
    bool Collision::CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2, float ax, float ay, float bx, float by)
    {
        sf::Rect<float> rect1 = sprite1.getGlobalBounds();
        sf::Rect<float> rect2 = sprite2.getGlobalBounds();
        if(ax || ay){
            rect1.width -= ax;
            rect1.height -= ay;
            rect1.top += ay / 2;
            rect1.left += ax / 2;
        }
        if(bx || by){
            rect2.width -= bx;
            rect2.height -= by;
            rect2.top += by / 2;
            rect2.left += bx / 2;
        }
        
        return rect1.intersects(rect2);
    }
    
    bool Collision::CheckSpriteCollision(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2)
    {
        sprite1.setScale(scale1, scale1);
        sprite2.setScale(scale2, scale2);
        return sprite1.getGlobalBounds().intersects(sprite2.getGlobalBounds());
    }
    
    bool Collision::CheckRectCollision(sf::FloatRect rect1, sf::FloatRect rect2){
        return rect1.intersects(rect2);
    }
}
