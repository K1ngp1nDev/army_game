/*_Created_by_K1ngp1n_*/

#pragma once

#include <iostream>
#include "AbstractUnit.hpp"

class AbstractUnit;

class AbstractSpell {
	protected:
	const std::string spellName;
	int cost;
	int range;
	double points;
	public:
	AbstractSpell(const std::string spellName, int cost, double points, int range);
	virtual~AbstractSpell();

	virtual const std::string getSpellName() const;
	virtual int getCost() const;
	virtual double getPoints() const;
	virtual int getRange() const;
	void setPoints(int newPower);

	virtual void castSpell(AbstractUnit* target) = 0;

};



