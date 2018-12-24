/*_Created_by_K1ngp1n_*/

#include "VikingSword.hpp"

VikingSword::VikingSword(AbstractUnit *holder)
	: AbstractWeapon(holder, "viking sword", 2.15, 1, 50, 30, 10)
{}

VikingSword::~VikingSword() {

}

std::string VikingSword::getTitle() const {
	return AbstractWeapon::getTitle();
}

int VikingSword::getRange() const {
	return AbstractWeapon::getRange();
}

int VikingSword::getDamage() const {
	return AbstractWeapon::getDamage();
}

int VikingSword::getWeight() const {
	return AbstractWeapon::getWeight();
}

int VikingSword::getAgility() const {
	return AbstractWeapon::getAgility();
}

int VikingSword::getMind() const {
	return AbstractWeapon::getMind();
}
