/*_Created_by_K1ngp1n_*/

#pragma once

#include "../Interfaces/AbstractAttack.hpp"

class ClassicAttack : public AbstractAttack {
	public:
	ClassicAttack(AbstractUnit* target) ;
	 ~ClassicAttack() override ;

	 void makeAttack(AbstractUnit *attacker, AbstractUnit *attacked) override ;
	 void makeCounterAttack(AbstractUnit *attacker, AbstractUnit *attacked) override;

};
