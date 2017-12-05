

#ifndef WinState_hpp
#define WinState_hpp

#include <SFML/Graphics.hpp>
#include "../State.hpp"
#include "../Game.hpp"
#include "../Constants.hpp"

namespace DevJAD {
    
    class WinState : public State {
        GameDataRef data;
        sf::Clock clock;
        sf::Sprite winCharacter;
        sf::Sprite winText;
        sf::Text textScore;
        sf::Music finishMusic;
        int frameInterator;
        int score;
        
    public:
        WinState(GameDataRef data, int score = 0);
        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);
    };
    
}

#endif /* WinState_hpp */
