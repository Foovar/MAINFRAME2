
#ifndef Physics_hpp
#define Physics_hpp
#include <SFML/Graphics.hpp>
#include <math.h>

namespace DevJAD {
    class Physics {
        sf::Vector2f v;
        float x0, y0, angle, power, ax, ay;
    public:
        Physics(float x0, float y0, float angle, float power, float ax, float ay);
        Physics(float x0, float y0, float angle, float power);
        sf::Vector2f GetPosAtTime(float time);
        float AngleToRad(float angle);
    };
}

#endif /* Physics_hpp */
