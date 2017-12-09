//
//  StoneController.hpp
//  PROYECTO
//
//  Created by Alex Paredes on 9/12/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#ifndef StoneController_hpp
#define StoneController_hpp

#include <SFML/Graphics.hpp>
#include "../Game.hpp"
#include "iostream"
#include "../GameEntities/StoneEntity.hpp"

namespace DevJAD {
    class StoneController {
        GameDataRef data;
        std::vector<StoneEntity> stones;
        
    public:
        StoneController(GameDataRef _data);
        void Draw();
        void SpawnStones();
        void Update(float dt);
        void SetPosition(int i, sf::Vector2f p);
        sf::Vector2f GetPosition(int i);
        size_t size();
        void Move(unsigned int i, float x, float y);
        const sf::Sprite &GetSprite(int i) const;
    };
}


#endif /* StoneController_hpp */
