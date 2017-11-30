//
//  TestState.hpp
//  PROYECTO
//
//  Created by Alex Paredes on 25/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#ifndef TestState_hpp
#define TestState_hpp

#include <SFML/Graphics.hpp>
#include "../State.hpp"
#include "../Game.hpp"
#include "../GameEntities/ShotEntity.hpp"
#include "../Characters/MarioCharacter.hpp"
#include "iostream"

namespace DevJAD {
    
    class TestState : public State {
        GameDataRef data;
        sf::Clock clock;
        ShotEntity * shotEntity;
        MarioCharacter * marioCharacter;
        
    public:
        TestState(GameDataRef data);
        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);
    };
    
}

#endif /* TestState_hpp */
