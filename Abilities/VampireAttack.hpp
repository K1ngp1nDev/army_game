/*_Created_by_K1ngp1n_*/

#pragma once

#include "../Interfaces/AbstractAttack.hpp"
#include <time.h>
#include <stdlib.h>

class VampireState;

class VampireAttack : public AbstractAttack {
	public:
	VampireAttack(AbstractUnit* target) ;
	~VampireAttack() override ;

	void makeAttack(AbstractUnit *attacker, AbstractUnit *attacked) override ;
	void makeCounterAttack(AbstractUnit *attacker, AbstractUnit *attacked) override;

	void mutation(AbstractUnit *attacker, AbstractUnit *victim);

};


