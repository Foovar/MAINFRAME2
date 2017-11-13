//
//  Game.hpp
//  PROYECTO
//
//  Created by Alex Paredes on 2/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetsManager.hpp"
#include "InputManager.hpp"

namespace DevJAD {
    struct GameData{
        StateMachine machine;
        sf::RenderWindow window;
        AssetsManager assets;
        InputManager input;
    };
    
    typedef std::shared_ptr<GameData> GameDataRef;
    
    class Game {
        const float dt = 1.0f / 60.0f;
        sf::Clock clock;
        GameDataRef data = std::make_shared<GameData>();
        void Run();
    public:
        Game(int width, int height, std::string title);
    };
    
}

#endif /* Game_hpp */
