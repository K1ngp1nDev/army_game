/*_Created_by_K1ngp1n_*/

#pragma once

#include "AbstractUnit.hpp"
#include "BattleField.hpp"

class BattleField;
class AbstractUnit;

class AbstractAttack {
//	protected:
//	AbstractUnit* u_target;
	public:
	AbstractAttack() {}
	virtual ~AbstractAttack() {}

	virtual void makeAttack(AbstractUnit *attacker, AbstractUnit *attacked) = 0 ;
	virtual void makeCounterAttack(AbstractUnit *attacker, AbstractUnit *attacked) = 0;

};
