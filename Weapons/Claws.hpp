/*_Created_by_K1ngp1n_*/

#pragma once

#include "../Interfaces/AbstractWeapon.hpp"

class AbstractWeapon;

class Claws : public AbstractWeapon {
	public:
	Claws(AbstractUnit* holder);
	~Claws() override;

//	int calculateDamage(AbstractUnit *holder) override;
};



