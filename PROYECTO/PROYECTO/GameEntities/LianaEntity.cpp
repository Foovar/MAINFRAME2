//
//  LianaEntity.cpp
//  PROYECTO
//
//  Created by Alex Paredes on 26/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#include "LianaEntity.hpp"
#include "iostream"

namespace DevJAD {
    LianaEntity::LianaEntity(GameDataRef _data, sf::Vector2f origin,float r_ ,int signo): data(_data), ropeLine(sf::Triangles,3) {
        this->ropeTexture = this->data->assets.GetTexture("rope");
        //this->ropeTexture.loadFromFile("Assets/images/cuerda.png", sf::IntRect(0,220-r_, 35, r_));
        this->ropeTexture.setSmooth(true);
        this->origin = origin;
        this->armLength = r_;
        this->angle = (signo * M_PI) / 4;
        this->speed = 0.0f;
        this->acceleration = 0.0f;
        this->xPosition = this->origin.x;
        
        this->shapeTest.setRadius(5);
        this->shapeTest.setFillColor(sf::Color::Red);
        this->shapeTest.setOutlineThickness(2);
        this->shapeTest.setOutlineColor(sf::Color(45,97,22));
    }
    
    void LianaEntity::Draw(){
        this->data->window.draw(this->ropeLine, &this->ropeTexture);
        this->data->window.draw(this->shape);
        this->data->window.draw(this->shapeTest);
    }
    
    void LianaEntity::Update(float dt){
        if(this->clock.getElapsedTime().asSeconds() > 0.08){
            float gravity = 1.5;
            this->acceleration = (-1 * gravity / armLength) * sin(this->angle);
            this->speed += this->acceleration;
            this->angle += this->speed;
            
            this->position = sf::Vector2f( ( this->armLength * sin(this->angle) + this->xPosition), this->armLength * cos(this->angle)  );
            // cuerda
            this->ropeLine[0].position = sf::Vector2f(this->origin.x, this->origin.y - 20); // punto de partida
            this->ropeLine[1].position = sf::Vector2f(this->position.x + ( this->armLength * 2), this->position.y);
            this->ropeLine[2].position = sf::Vector2f(this->position.x, this->position.y); // ultimo punto
            
            std::cout << "0x:" << this->ropeLine[2].position.x +20 << "  0y:" << this->ropeLine[2].position.y << " :: " << this->angle << std::endl;
            this->shapeTest.setPosition(this->ropeLine[2].position.x , this->ropeLine[2].position.y - 50);
            // tetura
            this->ropeLine[0].texCoords = sf::Vector2f(0, 0);
            this->ropeLine[1].texCoords = sf::Vector2f(220, this->position.y);
            this->ropeLine[2].texCoords = sf::Vector2f(0, this->position.y);
            
            /*this->shape.setRadius(5);
            this->shape.setFillColor(sf::Color(84,139,22));
            this->shape.setOutlineThickness(2);
            this->shape.setOutlineColor(sf::Color(45,97,22));
            this->shape.setPosition(this->position.x + 20, this->position.y - 5);*/
            this->clock.restart();
        }
    }
    void LianaEntity::SetPosition(sf::Vector2f a){
        this->xPosition = a.x;
        this->origin = a;
    }
    sf::VertexArray LianaEntity::GetRopeLine(){
        return this->ropeLine;
    }
}
