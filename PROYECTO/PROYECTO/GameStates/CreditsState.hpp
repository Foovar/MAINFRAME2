

#ifndef CreditsState_hpp
#define CreditsState_hpp

#include <SFML/Graphics.hpp>
#include "../State.hpp"
#include "../Game.hpp"
#include "../Constants.hpp"
#include "MainMenuState.hpp"

namespace DevJAD {
    
    class CreditsState : public State {
        GameDataRef data;
        sf::Clock clock;
        sf::Text text;
        sf::Text team;
        sf::Text title1;
        sf::Text title2;
        sf::Music musicBackground;
        sf::Sprite logo;
        
    public:
        CreditsState(GameDataRef data);
        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);
    };
    
}

#endif /* CreditsState_hpp */
