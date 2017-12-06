
#ifndef InputManager_hpp
#define InputManager_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

namespace DevJAD {
    
    class InputManager{
    public:
        InputManager(){}
        ~InputManager(){}
        
        bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
        bool IsSpriteHover(sf::Sprite object, sf::RenderWindow &window);
        sf::Vector2i GetMousePosition(sf::RenderWindow &window);
        
        bool IsJumping(sf::Keyboard::Key);
    };
    
}


#endif /* InputManager_hpp */
