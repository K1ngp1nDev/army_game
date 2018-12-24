/*_Created_by_K1ngp1n_*/

#pragma once

#include <iostream>

#include "../Exceptions/UnitIsDeadException.hpp"
//#include "../Interfaces/AbstractUnit.hpp"
//
//class AbstractUnit;

class AbstractState {
	public:
//	AbstractState();
	virtual~AbstractState() {}

//	void isAlive();
	virtual int getStrenght() const = 0;
	virtual int getDexterity() const = 0;
	virtual int getIntelligence() const = 0;

	virtual int getStep() const = 0;
//	virtual int getRange() const = 0;
	virtual int getHpLimit() const = 0;
	virtual int getHp() const = 0;
//	virtual double getDamage() const = 0;
	virtual const std::string getName() const = 0;

	virtual void setStrenght(int newStrenght) = 0;
	virtual void setDexterity(int newDexterity) = 0;
	virtual void setIntelligence(int newIntelligence) = 0;

	virtual void setStep(int newStep) = 0;
//	virtual void setRange(int newRange) = 0;

	virtual void setName(const std::string newName) = 0;
	virtual void setHpLimit(int hitPointsLimit) = 0;
	virtual void setHp(int hitPoints) = 0;
//	virtual void setDamage(double damage) = 0;

//	virtual void calculateDamage(int str) = 0;
//	virtual void calculateHpLimit(int str) = 0;


};



