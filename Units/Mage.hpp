/*_Created_by_K1ngp1n_*/

#pragma once

#include "../States/MageState.hpp"
#include "../Interfaces/AbstractCaster.hpp"
#include "../Abilities/ClassicAttack.hpp"

class MageState;
class ClassicAttack;

class Mage : public AbstractCaster {
	Mage(AbstractState* state);
	public:
	Mage();
	~Mage() override;
	void clickSpecialAbility() override;
	void castSpell(AbstractUnit *target, Spell spell) override;
	void attack(AbstractUnit *enemy) override;
	void counterAttack(AbstractUnit *enemy) override;
};
std::ostream& operator<<(std::ostream& out, const Mage& mage);



