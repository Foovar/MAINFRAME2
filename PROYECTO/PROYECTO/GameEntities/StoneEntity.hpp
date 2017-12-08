#ifndef StoneEntity_hpp
#define StoneEntity_hpp
#include "SFML/Graphics.hpp"
#include "../game.hpp"

namespace DevJAD {

class StoneEntity {
	GameDataRef data;
	sf::Sprite StoneSprite;
	int totalFrames, frameInterator;
	float switchTime;
	sf::Clock clock;
public:
	StoneEntity(GameDataRef _data);
	void Update(float dt);
	void Animate(float dt);
	void Move(float x, float y);
	void Draw();
	void setPosition(float x, float y);
	const sf::Sprite &StoneEntity::GetSprite() const;
};
}
#endif // StoneEntity_hpp