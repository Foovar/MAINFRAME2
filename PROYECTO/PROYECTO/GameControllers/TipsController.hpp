
#ifndef TipsController_hpp
#define TipsController_hpp
#include <SFML/Graphics.hpp>
#include "../Game.hpp"
#include "iostream"

namespace DevJAD {
    class TipsController {
        GameDataRef data;
        std::vector<sf::Sprite> tips;
        
    public:
        TipsController(GameDataRef _data);
        void Draw();
        void SpawnTips();
        void Update(float dt);
        void SetPosition(int i, sf::Vector2f p);
        sf::Vector2f GetPosition(int i);
    };
}


#endif /* TipsController_hpp */
