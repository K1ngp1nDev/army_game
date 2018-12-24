/*_Created_by_K1ngp1n_*/

#include "FireBall.hpp"
//#include "../Units/WereWolf.hpp"
#include "../Interfaces/BattleField.hpp"
#include "../Interfaces/AbstractState.hpp"
#include "../Interfaces/Observer.hpp"

FireBall::FireBall(const std::string name, int cost, int points, int range)
	: AbstractSpell(name, cost, points, range)
{}

FireBall::~FireBall() {}

void FireBall::castSpell(AbstractUnit *target) {
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
