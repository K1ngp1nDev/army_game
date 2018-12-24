/*_Created_by_K1ngp1n_*/

#pragma once

#include "../Interfaces/AbstractUnit.hpp"
#include "../Interfaces/AbstractAttack.hpp"

class AbstractUnit;

class NecromancerAttack : public AbstractAttack {
	public:
	NecromancerAttack(AbstractUnit* _target) ;
	~NecromancerAttack() override ;

	void makeAttack(AbstractUnit *attacker, AbstractUnit *attacked) override ;
	void makeCounterAttack(AbstractUnit *attacker, AbstractUnit *attacked) override;
};



