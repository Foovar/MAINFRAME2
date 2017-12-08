#ifndef FinalState_hpp
#define FinalState_hpp
#include "../Game.hpp"
#include "../State.hpp"
#include "../Characters/MarioCharacter.hpp"

namespace DevJAD {

	class FinalState : public State {
		GameDataRef data;
		MarioCharacter* marioSprite;
		sf::Sprite spriteBackground;
		sf::Sound sounDBackground;
	public:
		FinalState(GameDataRef data);
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
	};
}
#endif // !FinalState_hpp