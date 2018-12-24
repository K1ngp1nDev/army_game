/*_Created_by_K1ngp1n_*/

#pragma once

#include "../Interfaces/AbstractUnit.hpp"


class VampireState;
class VampireAttack;
class Undead;
class SpecialAbility;

class Vampire : public AbstractUnit {
	protected:
	Vampire(AbstractState* state);
	public:
	Vampire();
	~Vampire();

	void attack(AbstractUnit *enemy) override;
	void counterAttack(AbstractUnit *enemy) override;
	void clickSpecialAbility() override;
	
};

std::ostream& operator<<(std::ostream& out, const Vampire& vampire);

