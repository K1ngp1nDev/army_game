/*_Created_by_K1ngp1n_*/

#include "Vampire.hpp"
#include "../States/VampireState.hpp"
#include "../Abilities/VampireAttack.hpp"
#include "../Weapons/Teeth.hpp"
#include "../Interfaces/Undead.hpp"
#include "../Abilities/SpecialAbility.hpp"

Vampire::Vampire(AbstractState* state)
	: AbstractUnit(state) {}

Vampire::Vampire()
	: AbstractUnit(new VampireState()) {
	this->m_special_ability = nullptr;
	this->m_attribute = new Undead();
	this->m_attack = new VampireAttack(this);
	this->m_weapon = new Teeth(this);
}

Vampire::~Vampire() {
	delete m_special_ability;
	delete m_attack;
	delete m_weapon;
	delete m_attribute;
}

void Vampire::attack(AbstractUnit *enemy) {
	m_attack->makeAttack(this,enemy);
}

void Vampire::counterAttack(AbstractUnit *enemy) {
	m_attack->makeCounterAttack(this,enemy);
}

void Vampire::clickSpecialAbility() {
	m_special_ability->specialAbilityActivate();
}

std::ostream &operator<<(std::ostream &out, const Vampire &vampire) {
	out << vampire.getState()->getName() << " HP:("
	    << vampire.getState()->getHp() << "/"
	    << vampire.getState()->getHpLimit() << "), "
	    << vampire.getWeapon()->getTitle() <<" dmg:("
	    << vampire.getWeapon()->getDamage() << ")."
	    << std::endl;
	return out;
}
