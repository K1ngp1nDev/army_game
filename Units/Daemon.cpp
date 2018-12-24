/*_Created_by_K1ngp1n_*/

#include "Daemon.hpp"
#include "../Units/Warlock.hpp"

Daemon::Daemon(AbstractState* state)
	: Soldier(state)
	{}



Daemon::Daemon(Warlock*owner)
	: Soldier(new DaemonState())
	, m_owner(owner)
{
	this->m_attack = new DaemonAttack(this,m_owner);
	this->m_weapon = new Fists(this);
}

Daemon::~Daemon() {
	m_owner->setDemon(nullptr);
	BattleField::getInstance()->clearPoint(this);
}


void Daemon::attack(AbstractUnit *enemy) {
	m_attack->makeAttack(this,enemy);
}

void Daemon::counterAttack(AbstractUnit *enemy) {
	m_attack->makeCounterAttack(this,enemy);
}

Warlock *Daemon::getOwner() const {
	return m_owner;
}


std::ostream &operator<<(std::ostream &out, const Daemon &daemon) {
	out << daemon.getState()->getName() << " HP:("
	    << daemon.getState()->getHp() << "/"
	    << daemon.getState()->getHpLimit() << "), "
	    << daemon.getWeapon()->getTitle() <<" dmg:("
	    << daemon.getWeapon()->getDamage() << ")."
	    << std::endl;

	return out;
}