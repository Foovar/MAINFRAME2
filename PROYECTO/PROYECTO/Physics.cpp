//
//  Physics.cpp
//  PROYECTO
//
//  Created by Alex Paredes on 2/12/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#include "Physics.hpp"

namespace DevJAD {
    Physics::Physics(float x0, float y0, float angle, float power, float ax, float ay){
        this->x0 = x0;
        this->y0 = y0;
        this->angle = angle;
        this->power = power;
        this->ax = ax;
        this->ay = ay;
        //this->v = { cos(this->AngleToRad(angle)) *  power, -sin(this->AngleToRad(angle)) * power };
        this->v = { power * cos(this->AngleToRad(angle)), power *  sin(AngleToRad(angle)) };
    }
    
    sf::Vector2f Physics::GetPosAtTime(float time) {
        return {  this->x0 + this->v.x*time, this->y0 - ( (this->v.y*time)-(float)((this->ay/2)*(time*time)) ) } ;
    }
    
    float Physics::AngleToRad(float a){
        return a * 3.14159265358979323846 / 180;
    }
}
