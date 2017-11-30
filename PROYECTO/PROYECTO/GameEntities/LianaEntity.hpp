//
//  LianaEntity.hpp
//  PROYECTO
//
//  Created by Alex Paredes on 26/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#ifndef LianaEntity_hpp
#define LianaEntity_hpp
#include <SFML/Graphics.hpp>
#include "../Game.hpp"
#define M_PI 3.14159265358979323846
#include <math.h>

namespace DevJAD {
    class LianaEntity {
        GameDataRef data;
        sf::CircleShape shape;
        sf::CircleShape shapeTest;
        sf::Texture ropeTexture;
        sf::VertexArray ropeLine;
        sf::Vector2f position;
        sf::Vector2f origin;
        float armLength, angle, acceleration, speed, xPosition;
        sf::Clock clock;
        
    public:
        LianaEntity(GameDataRef _data);
        LianaEntity(GameDataRef _data, sf::Vector2f origin,float r_ ,int signo);
        void Animate(float dt);
        void Update(float dt);
        void Draw();
        sf::VertexArray GetRopeLine();
        void SetPosition(sf::Vector2f a);
    };
}

#endif /* LianaEntity_hpp */
