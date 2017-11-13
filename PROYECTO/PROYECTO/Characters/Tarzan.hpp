//
//  Tarzan.hpp
//  PROYECTO
//
//  Created by Alex Paredes on 3/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#ifndef Tarzan_hpp
#define Tarzan_hpp
#include <vector>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Constants.hpp"
#include "iostream"
namespace DevJAD {
    class Tarzan {
        GameDataRef data;
        std::vector<sf::Sprite> animationFrames;
        sf::Sprite tarzanSprite;
        sf::Texture tarzanTexture;
        sf::Clock clock;
        int state, movementX, movementY;
        unsigned int framesInterator;
        
    public:
        Tarzan(GameDataRef _data);
        ~Tarzan();
        void Draw();
        void Animate(float dt);
        void Update(float dt);
        const sf::Sprite &GetSprite() const;
        void SetState(int _state);
        int GetState();
    };
}

#endif /* Tarzan_hpp */
