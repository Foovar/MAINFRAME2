//
//  LianaController.hpp
//  PROYECTO
//
//  Created by Alex Paredes on 26/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#ifndef LianaController_hpp
#define LianaController_hpp
#include "../Game.hpp"
#include "../GameEntities/LianaEntity.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include "iostream"

namespace DevJAD {
    class LianaController {
        GameDataRef data;
        std::vector<LianaEntity> lianas;
        
    public:
        LianaController(GameDataRef _data);
        void Draw();
        void SpawnLianas();
        void Update(float dt);
        void SetPosition(int i, sf::Vector2f p);
        sf::Vector2f GetPosition(int i);
    };
}

#endif /* LianaController_hpp */
