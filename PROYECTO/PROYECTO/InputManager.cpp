
#include "InputManager.hpp"

namespace DevJAD {
    
    bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window){
        if(!sf::Mouse::isButtonPressed(button)) return false;
        
        sf::IntRect tempRect(object.getPosition().x - object.getOrigin().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);
        return tempRect.contains(sf::Mouse::getPosition(window));
    }
    
    bool InputManager::IsSpriteHover(sf::Sprite object, sf::RenderWindow &window){
        sf::IntRect tempRect(object.getPosition().x - object.getOrigin().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);
        return tempRect.contains(sf::Mouse::getPosition(window));
    }
    
    sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow &window){
        return sf::Mouse::getPosition(window);
    }
    
    bool InputManager::IsJumping(sf::Keyboard::Key key){
        return key == sf::Keyboard::Space;
    }
    
}
