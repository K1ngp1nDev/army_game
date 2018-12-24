/*_Created_by_K1ngp1n_*/

#include "Priest.hpp"
#include "../Spells/Heal.hpp"
#include "../Spells/Blast.hpp"
#include "../Spells/FireBall.hpp"
#include "../States/PriestState.hpp"
#include "../Weapons/Fists.hpp"
#include "../Weapons/BlackStaff.hpp"
#include "../Interfaces/Undead.hpp"
#include "../Interfaces/Observer.hpp"

Priest::Priest(AbstractState* state)
	: AbstractPhysician(state) {}

Priest::Priest()
	: AbstractPhysician(new PriestState())
{
	this->m_special_ability = nullptr;
	this->m_attack = new ClassicAttack(this);
	this->m_weapon = new Fists(this);
	this->m_weapon = new BlackStaff(this);
	if ( !m_weapon->compare(this)) {
		this->m_weapon = new Fists(this);
	}
}

Priest::~Priest() {
	delete m_special_ability;
	delete m_attack;
	delete m_weapon;
	Observer::getInstance()->informObserver(this);
}

void Priest::castSpell(AbstractUnit *target, Spell spell) {
	auto it = _getHealerSpellBook().find(spell);
	
	AbstractSpell* _spell = it->second;
	m_spell = it->second;
	
	if ( (this->getMageState()->getMana() - _spell->getCost() > 0 )) {
		if (!BattleField::getInstance()->checkMagicDistance(this, target)) {
			std::cout << "Can't cast, far away." << std::endl;
			return;
		}
		this->getMageState()->expendMana(_spell->getCost());

		if ( dynamic_cast<Undead*>(target->getAttribute()) ) {
			if ( dynamic_cast<Heal*>(it->second) ) {
				std::cout << "You can't healing undead!!" << std::endl;
			} else {
				std::cout << this->getState()->getName() << " cast *SAINT-"
				          << it->second->getSpellName()
				          << "*" << " in an enemy "
				          << target->getState()->getName() << std::endl;
				target->takeMagicDamage(it->second->getPoints() * 2);
			}
		} else {
			std::cout << this->getState()->getName() << " cast *"
			          << it->second->getSpellName()
			          << "*" << " in an enemy "
			          << target->getState()->getName() << std::endl;
			_spell->castSpell(target);
		}
	} else {
		std::cout << "throw mana exception" << std::endl;
	}
}

void Priest::attack(AbstractUnit *enemy) {
	m_attack->makeAttack(this,enemy);
}

void Priest::counterAttack(AbstractUnit *enemy) {
	m_attack->makeCounterAttack(this,enemy);
	
}

void Priest::clickSpecialAbility() {
	m_special_ability->specialAbilityActivate();

}

std::ostream &operator<<(std::ostream &out, const Priest &priest) {
	out << priest.getState()->getName() << " HP:("
	    << priest.getState()->getHp() << "/"
	    << priest.getState()->getHpLimit() << "), "
	    << priest.getWeapon()->getTitle() <<" dmg:("
	    << priest.getWeapon()->getDamage() << "), MP:("
	    << priest.getMageState()->getMana() << "/"
	    << priest.getMageState()->getManaLimit() << ")." << std::endl;
	
	return out;
}
