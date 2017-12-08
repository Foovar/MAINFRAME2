#include "StoneController.hpp"

namespace DevJAD {
	StoneController::StoneController(GameDataRef data) {
		srand(int(time(NULL)));
	}
	void StoneController::SpawnStones() {

	}
	void StoneController::DrawStone() {

	}
	void StoneController::move(int i,float x, float y) {
		this->stones.at(i).Move( x, y);
	}
	const std::vector<StoneEntity> &StoneController::getStones()const {
		return this->stones;
	}

}