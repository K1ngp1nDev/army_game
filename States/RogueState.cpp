/*_Created_by_K1ngp1n_*/

#include "RogueState.hpp"

RogueState::RogueState(std::string name, int strenght, int dexterity, int intelligence)
	: SoldierState(name,strenght,dexterity,intelligence)
{}

RogueState::RogueState()
	: SoldierState("Rogue", 40, 50, 20)
{}

RogueState::~RogueState() {}
