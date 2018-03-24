#ifndef MainMenuState_hpp
#define MainMenuState_hpp
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../State.hpp"
#include "../Game.hpp"
#include "../Utils.hpp"
#include "CreditsState.hpp"
#include "MountainState.hpp"
#include "../GameControllers/FileController.hpp"
#include "FinalState.hpp"

namespace DevJAD {
    class MainMenuState : public State {
        GameDataRef data;
        sf::Clock clock;
        sf::Sprite background;
        sf::Sprite title;
        sf::Sprite menu;
        sf::Sprite menuItemStart;
        sf::Sprite menuItemQuit;
        sf::Sprite menuItemOptions;
        sf::Sprite menuItemCredits;
        FileController * fs;
        bool startHover, quitHover;
        bool optionsHover, creditsHover;
        
        unsigned short startMenuPositionX;
        unsigned short startMenuPositionY;
        sf::Music musicBackground;
        sf::Sound soundClick;
        sf::Sound soundHover;
        
    public:
        MainMenuState(GameDataRef data);
        void Init();
        void HandleInput();
        void Update(float dt);
        void Draw(float dt);
        void CreateMenu();
        void ResetHover();
    };

}


#endif /* MainMenuState_hpp */
