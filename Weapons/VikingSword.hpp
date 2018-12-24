/*_Created_by_K1ngp1n_*/

#pragma once

#include "../Interfaces/AbstractWeapon.hpp"

class AbstractWeapon;

class VikingSword : public AbstractWeapon {
	public:
	VikingSword(AbstractUnit* holder);
	~VikingSword() override;

	std::string getTitle() const override;
	int getRange() const override;
	int getDamage() const override;

	int getWeight() const override;
	int getAgility() const override;
	int getMind() const override;
//	int calculateDamage(AbstractUnit *holder) override;

};



