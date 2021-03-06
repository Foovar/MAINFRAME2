
#ifndef SharkController_hpp
#define SharkController_hpp
#include <SFML/Graphics.hpp>
#include <vector>
#include "../GameEntities/SharkEntity.hpp"
#include "../Game.hpp"
#include <cstdlib>
#include <ctime>
#include "iostream"
#include "../Collision.hpp"

namespace DevJAD {
    class SharkController{
        std::vector<SharkEntity> sharks;
        GameDataRef data;
        Collision collision;
        sf::Vector2f scale;
    public:
        SharkController(GameDataRef data);
        void MoveSharks(float dt);
        void MoveShark(int i, float x, float y);
        void UpdateSharks(float dt);
        void DrawSharks();
        void SpawnSharks();
        bool IsCollide(int i, sf::Sprite sprite);
        void SetSharkState(int shark, int state);
        int GetSharkState(int shark);
        void SetScale(float x, float y);
        const std::vector<SharkEntity> &GetEntities() const;
    };
}

#endif /* SharkController_hpp */
