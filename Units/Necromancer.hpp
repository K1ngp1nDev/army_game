/*_Created_by_K1ngp1n_*/

#pragma once

#include "../Interfaces/AbstractCaster.hpp"
#include "../Abilities/ClassicAttack.hpp"
#include "../States/NecromancerState.hpp"

class NecromancerState;
class ClassicAttack;

class Necromancer : public AbstractCaster {
	Necromancer(AbstractState* state);
	public:
	Necromancer();
	~Necromancer() override;
	
	void clickSpecialAbility() override;
	void castSpell(AbstractUnit *target, Spell spell) override;
	void attack(AbstractUnit *enemy) override;
	void counterAttack(AbstractUnit *enemy) override;
	
};

std::ostream& operator<<(std::ostream& out, const Necromancer& necromancer);



