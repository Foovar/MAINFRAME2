//
//  MountainState.hpp
//  PROYECTO
//
//  Created by Alex Paredes on 8/12/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#ifndef MountainState_hpp
#define MountainState_hpp
#include <SFML/Graphics.hpp>
#include <math.h>
#include "../Game.hpp"
#include "../GameControllers/StoneController.hpp"
#include "../GameEntities/StoneEntity.hpp"
#include "../Characters/MarioCharacter.hpp"
#include "iostream"
#include "../Collision.hpp"
#include "GameOverState.hpp"
#include "WinState.hpp"
#include "../ScoreBar.hpp"

namespace DevJAD {
    class MountainState : public State {
        GameDataRef data;
        sf::Sprite background;
        sf::Music musicBackground;
        sf::Sound soundLose;
        sf::Sprite coline;
        StoneEntity * stone;
        MarioCharacter * mario;
        sf::Clock clockStone;
        sf::Clock colineClock;
        sf::Vector2f lastPosition;
        bool colineRotate;
        Collision * collision;
        StoneController * stones;
        int avoidStones, prevScore;
        bool isGameOver, isWin;
        ScoreBar * scoreBar;
        
    public:
        MountainState(GameDataRef data, int score = 0);
        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);
    };
    
}


#endif /* MountainState_hpp */
