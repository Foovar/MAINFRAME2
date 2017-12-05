

#ifndef Game_hpp
#define Game_hpp

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "Constants.hpp"
#include "StateMachine.hpp"
#include "AssetsManager.hpp"
#include "InputManager.hpp"

namespace DevJAD {
    struct GameData{
        StateMachine machine;
        sf::RenderWindow window;
        AssetsManager assets;
        InputManager input;
        int screenType;
    };
    
    typedef std::shared_ptr<GameData> GameDataRef;
    
    class Game {
        const float dt = 1.0f / 60.0f;
        sf::Clock clock;
        GameDataRef data = std::make_shared<GameData>();
        void Run();
    public:
        Game(std::string title, int screen_type = SCREEN_SIZE_TYPE_MEDIUM);
    };
    
}

#endif /* Game_hpp */
