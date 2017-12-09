#ifndef SharkEntity_hpp
#define SharkEntity_hpp
#include "../Constants.hpp"
#include <SFML/Graphics.hpp>
#include <math.h>
#include "iostream"

namespace DevJAD {
    
    struct AnimationEntityData {
        sf::Sprite sprite;
        unsigned int totalFrames;
        sf::IntRect sizes;
        float switchTime;
        
        AnimationEntityData(sf::Sprite a, sf::IntRect b, unsigned int d, sf::Vector2f scale  = sf::Vector2f() ,float e = 0.1){
            sprite = a;
            sprite.setTextureRect(b);
            if(scale.x > 0 || scale.y > 0){
                sprite.setScale(scale);
            }
            totalFrames = d;
            switchTime = e;
            sizes = b;
        }
    };
    
    class SharkEntity {
        int entityState;
        unsigned frameInterator;
        sf::Clock clock;
        sf::Clock clockSin;
        float switchTime;
        sf::IntRect entityRect;
        sf::Sprite entitySprite;
        AnimationEntityData * attack;
        AnimationEntityData * swimming;
        AnimationEntityData * die;
        
    public:
        SharkEntity(sf::Texture &texture, sf::Vector2f scale = sf::Vector2f());
        AnimationEntityData * GetCurrentAnimationData();
        void SetPosition(float x, float y);
        void SetState(int state);
        void Update(float dt);
        void Animate(float dt);
        void Move(float x, float y);
        int GetState();
        const sf::Sprite &GetSprite() const;
    };

}
#endif /* SharkEntity_hpp */
