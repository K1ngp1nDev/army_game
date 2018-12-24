/*_Created_by_K1ngp1n_*/

#include "RangeAttack.hpp"
#include "../Interfaces/AbstractWeapon.hpp"
#include "../Interfaces/AbstractState.hpp"
#include "../Interfaces/Observer.hpp"


RangeAttack::RangeAttack(AbstractUnit* target)
	: AbstractAttack() {
}

RangeAttack::~RangeAttack() {
}

void RangeAttack::makeAttack(AbstractUnit *attacker, AbstractUnit *attacked) {
	if ( BattleField::getInstance()->getTeam()->showPlayerTeam(attacker) != BattleField::getInstance()->getTeam()->showPlayerTeam(attacked)) {

		if (BattleField::getInstance()->checkWeaponDistance(attacker, attacked)) {
			std::cout << attacker->getState()->getName() << " range attack "
			          << attacked->getState()->getName() << " with a " << attacker->getWeapon()->getTitle()
			          << std::endl;
			attacked->takePhysicalDamage(attacker->getWeapon()->getDamage());

			if ( attacked->getState()->getHp() == 0) {
//
				BattleField::getInstance()->clearPointAndDelUnit(attacked);
			}
		} else {
			std::cout << attacked->getState()->getName() << " is so far away." << std::endl;
		}
	} else {
		std::cout << "Can't attack your team member." << std::endl;
	}
}

void RangeAttack::makeCounterAttack(AbstractUnit *attacker, AbstractUnit *attacked) {

}
