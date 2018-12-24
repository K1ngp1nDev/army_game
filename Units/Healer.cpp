/*_Created_by_K1ngp1n_*/

#include "Healer.hpp"
#include "../Spells/Heal.hpp"
#include "../Spells/Blast.hpp"
#include "../Spells/FireBall.hpp"
#include "../States/HealerState.hpp"
#include "../Weapons/Fists.hpp"
#include "../Weapons/BlackStaff.hpp"
#include "../Interfaces/Observer.hpp"


Healer::Healer(AbstractState* state)
	: AbstractPhysician(state) {}

Healer::Healer()
	: AbstractPhysician(new HealerState())
{
	this->m_special_ability = nullptr;
	this->m_attack = new ClassicAttack(this);
	this->m_weapon = new Fists(this);
	this->m_weapon = new BlackStaff(this);
	if ( !m_weapon->compare(this)) {
		this->m_weapon = new Fists(this);
	}
}

Healer::~Healer() {
	delete m_special_ability;
	delete m_weapon;
	delete m_attack;
	Observer::getInstance()->informObserver(this);
}

void Healer::castSpell(AbstractUnit *target, Spell spell) {
	auto it = _getHealerSpellBook().find(spell);
	
	AbstractSpell* _spell = it->second;
	m_spell = it->second;
	
	if ( (this->getMageState()->getMana() - _spell->getCost() > 0 )) {
		if ( !BattleField::getInstance()->checkMagicDistance(this, target)) {
			std::cout << "Can't cast, far away." << std::endl;
			return;
		}
		this->getMageState()->expendMana(_spell->getCost());
		
		std::cout << this->getState()->getName() << " cast *"
		          << it->second->getSpellName()
		          << "*" << " in an enemy "
		          << target->getState()->getName() << std::endl;
		_spell->castSpell(target);
	} else {
		std::cout << "throw mana exception" << std::endl;
	}
}

void Healer::attack(AbstractUnit *enemy) {
	m_attack->makeAttack(this,enemy);
}

void Healer::counterAttack(AbstractUnit *enemy) {
	m_attack->makeCounterAttack(this,enemy);
	
}

void Healer::clickSpecialAbility() {
	m_special_ability->specialAbilityActivate();
}

std::ostream &operator<<(std::ostream &out, const Healer &healer) {
	out << healer.getState()->getName() << " HP:("
	    << healer.getState()->getHp() << "/"
	    << healer.getState()->getHpLimit() << "), "
	    << healer.getWeapon()->getTitle() <<" dmg:("
	    << healer.getWeapon()->getDamage() << "), MP:("
	    << healer.getMageState()->getMana() << "/"
	    << healer.getMageState()->getManaLimit() << ")." << std::endl;
	
	return out;
}
