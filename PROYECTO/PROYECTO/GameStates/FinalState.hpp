#ifndef FinalState_hpp
#define FinalState_hpp
#include "../Game.hpp"
#include "../State.hpp"
#include "../Characters/MarioCharacter.hpp"
#include "../Characters/PrincessCharacter.hpp"

namespace DevJAD {

	class FinalState : public State {
		GameDataRef data;
		MarioCharacter* marioSprite;
		princessCharacter* princesaSprite;
		sf::Sprite spriteBackground;
		sf::Sound soundBackGround;
		sf::Clock clock_princess;
			
	public:
		FinalState(GameDataRef data);
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
	};
}
#endif // !FinalState_hpp