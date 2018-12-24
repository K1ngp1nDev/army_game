/*_Created_by_K1ngp1n_*/

#pragma once

#include "SpecialAbility.hpp"

class AbstractUnit;
class AbstractState;

class Mount : public SpecialAbility {
	int step;
	AbstractUnit* m_rider;
	public:
	Mount(AbstractUnit *rider);

	~Mount() override;

	int getStep() const;

	void specialAbilityActivate() override;
};



