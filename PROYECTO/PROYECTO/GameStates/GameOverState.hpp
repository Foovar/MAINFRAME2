
#ifndef GameOverState_hpp
#define GameOverState_hpp
#include <SFML/Graphics.hpp>
#include "../State.hpp"
#include "../Game.hpp"
#include "../Constants.hpp"
#include "iostream"

namespace DevJAD {
    
    class GameOverState : public State {
        GameDataRef data;
        sf::Clock clock;
        sf::Sprite box;
        sf::Sprite background;
        sf::Sprite buttonReStart;
        sf::Sprite buttonExit;
        int score;
        sf::Text scoreText;
        
        
    public:
        GameOverState(GameDataRef data, int score = 0);
        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);
    };
    
}
#endif /* GameOverState_hpp */
