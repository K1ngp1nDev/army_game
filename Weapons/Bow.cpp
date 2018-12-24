/*_Created_by_K1ngp1n_*/

#include "Bow.hpp"

Bow::Bow(AbstractUnit *holder)
//                                 dmg range str dex int

	: AbstractWeapon(holder, "bow", 1.6,  4,  30, 40, 20)

{}

Bow::~Bow() {

}