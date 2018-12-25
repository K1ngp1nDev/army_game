/*_Created_by_K1ngp1n_*/

#include "Mage.hpp"
#include "../Spells/Blast.hpp"
#include "../Spells/FireBall.hpp"
#include "../Spells/Heal.hpp"
#include "../Weapons/Fists.hpp"
#include "../States/VampireState.hpp"
#include "../Weapons/BlackStaff.hpp"
#include "../Interfaces/Observer.hpp"

Mage::Mage(AbstractState* state)
	: AbstractCaster(state) {}

	Mage::Mage()
	: AbstractCaster(new MageState()) {
		this->m_special_ability = nullptr;
		this->m_attack = new ClassicAttack(this);
		this->m_weapon = new Fists(this);
		this->m_weapon = new BlackStaff(this);
		if ( !m_weapon->compare(this)) {
			this->m_weapon = new Fists(this);
		}
}

Mage::~Mage() {
	delete m_special_ability;
	delete m_attack;
	delete m_weapon;
	std::cout << this->getState()->getName() << " destructor" << std::endl;
	Observer::getInstance()->informObserver(this);
}

void Mage::castSpell(AbstractUnit *target, Spell spell) {
	auto it = getSpellBook().find(spell);

	AbstractSpell *_spell = it->second;
	m_spell = it->second;
	
	if (this->getMageState()->getMana() - _spell->getCost() > 0) {
		if (!BattleField::getInstance()->checkMagicDistance(this, target)) {
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

void Mage::attack(AbstractUnit *enemy) {
	m_attack->makeAttack(this,enemy);
}

void Mage::counterAttack(AbstractUnit *enemy) {
	m_attack->makeCounterAttack(this,enemy);
}

void Mage::clickSpecialAbility() {
	m_special_ability->specialAbilityActivate();
}

std::ostream &operator<<(std::ostream &out, const Mage &mage) {
	out << mage.getState()->getName() << " HP:("
	    << mage.getState()->getHp() << "/"
	    << mage.getState()->getHpLimit() << "), "
	    << mage.getWeapon()->getTitle() <<" dmg:("
	    << mage.getWeapon()->getDamage() << "), MP:("
	    << mage.getMageState()->getMana() << "/"
	    << mage.getMageState()->getManaLimit() << ")." << std::endl;
	return out;
}
