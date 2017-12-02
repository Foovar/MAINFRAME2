//
//  WinState.hpp
//  PROYECTO
//
//  Created by Alex Paredes on 2/12/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#ifndef WinState_hpp
#define WinState_hpp

#include <SFML/Graphics.hpp>
#include "../State.hpp"
#include "../Game.hpp"
#include "../Constants.hpp"

namespace DevJAD {
    
    class WinState : public State {
        GameDataRef data;
        sf::Clock clock;
        sf::Sprite winCharacter;
        sf::Sprite winText;
        int frameInterator;
    public:
        WinState(GameDataRef data);
        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);
    };
    
}

#endif /* WinState_hpp */
