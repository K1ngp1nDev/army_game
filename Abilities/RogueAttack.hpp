/*_Created_by_K1ngp1n_*/

#pragma once

//#include "../Interfaces/AbstractUnit.hpp"
#include "../Interfaces/AbstractAttack.hpp"
//class AbstractUnit;

class RogueAttack : public AbstractAttack{
	public:
	RogueAttack(AbstractUnit* _target) ;
	~RogueAttack() override ;

	void makeAttack(AbstractUnit *attacker, AbstractUnit *attacked) override ;
	void makeCounterAttack(AbstractUnit *attacker, AbstractUnit *attacked) override;

};


