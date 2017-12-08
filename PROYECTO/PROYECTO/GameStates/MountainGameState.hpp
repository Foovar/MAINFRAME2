#ifndef MountainGameState_hpp
#define MountainGameState_hpp

#include "../game.hpp"
#include "../State.hpp"
#include "../Characters/MarioCharacter.hpp"
#include "../Collision.hpp"
#include "../GameEntities/StoneEntity.hpp"

namespace DevJAD {

class MountainGameState : public State {
	GameDataRef data;
	sf::Sprite spritebackground;
	sf::Sprite spriteColine;
	MarioCharacter *marioCharacter;
	StoneEntity *stoneEntity;
	sf::View viewScreen;
	sf::Music musicBackground;
	int  gameState;
	sf::CircleShape shape;
	Collision collision;
public:
	MountainGameState(GameDataRef data);
	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);
	};
}
#endif // !MountainGameState