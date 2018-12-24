/*_Created_by_K1ngp1n_*/

#include "MageState.hpp"

MageState::MageState(std::string name, int strenght, int dexterity, int intelligence)
	: SoldierState(name,strenght,dexterity,intelligence)
	, manaLimit(intelligence*8.5)
	, mana(manaLimit)

{}

MageState::MageState()
	: SoldierState("Mage", 30, 10, 60)
	, manaLimit(60*8.5)
	, mana(manaLimit)
{}

MageState::~MageState() {

}

int MageState::getManaLimit() const {
	return this->manaLimit ;
}

int MageState::getMana() const {
	return this->mana;
}

void MageState::setManaLimit(int newManaLimit) {
	if ( this->manaLimit != newManaLimit ) {
		this->manaLimit = newManaLimit;
	}
}

void MageState::setMana(int newMana) {
	if ( this->mana != newMana ) {
		this->mana = newMana;
	}
}

int MageState::getHpLimit() const {
	return SoldierState::getHpLimit();
}

int MageState::getHp() const {
	return SoldierState::getHp();
}

//double MageState::getDamage() const {
//	return SoldierState::getDamage();
//}

const std::string MageState::getName() const {
	return SoldierState::getName();
}

void MageState::setName(const std::string newName) {
	SoldierState::setName(newName);
}

void MageState::setHpLimit(int hitPointsLimit) {
	SoldierState::setHpLimit(hitPointsLimit);
}

void MageState::setHp(int hitPoints) {
	SoldierState::setHp(hitPoints);
}

//void MageState::setDamage(double damage) {
//	SoldierState::setDamage(damage);
//}

int MageState::getStrenght() const {
	return SoldierState::getStrenght();
}

int MageState::getDexterity() const {
	return SoldierState::getDexterity();
}

int MageState::getIntelligence() const {
	return SoldierState::getIntelligence();
}

int MageState::getStep() const {
	return SoldierState::getStep();
}

void MageState::setStrenght(int newStrenght) {
	SoldierState::setStrenght(newStrenght);
}

void MageState::setDexterity(int newDexterity) {
	SoldierState::setDexterity(newDexterity);
}

void MageState::setIntelligence(int newIntelligence) {
	SoldierState::setIntelligence(newIntelligence);
}

void MageState::setStep(int newStep) {
	SoldierState::setStep(newStep);
}

void MageState::addMana(int points) {
	if ( (this->mana + points) <= this->manaLimit ) {
		this->mana += points;
	} else {
		this->mana = manaLimit;
	}
}

void MageState::expendMana(int cost) {
	if ( (this->mana - cost) >= 0 ) {
		this->mana -= cost;
	}
}

