//
//  GameState.hpp
//  PROYECTO
//
//  Created by Alex Paredes on 3/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#ifndef GameState_hpp
#define GameState_hpp

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Tarzan.hpp"

namespace DevJAD {
    
    class GameState : public State {
        GameDataRef data;
        sf::Clock clock;
        sf::Sprite background;
        Tarzan * tarzan;
        
    public:
        GameState(GameDataRef data);
        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);
    };
    
}

#endif /* GameState_hpp */
