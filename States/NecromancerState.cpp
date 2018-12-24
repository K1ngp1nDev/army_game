/*_Created_by_K1ngp1n_*/

#include "NecromancerState.hpp"

NecromancerState::NecromancerState(std::string name, int strenght, int dexterity, int intelligence)
	: MageState("Necromancer", 28, 25, 45)

{}

NecromancerState::NecromancerState()
	: MageState("Necromancer", 28, 25, 45) {}

NecromancerState::~NecromancerState() {

}

int NecromancerState::getManaLimit() const {
	return manaLimit;
}

int NecromancerState::getMana() const {
	return mana;
}

void NecromancerState::setManaLimit(int newManaLimit) {
	MageState::setManaLimit(newManaLimit);
}

void NecromancerState::setMana(int newMana) {
	MageState::setMana(newMana);
}

void NecromancerState::addMana(int points) {
	MageState::addMana(points);
}

void NecromancerState::expendMana(int cost) {
	MageState::expendMana(cost);
}

int NecromancerState::getHpLimit() const {
	return MageState::getHpLimit();
}

int NecromancerState::getHp() const {
	return MageState::getHp();
}

const std::string NecromancerState::getName() const {
	return MageState::getName();
}

int NecromancerState::getStrenght() const {
	return MageState::getStrenght();
}

int NecromancerState::getDexterity() const {
	return MageState::getDexterity();
}

int NecromancerState::getIntelligence() const {
	return MageState::getIntelligence();
}

int NecromancerState::getStep() const {
	return MageState::getStep();
}

void NecromancerState::setName(const std::string newName) {
	MageState::setName(newName);
}

void NecromancerState::setHpLimit(int hitPointsLimit) {
	MageState::setHpLimit(hitPointsLimit);
}

void NecromancerState::setHp(int hitPoints) {
	MageState::setHp(hitPoints);
}

void NecromancerState::setStrenght(int newStrenght) {
	MageState::setStrenght(newStrenght);
}

void NecromancerState::setDexterity(int newDexterity) {
	MageState::setDexterity(newDexterity);
}

void NecromancerState::setIntelligence(int newIntelligence) {
	MageState::setIntelligence(newIntelligence);
}

void NecromancerState::setStep(int newStep) {
	MageState::setStep(newStep);
}
