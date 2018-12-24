/*_Created_by_K1ngp1n_*/

#pragma once

#include <iostream>

class AbstractUnit;

class AbstractWeapon {
	public:
		AbstractUnit* holder;
		std::string title;
		double coef_damage;
		int range;
		int weight;
		int agility;
		int mind;
		AbstractWeapon(AbstractUnit *holder
			, std::string title
			, double coef_damage
			, int range
			, int weight
			, int agility
			, int mind);
		virtual~AbstractWeapon();

		virtual std::string getTitle() const;
		virtual double getCoef() const;
		virtual int getRange() const;
		virtual int getWeight() const;
		virtual int getAgility() const;
		virtual int getMind() const;
		virtual int getDamage() const;

		virtual void showDemands() const ;
		virtual bool compare(AbstractUnit* holder) const;
};

std::ostream& operator<<(std::ostream& out, const AbstractWeapon& weapon);

