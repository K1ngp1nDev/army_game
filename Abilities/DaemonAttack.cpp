/*_Created_by_K1ngp1n_*/

#include "DaemonAttack.hpp"
#include "../Interfaces/Observer.hpp"

DaemonAttack::DaemonAttack(AbstractUnit *_target, Warlock* own)
	: AbstractAttack()
	, w_owner(own)
{

}

DaemonAttack::~DaemonAttack() {
//	delete w_owner;
}

void DaemonAttack::makeAttack(AbstractUnit *attacker, AbstractUnit *attacked) {
//	int hits = attacked->getState()->getHp() - attacker->state()->getDamage();
//
//	if ( (attacked->state()->getHp() - attacker->getState()->getDamage()) < 0 ) {
//		hits = 0;
//	}
	if (BattleField::getInstance()->checkWeaponDistance(attacker, attacked) ) {

		if ((!dynamic_cast<Warlock *>(attacked)) && (!dynamic_cast<Daemon *>(attacked))) {
			std::cout << attacker->getState()->getName() << " attack "
			          << attacked->getState()->getName() << " with a " << attacker->getWeapon()->getTitle() << std::endl;
			attacked->takePhysicalDamage(attacker->getWeapon()->getDamage());

			if (attacked->getState()->getHp() > 0) {
//				attacked->counterAttack(attacker);
//				makeCounterAttack(attacker,attacked);
				makeCounterAttack(attacked,attacker);
				
				
			} else {
//				Observer::getInstance()->informObserver(attacked);
//				Observer::getInstance()->informObservable(attacked);//victim is dead
				BattleField::getInstance()->clearPointAndDelUnit(attacked);
			}
		} else {
			std::cout << "Can't attack master and self" << std::endl;
		}
	} else {
		std::cout << attacked->getState()->getName() << " is so far away." << std::endl;
	}
}

void DaemonAttack::makeCounterAttack(AbstractUnit *attacker, AbstractUnit *attacked) {
//	int hits = attacked->state()->getHp() - (attacker->getState()->getDamage() / 2);
//
//	if ( (attacked->state()->getHp() - attacker->getState()->getDamage() / 2) < 0 ) {
//		hits = 0;
//	}
	std::cout << attacker->getState()->getName() << " counter attack " << attacked->getState()->getName() << " with a " << attacker->getWeapon()->getTitle() << std::endl;

	attacked->takePhysicalDamage(attacker->getWeapon()->getDamage()/2);
	if (attacked->getState()->getHp() == 0 ) {
//		Observer::getInstance()->informObserver(attacked);
//		Observer::getInstance()->informObservable(attacked);//victim is dead
		BattleField::getInstance()->clearPointAndDelUnit(attacked);
	}
}
