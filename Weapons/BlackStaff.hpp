/*_Created_by_K1ngp1n_*/

#pragma once

#include "../Interfaces/AbstractWeapon.hpp"

class AbstractWeapon;

class BlackStaff : public AbstractWeapon {
	public:
	BlackStaff(AbstractUnit* holder);
	~BlackStaff() override;

};



