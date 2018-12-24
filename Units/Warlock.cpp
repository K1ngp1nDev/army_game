/*_Created_by_K1ngp1n_*/

#include "Warlock.hpp"
#include "../Spells/Heal.hpp"
#include "../Spells/SummonDaemon.hpp"
#include "../Spells/Blast.hpp"
#include "../Spells/FireBall.hpp"
#include "../Exceptions/DaemonDoesNotExistException.hpp"
#include "../States/WarlockState.hpp"
#include "../Weapons/Fists.hpp"
#include "../Weapons/BlackStaff.hpp"
#include "../Interfaces/Observer.hpp"

Warlock::Warlock(AbstractState* state)
	: AbstractCaster(state) {}

Warlock::Warlock()
	: AbstractCaster(new WarlockState())
	, m_daemon(nullptr)
{
	this->m_special_ability = nullptr;
	this->spell = new SummonDaemon();
	this->m_attack = new ClassicAttack(this);
	this->m_weapon = new Fists(this);
	this->m_weapon = new BlackStaff(this);
	if ( !m_weapon->compare(this)) {
		this->m_weapon = new Fists(this);
	}
}

Warlock::~Warlock() {
	if (m_daemon) {
		delete m_daemon;
	}
	delete m_special_ability;
	delete m_attack;
	delete spell;
	Observer::getInstance()->informObserver(this);
}
Daemon *Warlock::getDaemon() const {
	if ( m_daemon == nullptr ) {
		std::cout << "throw exeption no daemon" << std::endl;
		return nullptr;
	} else {
		return m_daemon;
	}
}

void Warlock::summonDaemon() {
	if ( m_daemon != nullptr ) {
		BattleField::getInstance()->clearPointAndDelUnit(m_daemon);
		this->setDemon(nullptr);
	}
	if ( (this->getMageState()->getMana() - spell->getCost() > 0 )) {
		this->getMageState()->expendMana(spell->getCost());

		std::cout << this->getState()->getName() << " cast *"
		          << spell->getSpellName()
		          << "*" << " on the " << this->getState()->getName()
		          <<  "." << std::endl;

		spell->castSpell(this);
	} else {
		std::cout << "throw mana exception" << std::endl;
	}

}

void Warlock::castSpell(AbstractUnit *target, Spell spell) {
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

void Warlock::setDemon(Daemon *daemon) {
	m_daemon = daemon;
}

void Warlock::attack(AbstractUnit *enemy) {
	m_attack->makeAttack(this,enemy);
}

void Warlock::counterAttack(AbstractUnit *enemy) {
	m_attack->makeCounterAttack(this,enemy);

}

void Warlock::clickSpecialAbility() {
	m_special_ability->specialAbilityActivate();
	
}

std::ostream &operator<<(std::ostream &out, const Warlock &warlock) {
	out << warlock.getState()->getName() << " HP:("
	    << warlock.getState()->getHp() << "/"
	    << warlock.getState()->getHpLimit() << "), "
	    << warlock.getWeapon()->getTitle() <<" dmg:("
	    << warlock.getWeapon()->getDamage() << "), MP:("
		<< warlock.getMageState()->getMana() << "/"
		<< warlock.getMageState()->getManaLimit() << ")." << std::endl;

	return out;
}
