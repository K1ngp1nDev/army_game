/*_Created_by_K1ngp1n_*/

#include "LycanthropeAttack.hpp"
#include "../Interfaces/AbstractCaster.hpp"
#include "../Interfaces/AbstractPhysician.hpp"
#include "../Interfaces/AbstractUnit.hpp"
#include "../Units/Vampire.hpp"
#include "../Units/Daemon.hpp"
#include "../Weapons/Claws.hpp"
#include "../Abilities/Transformation.hpp"
#include "../Interfaces/Observer.hpp"
#include "../Interfaces/BattleField.hpp"
#include "../Interfaces/Undead.hpp"
#include "../Interfaces/Beast.hpp"
#include "../Interfaces/Human.hpp"


LycanthropeAttack::LycanthropeAttack(AbstractUnit *target)
	: AbstractAttack()
{}

LycanthropeAttack::~LycanthropeAttack() {
}

void LycanthropeAttack::makeAttack(AbstractUnit *attacker, AbstractUnit *attacked) {
	if (BattleField::getInstance()->getTeam()->showPlayerTeam(attacker) !=
	    BattleField::getInstance()->getTeam()->showPlayerTeam(attacked)) {
		
		if (BattleField::getInstance()->checkWeaponDistance(attacker, attacked)) {
			std::cout << attacker->getState()->getName() << " bite "
			          << attacked->getState()->getName() << " with a " << attacker->getWeapon()->getTitle()
			          << std::endl;
			
			attacked->takePhysicalDamage(attacker->getWeapon()->getDamage());
			
			
			if ( (!dynamic_cast<Undead*>(attacked->getAttribute())) &&
				(!dynamic_cast<Beast*>(attacked->getAttribute())) &&
				(!dynamic_cast<Daemon*>(attacked)) ) {
				
				mutation(attacker, attacked);
				
			}
			if (attacked->getState()->getHp() > 0) {
				makeCounterAttack(attacked,attacker);
				
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

void LycanthropeAttack::makeCounterAttack(AbstractUnit *attacker, AbstractUnit *attacked) {
	if (BattleField::getInstance()->checkWeaponDistance(attacker, attacked)) {
		std::cout << attacker->getState()->getName() << " counter attack " << attacked->getState()->getName()
		          << " with a " << attacker->getWeapon()->getTitle() << std::endl;
		
		attacked->takePhysicalDamage(attacker->getWeapon()->getDamage() / 2);
		if ( (!dynamic_cast<Transformation*>(attacked->getSpecialAbility())) &&
		     (!dynamic_cast<Undead*>(attacked->getAttribute())) &&
			 (!dynamic_cast<Daemon*>(attacked)) ) {

				mutation(attacker, attacked);
		}
		if (attacked->getState()->getHp() == 0) {

			BattleField::getInstance()->clearPointAndDelUnit(attacked);
		}
	}
}

void LycanthropeAttack::mutation(AbstractUnit *attacker, AbstractUnit *victim) {
	std::cout << victim->getState()->getName() << " was infected by *wolf!*" << std::endl;
	
	victim->setSpecialAbility(new Transformation(victim));

}