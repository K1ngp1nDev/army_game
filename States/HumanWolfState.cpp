/*_Created_by_K1ngp1n_*/

#include "HumanWolfState.hpp"


HumanWolfState::HumanWolfState(std::string name, int strenght, int dexterity, int intelligence)
: SoldierState(name,strenght,dexterity,intelligence)
, isWereWolf(false)
{}

HumanWolfState::HumanWolfState()
	: SoldierState("Human-Wolf", 50,20,20)
{}

HumanWolfState::~HumanWolfState() {
}


bool HumanWolfState::isWereWolfGet() {
	if ( isWereWolf) {
		std::cout << "WOLF" << std::endl;
	} else {
		std::cout << "HUMAN" << std::endl;
	}
	return isWereWolf;
}


void HumanWolfState::setWereWolf(bool value) {
	if ( isWereWolf != value ) {
		isWereWolf = value;
	}
}
