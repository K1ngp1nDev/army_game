/*_Created_by_K1ngp1n_*/

#pragma once

#include "../States/RogueState.hpp"
#include "../Interfaces/AbstractUnit.hpp"
#include "../Abilities/RogueAttack.hpp"
#include "../Weapons/Fists.hpp"
#include "../Weapons/Dagger.hpp"

class RogueState;
class RogueAttack;

class Rogue : public AbstractUnit {
	Rogue(AbstractState* state);
	public:
	Rogue();
	~Rogue() override;

	void clickSpecialAbility() override;
	void attack(AbstractUnit *enemy) override;
	void counterAttack(AbstractUnit *enemy) override;
//	std::set<EActionType> availableActions() override;

};

std::ostream& operator<<(std::ostream& out, const Rogue& rogue);


