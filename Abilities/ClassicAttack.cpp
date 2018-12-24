/*_Created_by_K1ngp1n_*/

#include "ClassicAttack.hpp"
#include "../Interfaces/AbstractWeapon.hpp"
#include "../Interfaces/AbstractState.hpp"
#include "../Interfaces/Observer.hpp"

ClassicAttack::ClassicAttack(AbstractUnit *target)
	: AbstractAttack() {}

ClassicAttack::~ClassicAttack() {
}

void ClassicAttack::makeAttack(AbstractUnit *attacker, AbstractUnit *attacked) {
	if ( BattleField::getInstance()->getTeam()->showPlayerTeam(attacker) !=
		 BattleField::getInstance()->getTeam()->showPlayerTeam(attacked)) {

		if (BattleField::getInstance()->checkWeaponDistance(attacker, attacked)) {
			std::cout << attacker->getState()->getName() << " attack "
			          << attacked->getState()->getName() << " with a " << attacker->getWeapon()->getTitle()
			          << std::endl;
			attacked->takePhysicalDamage(attacker->getWeapon()->getDamage());

			if (attacked->getState()->getHp() > 0) {
				attacked->counterAttack(attacker);
			} else {
				BattleField::getInstance()->clearPointAndDelUnit(attacked);
			}
		} else {
			std::cout << attacked->getState()->getName() << " is so far away." << std::endl;
		}
	} else {
		std::cout << "Can't attack your team member." << std::endl;
	}
}

void ClassicAttack::makeCounterAttack(AbstractUnit *attacker, AbstractUnit *attacked) {
	if (BattleField::getInstance()->checkWeaponDistance(attacker, attacked)) {
		std::cout << attacker->getState()->getName() << " counter attack " << attacked->getState()->getName()
		          << " with a " << attacker->getWeapon()->getTitle() << std::endl;
		attacked->takePhysicalDamage(attacker->getWeapon()->getDamage() / 2);
		if (attacked->getState()->getHp() == 0) {

			BattleField::getInstance()->clearPointAndDelUnit(attacked);
		}
	}
}
