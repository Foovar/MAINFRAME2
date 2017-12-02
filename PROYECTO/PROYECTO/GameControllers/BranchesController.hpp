//
//  BranchesController.hpp
//  PROYECTO
//
//  Created by Alex Paredes on 2/12/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#ifndef BranchesController_hpp
#define BranchesController_hpp

#include <SFML/Graphics.hpp>
#include "../Game.hpp"

namespace DevJAD {
    class BranchesController {
        GameDataRef data;
        std::vector<sf::Sprite> branches;
        
    public:
        BranchesController(GameDataRef _data);
        void Draw();
        void SpawnBranches();
        void Update(float dt);
        void SetPosition(int i, sf::Vector2f p);
        sf::Vector2f GetPosition(int i);
    };
}
#endif /* BranchesController_hpp */
