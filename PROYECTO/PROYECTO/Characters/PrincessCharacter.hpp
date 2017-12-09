#ifndef princessCharacter_hpp
#define princessCharacter_hpp
#include "../Game.hpp"
#include "../Constants.hpp"
namespace DevJAD {
class princessCharacter {
	GameDataRef data;
	sf::Sprite spriteCharacter;
	sf::Clock clock;
	int frameInterator, totalFrames;
	float framePosY, framePosX;
	float switchTime;
	int moveAmount;
	int characterStatus, moveType;
	int movementX;
	sf::Sound soundAttack;
	public:
	princessCharacter(GameDataRef data);
	void Draw();
	void Animate(float dt);
	void Update(float dt);
	const sf::Sprite &GetSprite() const;
	void SetPosition(float x, float y);
	sf::Vector2f GetPosition();
	void Move(int type);
	void SetDefaultState(int state);
	void SetState(int state);
};
}
#endif // !princessCharacter_hpp
