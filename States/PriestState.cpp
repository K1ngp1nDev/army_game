/*_Created_by_K1ngp1n_*/

#include "PriestState.hpp"

PriestState::PriestState(std::string name, int strenght, int dexterity, int intelligence)
	: MageState("Priest", 26, 18, 52)

{}

PriestState::PriestState()
	: MageState("Priest", 26, 18, 52) {}

PriestState::~PriestState() {

}

int PriestState::getManaLimit() const {
	return manaLimit;
}

int PriestState::getMana() const {
	return mana;
}

void PriestState::setManaLimit(int newManaLimit) {
	MageState::setManaLimit(newManaLimit);
}

void PriestState::setMana(int newMana) {
	MageState::setMana(newMana);
}

void PriestState::addMana(int points) {
	MageState::addMana(points);
}

void PriestState::expendMana(int cost) {
	MageState::expendMana(cost);
}

int PriestState::getHpLimit() const {
	return MageState::getHpLimit();
}

int PriestState::getHp() const {
	return MageState::getHp();
}

const std::string PriestState::getName() const {
	return MageState::getName();
}

int PriestState::getStrenght() const {
	return MageState::getStrenght();
}

int PriestState::getDexterity() const {
	return MageState::getDexterity();
}

int PriestState::getIntelligence() const {
	return MageState::getIntelligence();
}

int PriestState::getStep() const {
	return MageState::getStep();
}

void PriestState::setName(const std::string newName) {
	MageState::setName(newName);
}

void PriestState::setHpLimit(int hitPointsLimit) {
	MageState::setHpLimit(hitPointsLimit);
}

void PriestState::setHp(int hitPoints) {
	MageState::setHp(hitPoints);
}

void PriestState::setStrenght(int newStrenght) {
	MageState::setStrenght(newStrenght);
}

void PriestState::setDexterity(int newDexterity) {
	MageState::setDexterity(newDexterity);
}

void PriestState::setIntelligence(int newIntelligence) {
	MageState::setIntelligence(newIntelligence);
}

void PriestState::setStep(int newStep) {
	MageState::setStep(newStep);
}
