#ifndef StoneController_hpp
#define StoneController_hpp
#include "../game.hpp"
#include <cstdlib>
#include <ctime>
#include "../GameEntities/StoneEntity.hpp"
#include <vector>
namespace DevJAD {
	class StoneController {
		GameDataRef data;
		std::vector<StoneEntity> stones;
	public:
		StoneController(GameDataRef data);
		void SpawnStones();
		void DrawStone();
		void move(int i,float x, float y);
		const std::vector<StoneEntity> &getStones() const;

	};
}

#endif // !StoneController