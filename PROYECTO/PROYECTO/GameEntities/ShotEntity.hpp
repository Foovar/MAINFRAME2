
#ifndef Shot_hpp
#define Shot_hpp
#include <SFML/Graphics.hpp>
#include "../Game.hpp"

namespace DevJAD {
    class ShotEntity {
        GameDataRef data;
        sf::Sprite shotSprite;
        int totalFrames, frameInterator;
        float switchTime;
        sf::Clock clock;
        bool hasShot;
    public:
        ShotEntity(GameDataRef data);
        void Update(float dt);
        void Animate(float dt);
        void Move(float x, float y, float dt);
        void Draw();
        void Shoot(sf::Vector2f pos);
        bool hasShoot();
        const sf::Sprite &GetSprite() const;
    };
}

#endif /* Shot_hpp */
