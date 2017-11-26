//
//  FakeMario.hpp
//  PROYECTO
//
//  Created by Alex Paredes on 25/11/17.
//  Copyright © 2017 Alex Paredes. All rights reserved.
//

#ifndef FakeMario_hpp
#define FakeMario_hpp

#include <vector>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Constants.hpp"
namespace DevJAD {
    class FakeMario {
        GameDataRef data;
        std::vector<sf::Sprite> animationFrames;
        std::vector<sf::Sprite> shots;
        
        sf::Sprite fakeMarioSprite;
        sf::Texture fakeMarioTexture;
        sf::Clock clock;
        sf::Sprite shot;
        int state, movementX, movementY;
        unsigned int framesInterator, framesShotInterator;
        float timeAttack;
        
    public:
        FakeMario(GameDataRef _data);
        FakeMario();
        void Draw();
        void Animate(float dt);
        void Update(float dt);
        const sf::Sprite &GetSprite() const;
        void SetState(int _state);
        int GetState();
    };
}
#endif /* FakeMario_hpp */
