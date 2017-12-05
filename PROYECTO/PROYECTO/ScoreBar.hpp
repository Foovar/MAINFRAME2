

#ifndef ScoreBar_hpp
#define ScoreBar_hpp
#include "Game.hpp"

namespace DevJAD {
    class ScoreBar {
        GameDataRef data;
        sf::Text text;
        sf::Sprite lifeSprite;
        sf::Sprite scoreSprite;
        sf::Sprite timeSprite;
        int score, life, time;
        
    public:
        ScoreBar(GameDataRef _data);
        void Draw();
        void AddScore(int score);
        int GetScore();
        void AddLife(int life);
        void SubLife(int life);
        void UpdateTime(int time);
    };
}

#endif /* ScoreBar_hpp */
