/*_Created_by_K1ngp1n_*/

#include "RogueAttack.hpp"
#include "../Interfaces/AbstractWeapon.hpp"
#include "../Interfaces/AbstractState.hpp"
#include "../Interfaces/Observer.hpp"

RogueAttack::RogueAttack(AbstractUnit *_target)
	: AbstractAttack() {}

RogueAttack::~RogueAttack() {
}

void RogueAttack::makeAttack(AbstractUnit *attacker, AbstractUnit *attacked) {
	if (BattleField::getInstance()->getTeam()->showPlayerTeam(attacker) !=
	    BattleField::getInstance()->getTeam()->showPlayerTeam(attacked)) {
		
		if (BattleField::getInstance()->checkWeaponDistance(attacker, attacked)) {
			
			std::cout << attacker->getState()->getName() << " attack " << attacked->getState()->getName() << " with a "
			          << attacker->getWeapon()->getTitle() << std::endl;
			attacked->takePhysicalDamage(attacker->getWeapon()->getDamage());
			
		} else {
			std::cout << attacked->getState()->getName() << " is so far away." << std::endl;
		}
		if (attacked->getState()->getHp() == 0) {
//			Observer::getInstance()->informObserver(attacked);
//			Observer::getInstance()->informObservable(attacked);//victim is dead

			BattleField::getInstance()->clearPointAndDelUnit(attacked);
		}
	} else {
		std::cout << "Can't attack your team member." << std::endl;
	}
}

void RogueAttack::makeCounterAttack(AbstractUnit *attacker, AbstractUnit *attacked) {

		std::cout << attacker->getState()->getName() << " counter attack " << attacked->getState()->getName() << " with a " << attacker->getWeapon()->getTitle() << std::endl;

		attacked->takePhysicalDamage(attacker->getWeapon()->getDamage()/2);

	if (attacked->getState()->getHp() == 0 ) {
//		Observer::getInstance()->informObserver(attacked);

		BattleField::getInstance()->clearPointAndDelUnit(attacked);
	}
}
