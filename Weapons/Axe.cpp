/*_Created_by_K1ngp1n_*/

#include "Axe.hpp"

Axe::Axe(AbstractUnit *holder)
	: AbstractWeapon(holder, "axe", 3, 1, 60, 20, 10)
	{}

Axe::~Axe() {

}

std::string Axe::getTitle() const {
	return AbstractWeapon::getTitle();
}

int Axe::getRange() const {
	return AbstractWeapon::getRange();
}

int Axe::getDamage() const {
	return AbstractWeapon::getDamage();
}

int Axe::getWeight() const {
	return AbstractWeapon::getWeight();
}

int Axe::getAgility() const {
	return AbstractWeapon::getAgility();
}

int Axe::getMind() const {
	return AbstractWeapon::getMind();
}
