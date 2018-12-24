/*_Created_by_K1ngp1n_*/

#include "GreaterHeal.hpp"
#include "../Interfaces/AbstractState.hpp"

GreaterHeal::GreaterHeal(const std::string name, int cost, int points, int range)
	: AbstractSpell(name, cost, points, range)
{}

GreaterHeal::~GreaterHeal() {}

void GreaterHeal::castSpell(AbstractUnit *target) {

	if (target->getState()->getHp() == 0 ) {
		std::cout << "You can't healing dead!" << std::endl;
		return;
	} else if ( (target->getState()->getHp() + points) > target->getState()->getHpLimit() ) {
		target->getState()->setHp(target->getState()->getHpLimit());
	} else {
		target->getState()->setHp(target->getState()->getHp()+points);
	}
}
