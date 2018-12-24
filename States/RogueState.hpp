/*_Created_by_K1ngp1n_*/

#pragma once

#include "SoldierState.hpp"

class RogueState : public SoldierState {
	RogueState(std::string name, int strenght, int dexterity, int intelligence);
	public:
	RogueState();
	~RogueState() override;
};



