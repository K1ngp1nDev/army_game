/*_Created_by_K1ngp1n_*/

#pragma once

#include "AbstractCaster.hpp"

class AbstractPhysician: public AbstractCaster {
	protected:
	spellbook healer_spellbook;
	AbstractPhysician(AbstractState* state);
	public:
	AbstractPhysician();
	virtual ~AbstractPhysician() override;
	
	void clickSpecialAbility() override;
	
	SpecialAbility *getSpecialAbility() const override;
	
	void setSpecialAbility(SpecialAbility *newAbility) override;
	
	virtual void castSpell(AbstractUnit *target, Spell spell) = 0;
	
	virtual AbstractSpell *getSpell() const;
	
	virtual MageState *getMageState() const;
	
	const spellbook& _getHealerSpellBook() const{
		return healer_spellbook;
	}

};

