
#ifndef SeaGameState_hpp
#define SeaGameState_hpp

#include <SFML/Graphics.hpp>
#include "../State.hpp"
#include "../Game.hpp"
#include "../Collision.hpp"
#include "../GameControllers/SharkController.hpp"
#include "../Flash.hpp"
#include "GameOverState.hpp"
#include "../Constants.hpp"
#include <sstream>
#include "../GameEntities/ShotEntity.hpp"
#include "../Characters/MarioCharacter.hpp"
#include "../ScoreBar.hpp"
#include "WinState.hpp"
#include "MountainState.hpp"

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
        sf::Music musicBackground;
        sf::Font fontPoints;
        std::vector<sf::Text> textPoints;
        bool isGameOver, isWon;
        sf::RectangleShape shapeGameOver;
         sf::Sound deadSound;
        SharkController * sharks;
        float maxDuration, alphaGameOver;
        Flash * flash;
        int gameState, prevScore;
        
    public:
        SeaGameState(GameDataRef data, int score = 0);
        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);
    };
    
}
#endif /* SeaGameState_hpp */
