/*_Created_by_K1ngp1n_*/

#pragma once

#include "../Interfaces/AbstractPhysician.hpp"
#include "../Abilities/ClassicAttack.hpp"

class Priest : public AbstractPhysician{
	Priest(AbstractState* state);
	public:
	Priest();
	~Priest() override;
	
	void attack(AbstractUnit *enemy) override;
	void counterAttack(AbstractUnit *enemy) override;
	void castSpell(AbstractUnit *target, Spell spell) override;
	void clickSpecialAbility() override;
	
};

std::ostream& operator<<(std::ostream& out, const Priest& priest);






