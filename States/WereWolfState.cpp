/////*_Created_by_K1ngp1n_*/
//
//#include "WereWolfState.hpp"
//#include "HumanWolfState.hpp"
//#include "MageState.hpp"
//#include "../States/SourceState.hpp"
//
//WereWolfState::WereWolfState(std::string name, int strenght, int dexterity, int intelligence)
//	: SoldierState(name,strenght,dexterity,intelligence)
//	, isWereWolf(true)
//
//{}
//
//WereWolfState::WereWolfState(AbstractState *_sourcestate) // SOURCE_STATE
//	: SoldierState("WereWolf", 70,30,0)
//{
//	if ( MageState* mage_state = dynamic_cast<MageState*>(_sourcestate) ) {
//		std::cout << _sourcestate << std::endl;
//		this->w_sourcestate = new SourceState(mage_state);
//		std::cout << mage_state << std::endl;
////		std::cout << w_sourcestate << std::endl;
////mage_state = dynamic_cast<MageState*>(w_sourcestate);
//
//		std::cout << mage_state->getName() << " test MAGE WEREWOLFSTATE.CPP  " << mage_state->getMana() << " work mana" << std::endl;
//	} else {
//		this->w_sourcestate = new SourceState(_sourcestate);
//		std::cout << w_sourcestate->getName() << " test NO MAG WEREFOLFSTATE.CPP " << std::endl;
//	}
//}
//
//WereWolfState::~WereWolfState() {
//	delete w_sourcestate;
//}
//
//AbstractState *WereWolfState::getSourceState() {
//	return w_sourcestate;
//}
//
//bool WereWolfState::isWereWolfGet() {
//	if ( isWereWolf) {
//		std::cout << "WOLF" << std::endl;
//	} else {
//		std::cout << "HUMAN" << std::endl;
//	}
//	return isWereWolf;
//}
//
//
//void WereWolfState::setWereWolf(bool value) {
//	if ( isWereWolf != value ) {
//		isWereWolf = value;
//	}
//}
