/*_Created_by_K1ngp1n_*/

#include "BerserkState.hpp"

BerserkState::BerserkState(std::string name, int strenght, int dexterity, int intelligence)
	: SoldierState(name,strenght,dexterity,intelligence)
{}

BerserkState::BerserkState()
	: SoldierState("Berserker", 60, 30, 10)
{}

BerserkState::~BerserkState() {}
