
#ifndef Collision_hpp
#define Collision_hpp
#include <SFML/Graphics.hpp>

namespace DevJAD {
    class Collision{
    public:
        Collision();
        ~Collision();
        bool CheckSpriteCollision(sf::Sprite sprite1, sf::Sprite sprite2, float ax = 0, float ay = 0, float bx = 0, float by = 0);
        bool CheckSpriteCollision(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2);
        bool CheckRectCollision(sf::FloatRect rect1, sf::FloatRect rect2);
    };
}

#endif /* Collision_hpp */
