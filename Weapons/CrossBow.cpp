/*_Created_by_K1ngp1n_*/

#include "CrossBow.hpp"

CrossBow::CrossBow(AbstractUnit *holder)
	//                                   dmg range str dex int

	: AbstractWeapon(holder, "crossbow", 2.2,  3,  40, 20, 10)

{}

CrossBow::~CrossBow() {

}
