/*_Created_by_K1ngp1n_*/

#include "Blast.hpp"
//#include "../Units/WereWolf.hpp"
#include "../Interfaces/AbstractState.hpp"
#include "../Interfaces/BattleField.hpp"
#include "../Interfaces/Observer.hpp"


Blast::Blast(const std::string name, int cost, double points, int range)
	: AbstractSpell(name, cost, points, range)
{}

Blast::~Blast() {}

void Blast::castSpell(AbstractUnit *target) {
	int m_damage = points;

	if (target->getState()->getIntelligence() <= 10 ) {
		m_damage *= 1.8;
	} else if (target->getState()->getIntelligence() <= 20) {
		m_damage *= 1.5;
	} else if (target->getState()->getIntelligence() <= 30 ) {
		m_damage *= 0.9;
	} else {
		m_damage *= 0.75;
	}

	if ((target->getState()->getHp() - m_damage) < 0 ) {
		target->getState()->setHp(0);
	} else {
		target->takeMagicDamage(m_damage);
	}
	if (target->getState()->getHp() == 0) {
//		Observer::getInstance()->informObserver(target);
//		Observer::getInstance()->informObservable(target);//victim is dead

		BattleField::getInstance()->clearPointAndDelUnit(target);

//		target->informObservers();
	}
}
