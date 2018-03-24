//
//  FinalState.hpp
//  PROYECTO
//
//  Created by Alex Paredes on 9/12/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#ifndef FinalState_hpp
#define FinalState_hpp
#include "../Game.hpp"
#include "../Characters/MarioCharacter.hpp"

namespace DevJAD {
    class FinalState : public State {
        GameDataRef data;
        sf::Sprite background;
        sf::Music musicBackground;
        MarioCharacter * marioSprite;
        int scoreTotal;
        bool is_SetPosition;
    public:
        FinalState(GameDataRef data, int score = 0);
        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);
    };
    
}


#endif /* FinalState_hpp */
