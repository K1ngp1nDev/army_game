/*_Created_by_K1ngp1n_*/

#include "Fists.hpp"

Fists::Fists(AbstractUnit *holder)
	: AbstractWeapon(holder, "fists", 1, 1, 0, 0, 0)
{}

Fists::~Fists() {

}

std::string Fists::getTitle() const {
	return AbstractWeapon::getTitle();
}

int Fists::getRange() const {
	return AbstractWeapon::getRange();
}

int Fists::getDamage() const {
	return AbstractWeapon::getDamage();
}

int Fists::getWeight() const {
	return AbstractWeapon::getWeight();
}

int Fists::getAgility() const {
	return AbstractWeapon::getAgility();
}

int Fists::getMind() const {
	return AbstractWeapon::getMind();
}

void Fists::showDemands() const {
	AbstractWeapon::showDemands();
}

bool Fists::compare(AbstractUnit *holder) const {
	return AbstractWeapon::compare(holder);
}

//int Fists::calculateDamage(AbstractUnit *holder) {
//int dmg = holder->getState()->getStrenght()*0.25;
////calculate the actual damage strenght
//	return dmg;
//}
