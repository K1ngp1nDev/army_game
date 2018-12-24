///*_Created_by_K1ngp1n_*/
//
//#include "AbstractState.hpp"
//
//AbstractState::AbstractState()
//	: name("")
//	, strenght(1)
//	, dexterity(1)
//	, intelligence(1)
//	, hpLimit(100)
//	, hp(hpLimit)
//	, dmg(0)
//	, step(1)
//	, range(1)
//
//{}
//
//AbstractState::~AbstractState() {}
//
//void AbstractState::isAlive() {
//	if ( this->getHp() <= 0 ) {
//		std::cout << "Here unit is dead exception" << std::endl;
////		throw UnitIsDeadException("Unit is dead exception");
//	}
//}
//
//int AbstractState::getStrenght() const {
//	return this->strenght;
//}
//int AbstractState::getDexterity() const {
//	return this->dexterity;
//}
//int AbstractState::getIntelligence() const {
//	return this->intelligence;
//}
//
//void AbstractState::setStrenght(int newStrenght) {
//	if ( this->strenght != newStrenght ) {
//		this->strenght = newStrenght;
//	}
//}
//void AbstractState::setDexterity(int newDexterity) {
//	if ( this->dexterity != newDexterity ) {
//		this->dexterity = newDexterity;
//	}
//}
//void AbstractState::setIntelligence(int newIntelligence) {
//	if ( this->intelligence != newIntelligence ) {
//		this->intelligence = newIntelligence;
//	}
//}
//
//int AbstractState::getStep() const {
//	return this->step;
//}
//
//int AbstractState::getRange() const {
//	return this->range;
//}
//
//int AbstractState::getHpLimit() const {
//	return this->hpLimit;
//}
//
//int AbstractState::getHp() const {
//	return this->hp;
//}
//int AbstractState::getDamage() const {
//	return this->dmg;
//}
//
//const std::string AbstractState::getName() const {
//	return this->name;
//}
//
//void AbstractState::setStep(int newStep) {
//	if ( this->step != newStep ) {
//		this->step = newStep;
//	}
//}
//
//void AbstractState::setRange(int newRange) {
//	if ( this->range != newRange ) {
//		this->range = newRange;
//	}
//}
//
//void AbstractState::setName(const std::string newName) {
//	if ( this->name != newName ) {
//		this->name = newName;
//	}
//}
//
//void AbstractState::setHp(int hitPoints) {
//	isAlive();
//	if ( hitPoints < 0 ) {
//		hitPoints = 0;
//	}
//	this->hp = hitPoints;
//}
//
//
//void AbstractState::setHpLimit(int hitPointsLimit) {
//	if ( this->hpLimit != hitPointsLimit ) {
//		this->hpLimit = hitPointsLimit;
//	}
//}
//
//void AbstractState::setDamage(int coef_damage) {
//	if ( this->dmg != coef_damage ) {
//		this->dmg = coef_damage;
//	}
//}
//
////void AbstractState::takePhysicalDamage(int damage) {
////	this->setHp(damage);
////}
////
////void AbstractState::takeMagicDamage(int damage) {
////	this->setHp(damage);
////}
//
