/*_Created_by_K1ngp1n_*/

#pragma once

#include "../Interfaces/AbstractWeapon.hpp"

class AbstractWeapon;

class Teeth : public AbstractWeapon {
	public:
	Teeth(AbstractUnit *holder);
	~Teeth() override;

	std::string getTitle() const override;
	int getRange() const override;
	int getDamage() const override;
};

