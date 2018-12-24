#include "SoldierState.hpp"

/*_Created_by_K1ngp1n_*/

SoldierState::SoldierState(std::string name, int strenght, int dexterity, int intelligence)
	: name(name)
	, strenght(strenght)
	, dexterity(dexterity)
	, intelligence(intelligence)
	, hpLimit(strenght*8.5)
	, hp(hpLimit)
	, step(1)
{}

SoldierState::SoldierState()
	: AbstractState()
	, name("Soldier")
	, strenght(50)
	, dexterity(30)
	, intelligence(10)
	, hpLimit(strenght*8.5)
	, hp(hpLimit)
//	, dmg(strenght*0.65)
	, step(1)
//	, range(1)
{}

SoldierState::~SoldierState()
{}

int SoldierState::getHpLimit() const {
	return this->hpLimit;
}

int SoldierState::getHp() const {
	return this->hp;
}

//double SoldierState::getDamage() const {
//
//	return this->dmg;
//}

const std::string SoldierState::getName() const {
	return this->name;
}

int SoldierState::getStrenght() const {
	return this->strenght;
}

int SoldierState::getDexterity() const {
	return this->dexterity;
}

int SoldierState::getIntelligence() const {
	return this->intelligence;
}

int SoldierState::getStep() const {
	return this->step;
}

//int SoldierState::getRange() const {
//	return this->range;
//}

void SoldierState::setHpLimit(int hitPointsLimit) {
	if ( this->hpLimit != hitPointsLimit ) {
		this->hpLimit = hitPointsLimit;
	}
}

void SoldierState::setHp(int hitPoints) {
	if ( this->hp != hitPoints ) {
		this->hp = hitPoints;
	}
}

//void SoldierState::setDamage(double damage) {
//	if ( this->dmg != damage ) {
//		this->dmg = damage;
//	}
//}

void SoldierState::setName(const std::string newName) {
	if ( this->name != newName ) {
		this->name = newName;
	}
}

void SoldierState::setStrenght(int newStrenght) {
	if ( (this->strenght != newStrenght) && (newStrenght <= 199) ) {
		this->strenght = newStrenght;

		if ( getHp() != getHpLimit() ) {
			int tmp = getHpLimit() - getHp();

			setHpLimit(getStrenght()*8.5);
			setHp(getHpLimit()-tmp);
		} else {
			setHpLimit(getStrenght()*8.5);
			setHp(getHpLimit());
		}
//		setDamage(getStrenght()*0.65);
	}
}

void SoldierState::setDexterity(int newDexterity) {
	if ( (this->dexterity != newDexterity) && (newDexterity < 100) ) {
		this->dexterity = newDexterity;
	}
}

void SoldierState::setIntelligence(int newIntelligence) {
	if ( (this->intelligence != newIntelligence) && (newIntelligence < 100) ) {
		this->intelligence = newIntelligence;
	}
}

void SoldierState::setStep(int newStep) {
	if ( this->step != newStep)  {
		this->step = newStep;
	}
}

//void SoldierState::setRange(int newRange) {
//	if ( this->range != newRange)  {
//		this->range = newRange;
//	}
//}

//void SoldierState::calculateDamage(int str) {
//	setDamage(getStrenght()*0.25);
//}
//
//void SoldierState::calculateHpLimit(int str) {
//	setHpLimit(getStrenght()*3.5);
//}
