/*_Created_by_K1ngp1n_*/

#pragma once

#include "AbstractUnit.hpp"

class AbstractUnit;

class SpecialAbility {
	AbstractUnit* m_unit;
	public:
	SpecialAbility(AbstractUnit* unit);
	virtual~SpecialAbility() = 0;

	virtual void specialAbilityActivate();
	virtual void specialAbilityToTarget(AbstractUnit* target);
    virtual std::set<EActionType> availableActions() const;
};



