/*_Created_by_K1ngp1n_*/

#pragma once

//#include "../Interfaces/AbstractState.hpp"
#include "SoldierState.hpp"

class VampireState : public SoldierState {
	VampireState(std::string name, int strenght, int dexterity, int intelligence);
	public:
	VampireState();
	~VampireState() override;
	
};
