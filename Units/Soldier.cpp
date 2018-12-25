/*_Created_by_K1ngp1n_*/

#include "Soldier.hpp"
#include "../Abilities/SpecialAbility.hpp"
#include "../Interfaces/Observer.hpp"

Soldier::Soldier(AbstractState* state)
	: AbstractUnit(state) {}

Soldier::Soldier()
	: AbstractUnit(new SoldierState()) {
	this->m_mount = new Mount(this);
	this->m_special_ability = this->m_mount;
	this->m_attack = new ClassicAttack(this);
	this->m_weapon = new Fists(this);
	this->m_weapon = new VikingSword(this);
	if ( !m_weapon->compare(this)) {
		this->m_weapon = new Fists(this);
	}
}

Soldier::~Soldier() {
	std::cout << this->getState()->getName() << " destructor" << std::endl;
	Observer::getInstance()->informObserver(this);
}

void Soldier::attack(AbstractUnit *enemy) {
	m_attack->makeAttack(this,enemy);
}

void Soldier::counterAttack(AbstractUnit *enemy) {
	m_attack->makeCounterAttack(this,enemy);
}

void Soldier::clickSpecialAbility() {
	m_special_ability->specialAbilityActivate();
}

std::ostream &operator<<(std::ostream &out, const Soldier &soldier) {
	out << soldier.getState()->getName() << " HP:("
	    << soldier.getState()->getHp() << "/"
	    << soldier.getState()->getHpLimit() << "), "
		<< soldier.getWeapon()->getTitle() <<" dmg:("
		<< soldier.getWeapon()->getDamage() << ")."
	    << std::endl;
	return out;
}

