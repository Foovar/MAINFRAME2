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
#include "../State.hpp"
#include "../Game.hpp"
#include <vector>
#include "iostream"
#include "../GameControllers/LianaController.hpp"
#include "../Characters/MarioCharacter.hpp"
#include "../Collision.hpp"
#include "../GameControllers/TipsController.hpp"
#include "../GameControllers/BranchesController.hpp"
#include "GameOverState.hpp"
#include "SeaGameState.hpp"


namespace DevJAD {
    
    class GameState : public State {
        GameDataRef data;
        std::vector<sf::Sprite> backgroundChange;
        sf::Clock clock;
        sf::View viewScreen;
        float backgrounSize, viewAccum, movingScreen, alphaGameOver;
        LianaController * lianas;
        TipsController * tips;
        BranchesController * branches;
        MarioCharacter * marioCharacter;
        Collision * collision;
        int currentLiana;
        sf::Music musicBackground;
        bool isGameOver, isWon;
        sf::RectangleShape shapeGameOver;
        sf::Sound deadSound;
        
    public:
        GameState(GameDataRef data);
        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);
        
        void MoveNextScreen();
        void SpawnTipsAndBranches();
    };
    
}

#endif /* GameState_hpp */
