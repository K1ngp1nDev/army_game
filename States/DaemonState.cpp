/*_Created_by_K1ngp1n_*/

#include "DaemonState.hpp"

DaemonState::DaemonState(std::string name, int strenght, int dexterity, int intelligence)
	: SoldierState(name,strenght,dexterity,intelligence)
{}

DaemonState::DaemonState()
	: SoldierState("Demon", 13, 12, 11)
{}

DaemonState::~DaemonState() {}

int DaemonState::getHpLimit() const {
	return SoldierState::getHpLimit();
}

int DaemonState::getHp() const {
	return SoldierState::getHp();
}

//double RogueState::getDamage() const {
//	return SoldierState::getDamage();
//}

const std::string DaemonState::getName() const {
	return SoldierState::getName();
}

void DaemonState::setName(const std::string newName) {
	SoldierState::setName(newName);
}

void DaemonState::setHpLimit(int hitPointsLimit) {
	SoldierState::setHpLimit(hitPointsLimit);
}

void DaemonState::setHp(int hitPoints) {
	SoldierState::setHp(hitPoints);
}
//
//void RogueState::setDamage(double damage) {
//	SoldierState::setDamage(damage);
//}

int DaemonState::getStrenght() const {
	return SoldierState::getStrenght();
}

int DaemonState::getDexterity() const {
	return SoldierState::getDexterity();
}

int DaemonState::getIntelligence() const {
	return SoldierState::getIntelligence();
}

int DaemonState::getStep() const {
	return SoldierState::getStep();
}

//int RogueState::getRange() const {
//	return SoldierState::getRange();
//}

void DaemonState::setStrenght(int newStrenght) {
	SoldierState::setStrenght(newStrenght);
}

void DaemonState::setDexterity(int newDexterity) {
	SoldierState::setDexterity(newDexterity);
}

void DaemonState::setIntelligence(int newIntelligence) {
	SoldierState::setIntelligence(newIntelligence);
}

void DaemonState::setStep(int newStep) {
	SoldierState::setStep(newStep);
}