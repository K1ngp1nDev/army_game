/*_Created_by_K1ngp1n_*/

#pragma once

#include "../Interfaces/AbstractWeapon.hpp"

class AbstractWeapon;

class Dagger : public AbstractWeapon {
	public:
	Dagger(AbstractUnit* holder);
	~Dagger() override;

//	int calculateDamage(AbstractUnit *holder) override;
};


