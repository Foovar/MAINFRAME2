//
//  SharkController.hpp
//  PROYECTO
//
//  Created by Alex Paredes on 8/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#ifndef SharkController_hpp
#define SharkController_hpp
#include <SFML/Graphics.hpp>
#include <vector>
#include "SharkEntity.hpp"
#include "Game.hpp"
#include <cstdlib>
#include <ctime>
#include "iostream"
#include "Collision.hpp"

namespace DevJAD {
    class SharkController{
        std::vector<SharkEntity> sharks;
        GameDataRef data;
        Collision collision;
    public:
        SharkController(GameDataRef data);
        void MoveSharks(float dt);
        void UpdateSharks(float dt);
        void DrawSharks();
        void SpawnSharks();
        bool IsCollide(int i, sf::Sprite sprite);
        void SetSharkState(int shark, int state);
        const std::vector<SharkEntity> &GetEntities() const;
    };
}

#endif /* SharkController_hpp */
