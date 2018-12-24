/*_Created_by_K1ngp1n_*/

#include "Necromancer.hpp"
#include "../Spells/Blast.hpp"
#include "../Spells/FireBall.hpp"
#include "../Spells/Heal.hpp"
#include "../Weapons/Fists.hpp"
#include "../States/WereWolfState.hpp"
#include "../States/VampireState.hpp"
#include "../Weapons/BlackStaff.hpp"
#include "../Interfaces/Observer.hpp"
#include "../Interfaces/Undead.hpp"
#include "../Abilities/NecromancerAttack.hpp"


Necromancer::Necromancer(AbstractState* state)
	: AbstractCaster(state) {}

Necromancer::Necromancer()
	: AbstractCaster(new NecromancerState()) {
	this->m_special_ability = nullptr;
	this->m_attribute = new Undead();
	this->m_attack = new NecromancerAttack(this);
	this->m_weapon = new Fists(this);
	this->m_weapon = new BlackStaff(this);
	if ( !m_weapon->compare(this)) {
		this->m_weapon = new Fists(this);
	}
}

Necromancer::~Necromancer() {
	delete m_special_ability;
	delete m_attack;
	delete m_weapon;
	Observer::getInstance()->informObservable(this);
}

void Necromancer::castSpell(AbstractUnit *target, Spell spell) {
	auto it = getSpellBook().find(spell);

	AbstractSpell *_spell = it->second;
	m_spell = it->second;
	if (this->getMageState()->getMana() - _spell->getCost() > 0) {
		if ( !BattleField::getInstance()->checkMagicDistance(this, target)) {
			std::cout << "Can't cast, far away." << std::endl;
			return;
		}
		this->getMageState()->expendMana(_spell->getCost());
		
		if ( !dynamic_cast<Undead*>(target->getAttribute() )) {
			if ( (int)it->first != (int)Spell::Heal ) {
				if ( Observer::getInstance()->checkSoul(target) ) {

					std::cout << "I'm watching for you, "
					          << target->getState()->getName() << std::endl;
					Observer::getInstance()->add(this, target); //add victim
				}
			}
		}
		std::cout << this->getState()->getName() << " cast *"
		          << it->second->getSpellName()
		          << "*" << " in an enemy "
		          << target->getState()->getName() << std::endl;
		_spell->castSpell(target);
	} else {
		std::cout << "throw mana exception" << std::endl;
	}
}

void Necromancer::attack(AbstractUnit *enemy) {
	m_attack->makeAttack(this,enemy);
}

void Necromancer::counterAttack(AbstractUnit *enemy) {
	m_attack->makeCounterAttack(this,enemy);
}

void Necromancer::clickSpecialAbility() {
	m_special_ability->specialAbilityActivate();

}

std::ostream &operator<<(std::ostream &out, const Necromancer &necromancer) {
	out << necromancer.getState()->getName() << " HP:("
	    << necromancer.getState()->getHp() << "/"
	    << necromancer.getState()->getHpLimit() << "), "
	    << necromancer.getWeapon()->getTitle() <<" dmg:("
	    << necromancer.getWeapon()->getDamage() << "), MP:("
	    << necromancer.getMageState()->getMana() << "/"
	    << necromancer.getMageState()->getManaLimit() << ")." << std::endl;
	return out;
}
