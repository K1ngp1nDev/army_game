/*_Created_by_K1ngp1n_*/

#include "Dagger.hpp"

Dagger::Dagger(AbstractUnit *holder)
	: AbstractWeapon(holder, "dagger", 1.75,1,10,50,10 )
{}

Dagger::~Dagger() {

}

//int Dagger::calculateDamage(AbstractUnit *holder) {
//	int dmg = holder->getState()->getStrenght()*1.25;
////	std::cout << "test " <<dmg * 2.5 << std::endl;
////calculate the actual damage strenght
//	return dmg;
//}
