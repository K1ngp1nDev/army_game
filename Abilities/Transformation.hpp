/*_Created_by_K1ngp1n_*/

#pragma once

#include "SpecialAbility.hpp"
#include <map>

class WereWolfState;
class SpecialAbility;
class AbstractUnit;
class AbstractAttack;
class AbstractWeapon;
class LycanthropeAttack;
class Claws;
class MageState;

class Transformation : public SpecialAbility {
	AbstractUnit* m_unit;
	     /**source/alter 			name 		move range				weapon				attack**/
	std::map<std::string, std::string> m_list_of_names;
	std::map<std::string, std::pair<AbstractWeapon*,AbstractAttack*>> m_list_of_weapons;
	
	public:
	Transformation(AbstractUnit *unit);
	virtual ~Transformation() override;

	void specialAbilityActivate() override;
	void add(AbstractUnit* unit);
};



