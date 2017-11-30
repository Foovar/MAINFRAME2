//
//  SplashState.hpp
//  PROYECTO
//
//  Created by DevJAD on 2/11/17.
//  Copyright © 2017 DevJAD. All rights reserved.
//

#ifndef SplashState_hpp
#define SplashState_hpp

#include <SFML/Graphics.hpp>
#include "../State.hpp"
#include "../Game.hpp"


namespace DevJAD {
    
    class SplashState : public State {
        GameDataRef data;
        sf::Clock clock;
        sf::Sprite background;
        sf::Sprite logo;
        sf::Sprite extra;
    public:
        SplashState(GameDataRef data);
        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);
        
        void FinishLoad();
        void StartLoad();
    };
    
}

#endif /* SplashState_hpp */
