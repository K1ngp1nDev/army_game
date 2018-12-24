/*_Created_by_K1ngp1n_*/

#pragma once

#include "../Interfaces/AbstractAttack.hpp"

class RangeAttack : public AbstractAttack {
	public:
	RangeAttack(AbstractUnit* target);

	RangeAttack();

	~RangeAttack() override;

	void makeAttack(AbstractUnit *attacker, AbstractUnit *attacked) override;

	void makeCounterAttack(AbstractUnit *attacker, AbstractUnit *attacked) override;


};
