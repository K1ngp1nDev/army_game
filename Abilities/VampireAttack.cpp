/*_Created_by_K1ngp1n_*/

#include "../Interfaces/BattleField.hpp"
#include "../Interfaces/Observer.hpp"
#include "VampireAttack.hpp"
#include "../Units/Vampire.hpp"
#include "../Units/Daemon.hpp"
#include "../Interfaces/Undead.hpp"
#include "../Interfaces/Beast.hpp"
#include "../Interfaces/AbstractWeapon.hpp"
#include "../States/VampireState.hpp"
#include "../Weapons/Teeth.hpp"

VampireAttack::VampireAttack(AbstractUnit *target)
: AbstractAttack()

{
	srand (time(NULL));
}

VampireAttack::~VampireAttack() {}

void VampireAttack::makeAttack(AbstractUnit *attacker, AbstractUnit *attacked) {
	if (BattleField::getInstance()->getTeam()->showPlayerTeam(attacker) !=
	    BattleField::getInstance()->getTeam()->showPlayerTeam(attacked)) {
		
		if (BattleField::getInstance()->checkWeaponDistance(attacker, attacked)) {
			int stealLife = attacker->getWeapon()->getDamage() * ((rand() % 6 + 1) * 0.1);
			
			std::cout << attacker->getState()->getName() << " attack "
			          << attacked->getState()->getName() << " with a " << attacker->getWeapon()->getTitle()
			          << std::endl;
			attacked->takePhysicalDamage(attacker->getWeapon()->getDamage());
			
			if ( (!dynamic_cast<Undead*>(attacked->getAttribute())) &&
				 (!dynamic_cast<Beast*>(attacked->getAttribute())) &&
				 (!dynamic_cast<Daemon*>(attacked)) ) {
				if (attacker->getState()->getHp() + stealLife > attacker->getState()->getHpLimit()) {
					attacker->getState()->setHp(attacker->getState()->getHpLimit());
					std::cout << attacker->getState()->getName() << " dring some blood." << std::endl << std::endl;
				} else {
					attacker->getState()->setHp(attacker->getState()->getHp() + stealLife);
				}
				std::cout << attacker->getState()->getName() << " dring some blood." << std::endl << std::endl;
				
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

void VampireAttack::makeCounterAttack(AbstractUnit *attacker, AbstractUnit *attacked) {
	
	if (BattleField::getInstance()->checkWeaponDistance(attacker, attacked)) {
		
		int stealLife = (attacker->getWeapon()->getDamage() / 2) * ((rand() % 6 + 1) * 0.1);
		std::cout << attacker->getState()->getName() << " counter attack " << attacked->getState()->getName()
		          << " with a " << attacker->getWeapon()->getTitle() << std::endl;
		attacked->takePhysicalDamage(attacker->getWeapon()->getDamage() / 2);
		
		if ((!dynamic_cast<Undead *>(attacked->getAttribute())) &&
		    (!dynamic_cast<Beast *>(attacked->getAttribute())) &&
		    (!dynamic_cast<Daemon*>(attacked)) ) {
			
			if (attacker->getState()->getHp() + stealLife > attacker->getState()->getHpLimit()) {
				attacker->getState()->setHp(attacker->getState()->getHpLimit());
				std::cout << attacker->getState()->getName() <<
				          " dring some blood, and hp how: (" <<
				          attacker->getState()->getHp() << ")." << std::endl << std::endl;
			} else {
				attacker->getState()->setHp(attacker->getState()->getHp() + stealLife);
				std::cout << attacker->getState()->getName() <<
				          " dring some blood, and hp how: (" <<
				          attacker->getState()->getHp() << ")." << std::endl << std::endl;
			}
			mutation(attacker, attacked);
			
		}
		
		if (attacked->getState()->getHp() == 0) {
			BattleField::getInstance()->clearPointAndDelUnit(attacked);
		}
	}
}

void VampireAttack::mutation(AbstractUnit *attacker, AbstractUnit *victim) {
	std::cout << victim->getState()->getName() << " was infected!" << std::endl;
	victim->setAttribute(new Undead);
	victim->setWeapon(new Teeth(victim));
	victim->setAttack(new VampireAttack(victim));
	victim->getState()->setName("Vampire-" + victim->getState()->getName() );
	BattleField::getInstance()->markerOnBoard(victim);
}
