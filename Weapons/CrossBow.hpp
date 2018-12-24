/*_Created_by_K1ngp1n_*/

#pragma once

#include "../Interfaces/AbstractWeapon.hpp"

class AbstractWeapon;

class CrossBow : public AbstractWeapon {
	public:
	CrossBow(AbstractUnit* holder);
	~CrossBow() override;

};



