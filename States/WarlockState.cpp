/*_Created_by_K1ngp1n_*/

#include "WarlockState.hpp"

WarlockState::WarlockState(std::string name, int strenght, int dexterity, int intelligence)
	: MageState("Warlock", 25, 15, 55)

{}

WarlockState::WarlockState()
	: MageState("Warlock", 25, 15, 55) {}

WarlockState::~WarlockState() {

}

int WarlockState::getManaLimit() const {
	return manaLimit;
}

int WarlockState::getMana() const {
	return mana;
}

void WarlockState::setManaLimit(int newManaLimit) {
	MageState::setManaLimit(newManaLimit);
}

void WarlockState::setMana(int newMana) {
	MageState::setMana(newMana);
}

void WarlockState::addMana(int points) {
	MageState::addMana(points);
}

void WarlockState::expendMana(int cost) {
	MageState::expendMana(cost);
}

int WarlockState::getHpLimit() const {
	return MageState::getHpLimit();
}

int WarlockState::getHp() const {
	return MageState::getHp();
}

const std::string WarlockState::getName() const {
	return MageState::getName();
}

int WarlockState::getStrenght() const {
	return MageState::getStrenght();
}

int WarlockState::getDexterity() const {
	return MageState::getDexterity();
}

int WarlockState::getIntelligence() const {
	return MageState::getIntelligence();
}

int WarlockState::getStep() const {
	return MageState::getStep();
}

void WarlockState::setName(const std::string newName) {
	MageState::setName(newName);
}

void WarlockState::setHpLimit(int hitPointsLimit) {
	MageState::setHpLimit(hitPointsLimit);
}

void WarlockState::setHp(int hitPoints) {
	MageState::setHp(hitPoints);
}

void WarlockState::setStrenght(int newStrenght) {
	MageState::setStrenght(newStrenght);
}

void WarlockState::setDexterity(int newDexterity) {
	MageState::setDexterity(newDexterity);
}

void WarlockState::setIntelligence(int newIntelligence) {
	MageState::setIntelligence(newIntelligence);
}

void WarlockState::setStep(int newStep) {
	MageState::setStep(newStep);
}
