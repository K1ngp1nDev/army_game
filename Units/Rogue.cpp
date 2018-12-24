/*_Created_by_K1ngp1n_*/

#include "Rogue.hpp"
#include "../Abilities/SpecialAbility.hpp"
#include "../Interfaces/Observer.hpp"

Rogue::Rogue(AbstractState* state)
	: AbstractUnit(state) {}

Rogue::Rogue()
	: AbstractUnit(new RogueState()) {
	this->m_special_ability = nullptr;
	this->m_attack = new RogueAttack(this);
	this->m_weapon = new Fists(this);
	this->m_weapon = new Dagger(this);
	if ( !m_weapon->compare(this)) {
		this->m_weapon = new Fists(this);
	}
}

Rogue::~Rogue() {
	delete m_special_ability;
	delete m_attack;
	delete m_weapon;
	Observer::getInstance()->informObserver(this);
}

void Rogue::attack(AbstractUnit *enemy) {
	m_attack->makeAttack(this,enemy);
}

void Rogue::counterAttack(AbstractUnit *enemy) {
	m_attack->makeCounterAttack(this,enemy);
}

void Rogue::clickSpecialAbility() {
	m_special_ability->specialAbilityActivate();
}

std::ostream &operator<<(std::ostream &out, const Rogue &rogue) {
	out << rogue.getState()->getName() << " HP:("
	    << rogue.getState()->getHp() << "/"
		<< rogue.getState()->getHpLimit() << "), "
		<< rogue.getWeapon()->getTitle() <<" dmg:("
		<< rogue.getWeapon()->getDamage() << ")."
		<< std::endl;

	return out;
}