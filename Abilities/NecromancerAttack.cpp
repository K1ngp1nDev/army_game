/*_Created_by_K1ngp1n_*/

#include "NecromancerAttack.hpp"
#include "../Interfaces/Observer.hpp"
#include "../Interfaces/AbstractWeapon.hpp"
#include "../Interfaces/AbstractState.hpp"
#include "../Interfaces/Undead.hpp"

NecromancerAttack::NecromancerAttack(AbstractUnit *target) :
	AbstractAttack() {}

NecromancerAttack::~NecromancerAttack() {
}

void NecromancerAttack::makeAttack(AbstractUnit *attacker, AbstractUnit *attacked) {
	if ( BattleField::getInstance()->getTeam()->showPlayerTeam(attacker) != BattleField::getInstance()->getTeam()->showPlayerTeam(attacked)) {
		
		if (BattleField::getInstance()->checkWeaponDistance(attacker, attacked)) {
			std::cout << attacker->getState()->getName() << " attack "
			          << attacked->getState()->getName() << " with a " << attacker->getWeapon()->getTitle()
			          << std::endl;
			if ( !dynamic_cast<Undead*>(attacked) ) {
				std::cout << attacker->getState()->getName() << " add soul "
				          << attacked->getState()->getName() << std::endl;
				Observer::getInstance()->add(attacker,attacked); // add in cont
			}
			attacked->takePhysicalDamage(attacker->getWeapon()->getDamage());
			
			if ( attacked->getState()->getHp() == 0 ) {
//				Observer::getInstance()->informObserver(attacked);
//				Observer::getInstance()->informObservable(attacked);//victim is dead

				BattleField::getInstance()->clearPointAndDelUnit(attacked);
				
			} else {
//				attacked->counterAttack(attacker);
				makeCounterAttack(attacked,attacker);
			}
			
		} else {
			std::cout << attacked->getState()->getName() << " is so far away." << std::endl;
		}
	} else {
		std::cout << "Can't attack your team member." << std::endl;
	}
}

void NecromancerAttack::makeCounterAttack(AbstractUnit *attacker, AbstractUnit *attacked) {
	if (BattleField::getInstance()->checkWeaponDistance(attacker, attacked)) {
		
		std::cout << attacker->getState()->getName() << " counter attack " << attacked->getState()->getName()
		          << " with a " << attacker->getWeapon()->getTitle() << std::endl;
		
		attacked->takePhysicalDamage(attacker->getWeapon()->getDamage() / 2);
		if (!dynamic_cast<Undead *>(attacked->getAttribute())) {
			std::cout << attacker->getState()->getName() << " add soul "
			          << attacked->getState()->getName() << std::endl;
			Observer::getInstance()->add(attacker, attacked); // add in cont
		}
		
		if (attacked->getState()->getHp() == 0) {
//			Observer::getInstance()->informObserver(attacked);
			BattleField::getInstance()->clearPointAndDelUnit(attacked);
		}
	}
}
