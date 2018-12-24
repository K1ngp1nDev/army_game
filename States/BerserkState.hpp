/*_Created_by_K1ngp1n_*/

#pragma once

#include "SoldierState.hpp"

class BerserkState : public SoldierState {
	BerserkState(std::string name, int strenght, int dexterity, int intelligence);
	public:
	BerserkState();
	~BerserkState() override;

};



