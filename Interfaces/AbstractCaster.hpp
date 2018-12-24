/*_Created_by_K1ngp1n_*/

#pragma once

#include "../Exceptions/OutOfManaException.hpp"
#include "AbstractUnit.hpp"
#include "AbstractState.hpp"
#include "AbstractSpell.hpp"
#include "MageState.hpp"
#include "SpellBook.hpp"
#include <time.h>
#include <stdlib.h>
#include "BattleField.hpp"
#include "SpecialAbility.hpp"
#include "../States/MageState.hpp"

class AbstractSpell;
class BattleField;
class AbstractUnit;
class SpecialAbility;
class MageState;

class AbstractCaster : public AbstractUnit {
	protected:
	AbstractSpell* m_spell;
	spellbook _spellbook;
	AbstractCaster(AbstractState* state);
	public:
	AbstractCaster();
	virtual ~AbstractCaster() override;
	
	void clickSpecialAbility() override;
	
	SpecialAbility *getSpecialAbility() const override;
	
	void setSpecialAbility(SpecialAbility *newAbility) override;
	
	std::set<EActionType> availableActions() override;

	virtual void castSpell(AbstractUnit *target, Spell spell) = 0;

	virtual AbstractSpell *getSpell() const;

	virtual MageState *getMageState() const;

	const spellbook& getSpellBook() const{
		return _spellbook;
	}

};



