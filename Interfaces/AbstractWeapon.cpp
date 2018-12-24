/*_Created_by_K1ngp1n_*/

#include "AbstractWeapon.hpp"
#include "AbstractUnit.hpp"
#include "AbstractState.hpp"

AbstractWeapon::AbstractWeapon(AbstractUnit *holder
	, std::string title
	, double coef_damage
	, int range
	, int weight
	, int agility
	, int mind)
{
	this->holder = holder;
	this->title = title;
	this->coef_damage = coef_damage;
	this->range = range;
	this->weight = weight;
	this->agility = agility;
	this->mind = mind;
}

AbstractWeapon::~AbstractWeapon() {

}
bool AbstractWeapon::compare(AbstractUnit* holder) const {
	if ( ( getWeight() <= holder->getState()->getStrenght())
	     && ( getAgility() <= holder->getState()->getDexterity())
	     && ( getMind() <= holder->getState()->getIntelligence()) ) {
		return true;
	} else {
		std::cout << holder->getState()->getName() << " can't hold this m_weapon" << std::endl;
		return false;
	}
}

std::string AbstractWeapon::getTitle() const {
	return this->title;
}

double AbstractWeapon::getCoef() const {
	return this->coef_damage;
}

int AbstractWeapon::getRange() const {
	return this->range;
}

int AbstractWeapon::getDamage() const {
	return (this->coef_damage * holder->getState()->getStrenght());
}
int AbstractWeapon::getWeight() const {
	return this->weight;
}
int AbstractWeapon::getAgility() const {
	return this->agility;
}
int AbstractWeapon::getMind() const {
	return this->mind;
}
void AbstractWeapon::showDemands() const {
	std::cout
		<< "w: " << weight
	    << ", a: " << agility
	    << ", i: " << mind
	    << "." << std::endl;
}


std::ostream &operator<<(std::ostream &out, const AbstractWeapon &weapon) {
	out << weapon.title << ": dmg(" << weapon.coef_damage << ")." << std::endl;

	return out;
}