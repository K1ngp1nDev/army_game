/*_Created_by_K1ngp1n_*/

#include "HumanWolfState.hpp"
#include "WereWolfState.hpp"


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

//void WereWolf::transform() {
//	WereWolfState* source = this->human_state;
//
//	if ( human_state->isWereWolfGet() == false ) {
//		std::cout << "*TRANSFORMATION IN WOLF" << std::endl;
//		this->setState(new WereWolfState("Wolf",this->getState()->getHpLimit()*2.2
//			, this->getState()->getHp()*2.2
//			, this->getState()->getDamage()*2.2))
//			, this->human_state->setWereWolf(true);
//	} else {
//		std::cout << "*TRANSFORMATION IN HUMAN" << std::endl;
//		if ( this->getState()->getHp() > source->getHp() ) {
//			this->setState(new WereWolfState(source->getName(),source->getHpLimit(),source->getHp(),source->getDamage()));
//		} else {
//			this->setState(new WereWolfState(source->getName(),source->getHpLimit(),this->getState()->getHp(),source->getDamage()));
//
//		}
//		this->human_state->setWereWolf(false);
//	}
//}
