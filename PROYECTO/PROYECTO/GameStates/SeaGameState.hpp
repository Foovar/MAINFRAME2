//
//  SeaGameState.hpp
//  PROYECTO
//
//  Created by Alex Paredes on 4/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#ifndef SeaGameState_hpp
#define SeaGameState_hpp

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Collision.hpp"
#include "SharkController.hpp"
#include "Flash.hpp"
#include "GameOverState.hpp"
#include "FakeMario.hpp"
#include "Constants.hpp"
#include <sstream>
#include "ShotEntity.hpp"
#include "MarioCharacter.hpp"
#include "ScoreBar.hpp"

namespace DevJAD {
    
    class SeaGameState : public State {
        GameDataRef data;
        sf::Clock clock;
        sf::Clock clockSpawn;
        sf::Clock coralClock;
        sf::Sprite background;
        sf::Sprite coral;
        sf::View viewScreen;
        Collision collision;
        ShotEntity * shotEntity;
        MarioCharacter * marioCharacter;
        ScoreBar * score;
        sf::Sound soundBackground;
        
        sf::Font fontPoints;
        std::vector<sf::Text> textPoints;
        
        SharkController * sharks;
        float maxDuration;
        Flash * flash;
        int gameState;
        
    public:
        SeaGameState(GameDataRef data);
        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);
    };
    
}
#endif /* SeaGameState_hpp */
