/*_Created_by_K1ngp1n_*/

#pragma once

#include "../Interfaces/AbstractAttack.hpp"
#include "../States/WereWolfState.hpp"

class WereWolfState;

class LycanthropeAttack : public AbstractAttack {
	public:
	LycanthropeAttack(AbstractUnit* target);
	~LycanthropeAttack() override ;

	void makeAttack(AbstractUnit *attacker, AbstractUnit *attacked) override ;
	void makeCounterAttack(AbstractUnit *attacker, AbstractUnit *attacked) override;
	void mutation(AbstractUnit *attacker, AbstractUnit *victim);
};



