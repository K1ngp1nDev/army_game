/*_Created_by_K1ngp1n_*/

#include "VampireState.hpp"

VampireState::VampireState(std::string name, int strenght, int dexterity, int intelligence)
	: SoldierState(name,strenght,dexterity,intelligence)
{}

VampireState::VampireState()
	: SoldierState("Vampire", 50, 50, 30)
{}

VampireState::~VampireState() {}