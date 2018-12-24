/*_Created_by_K1ngp1n_*/

#include "HealerState.hpp"

HealerState::HealerState(std::string name, int strenght, int dexterity, int intelligence)
	: MageState("Healer", 22, 14, 57)

{}

HealerState::HealerState()
	: MageState("Healer", 22, 14, 57) {}

HealerState::~HealerState() {

}

int HealerState::getManaLimit() const {
	return manaLimit;
}

int HealerState::getMana() const {
	return mana;
}

void HealerState::setManaLimit(int newManaLimit) {
	MageState::setManaLimit(newManaLimit);
}

void HealerState::setMana(int newMana) {
	MageState::setMana(newMana);
}

void HealerState::addMana(int points) {
	MageState::addMana(points);
}

void HealerState::expendMana(int cost) {
	MageState::expendMana(cost);
}

int HealerState::getHpLimit() const {
	return MageState::getHpLimit();
}

int HealerState::getHp() const {
	return MageState::getHp();
}

const std::string HealerState::getName() const {
	return MageState::getName();
}

int HealerState::getStrenght() const {
	return MageState::getStrenght();
}

int HealerState::getDexterity() const {
	return MageState::getDexterity();
}

int HealerState::getIntelligence() const {
	return MageState::getIntelligence();
}

int HealerState::getStep() const {
	return MageState::getStep();
}

void HealerState::setName(const std::string newName) {
	MageState::setName(newName);
}

void HealerState::setHpLimit(int hitPointsLimit) {
	MageState::setHpLimit(hitPointsLimit);
}

void HealerState::setHp(int hitPoints) {
	MageState::setHp(hitPoints);
}

void HealerState::setStrenght(int newStrenght) {
	MageState::setStrenght(newStrenght);
}

void HealerState::setDexterity(int newDexterity) {
	MageState::setDexterity(newDexterity);
}

void HealerState::setIntelligence(int newIntelligence) {
	MageState::setIntelligence(newIntelligence);
}

void HealerState::setStep(int newStep) {
	MageState::setStep(newStep);
}
