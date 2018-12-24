/*_Created_by_K1ngp1n_*/

#include "AbstractSpell.hpp"

AbstractSpell::AbstractSpell(const std::string spellName, int cost, double points, int range) :
spellName(spellName), cost(cost), points(points), range(range)
{}

AbstractSpell::~AbstractSpell() {

}

const std::string AbstractSpell::getSpellName() const {
	return this->spellName;
}

int AbstractSpell::getRange() const {
	return this->range;
}


int AbstractSpell::getCost() const {
	return this->cost;
}

double AbstractSpell::getPoints() const {
	return this->points;
}

void AbstractSpell::setPoints(int newPower) {
	if ( this->points != newPower ) {
		this->points = newPower;
	}
}
