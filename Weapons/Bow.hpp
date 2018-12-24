/*_Created_by_K1ngp1n_*/

#pragma once

#include "../Interfaces/AbstractWeapon.hpp"

class AbstractWeapon;

class Bow : public AbstractWeapon {
	public:
	Bow(AbstractUnit* holder);
	~Bow() override;

};



