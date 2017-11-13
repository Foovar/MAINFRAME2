//
//  MainMenuState.hpp
//  PROYECTO
//
//  Created by Alex Paredes on 2/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#ifndef MainMenuState_hpp
#define MainMenuState_hpp
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace DevJAD {
    
    class MainMenuState : public State {
        GameDataRef data;
        sf::Clock clock;
        sf::Sprite background;
        sf::Sprite title;
        sf::Sprite menu;
        sf::Sprite menuItemStart;
        sf::Sprite menuItemQuit;
        sf::Sprite menuItemOptions;
        sf::Sprite menuItemCredits;
        unsigned short startMenuPositionX;
        unsigned short startMenuPositionY;
        
    public:
        MainMenuState(GameDataRef data);
        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);
        void CreateMenu();
    };

}


#endif /* MainMenuState_hpp */
