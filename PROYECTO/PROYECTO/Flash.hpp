

#ifndef Flash_hpp
#define Flash_hpp

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Constants.hpp"

namespace DevJAD
{
    class Flash
    {
    public:
        Flash(GameDataRef data);
        Flash(GameDataRef data, float width, float height);
        ~Flash();
        
        void Show(float dt);
        void Draw();
        
    private:
        GameDataRef _data;
        
        sf::RectangleShape _shape;
        
        bool _flashOn;
        
    };
}
#endif /* Flash_hpp */
