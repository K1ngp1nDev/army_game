/*_Created_by_K1ngp1n_*/

#pragma once

#include <iostream>
#include <map>
#include "BattleField.hpp"
#include <cstdlib>
#include <time.h>

class BattleField;
class AbstractUnit;
class AbstractCaster;
class AbstractState;
class AbstractWeapon;

enum class select_team{
	blue = 1,
	red = 2,
};

class Team {
std::multimap<select_team, AbstractUnit*> m_team_units;

	public:
	Team();
	virtual~Team();

	void addUnitToTeam(select_team team, AbstractUnit *unit);

	void removeUnit(int team, AbstractUnit *unit);
	void showUnitsOnField(int team);

	int showPlayerTeam(AbstractUnit* unit) const;
	void randomFillUnitsOnBoard();
	bool checkTeam() const;
};



