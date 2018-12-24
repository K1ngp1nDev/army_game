/*_Created_by_K1ngp1n_*/

#include "Berserker.hpp"
#include "../Abilities/SpecialAbility.hpp"
#include "../Interfaces/Observer.hpp"

Berserker::Berserker(AbstractState* state)
	: AbstractUnit(state) {}

Berserker::Berserker()
	: AbstractUnit(new BerserkState()) {
	this->m_special_ability = nullptr;
	this->m_attack = new ClassicAttack(this);
	this->m_weapon = new Fists(this);
	this->m_weapon = new Axe(this);
	if ( !m_weapon->compare(this)) {
		this->m_weapon = new Fists(this);
	}
}

Berserker::~Berserker() {
	delete m_special_ability;
	delete m_attack;
	delete m_weapon;
	std::cout << this->getState()->getName() << " destructor" << std::endl;
	Observer::getInstance()->informObserver(this);
	
}

void Berserker::attack(AbstractUnit *enemy) {
//	m_abstractState->isAlive();
	m_attack->makeAttack(this,enemy);
}

void Berserker::counterAttack(AbstractUnit *enemy) {
//	m_abstractState->isAlive();
	m_attack->makeCounterAttack(this,enemy);
}

void Berserker::clickSpecialAbility() {
	m_special_ability->specialAbilityActivate();

}

void Berserker::takeMagicDamage(int damage) {
	std::cout << this->getState()->getName() << " is invulnerable of magic " << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Berserker &berserker) {
	out << berserker.getState()->getName() << " HP:("
	    << berserker.getState()->getHp() << "/"
	    << berserker.getState()->getHpLimit() << "), "
	    << berserker.getWeapon()->getTitle() <<" dmg:("
	    << berserker.getWeapon()->getDamage() << ")."
	    << std::endl;
	return out;
}

