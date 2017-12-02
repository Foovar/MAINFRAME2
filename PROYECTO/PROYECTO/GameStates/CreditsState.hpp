//
//  CreditsState.hpp
//  PROYECTO
//
//  Created by Alex Paredes on 2/12/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#ifndef CreditsState_hpp
#define CreditsState_hpp

#include <SFML/Graphics.hpp>
#include "../State.hpp"
#include "../Game.hpp"
#include "../Constants.hpp"


namespace DevJAD {
    
    class CreditsState : public State {
        GameDataRef data;
        sf::Clock clock;
        sf::Text text;
        
    public:
        CreditsState(GameDataRef data);
        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);
    };
    
}

#endif /* CreditsState_hpp */