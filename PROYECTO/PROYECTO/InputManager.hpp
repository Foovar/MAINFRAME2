//
//  InputManager.hpp
//  PROYECTO
//
//  Created by DevJAD on 2/11/17.
//  Copyright © 2017 DevJAD. All rights reserved.
//

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
    };
    
}


#endif /* InputManager_hpp */
