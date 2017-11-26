//
//  MarioCharacter.hpp
//  PROYECTO
//
//  Created by Alex Paredes on 26/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#ifndef MarioCharacter_hpp
#define MarioCharacter_hpp

#include "Game.hpp"
#include "ShotEntity.hpp"

namespace DevJAD {
    class MarioCharacter {
        GameDataRef data;
        sf::Sprite spriteCharacter;
        int moveType, characterStatus, frameInterator, totalFrames, defaultState;
        float framePosY, framePosX, moveAmount;
        float switchTime;
        int movementX, movementY;
        bool attackCompleted;
        ShotEntity * shotEntity;
        sf::Clock clock;
    public:
        MarioCharacter(GameDataRef _data);
        void Draw();
        void Animate(float dt);
        void Update(float dt);
        void Move(int type);
        const sf::Sprite &GetSprite() const;
        void SetState(int state);
        int GetState();
        void SetDefaultState(int state);
        bool hasShoot();
        const sf::Sprite &GetShootSprite() const;
    };
}

#endif /* MarioCharacter_hpp */
