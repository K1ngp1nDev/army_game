/*_Created_by_K1ngp1n_*/

#include "Teeth.hpp"

Teeth::Teeth(AbstractUnit *holder)
	: AbstractWeapon(holder, "teeth", 2, 1, 0, 0, 0)
{}

Teeth::~Teeth() {

}

std::string Teeth::getTitle() const {
	return AbstractWeapon::getTitle();
}

int Teeth::getRange() const {
	return AbstractWeapon::getRange();
}

int Teeth::getDamage() const {
	return AbstractWeapon::getDamage();
}
