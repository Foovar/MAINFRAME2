
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
#include "../ScoreBar.hpp"
#include "MountainState.hpp"
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
        ScoreBar * scoreBar;
        
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
