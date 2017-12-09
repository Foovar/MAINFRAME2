//
//  StoneEntity.hpp
//  PROYECTO
//
//  Created by Alex Paredes on 8/12/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#ifndef StoneEntity_hpp
#define StoneEntity_hpp
#include "SFML/Graphics.hpp"
#include "../Game.hpp"

namespace DevJAD {
    
    class StoneEntity {
        GameDataRef data;
        sf::Sprite StoneSprite;
        int totalFrames, frameInterator;
        float switchTime;
        sf::Clock clock;
    public:
        StoneEntity(GameDataRef _data);
        void Update(float dt);
        void Animate(float dt);
        void Move(float x, float y);
        void Draw();
        void setPosition(float x, float y);
        const sf::Sprite &GetSprite() const;
    };
}

#endif /* StoneEntity_hpp */
