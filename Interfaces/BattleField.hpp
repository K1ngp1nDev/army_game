/*_Created_by_K1ngp1n_*/

#pragma once

#include <iostream>
#include <map>
#include <set>
#include "Team.hpp"
#include <functional>
#include <ctype.h>
#include "../Controller/Action.hpp"
#include "../Interfaces/AbstractSpell.hpp"


//#include <winuser.h>

#define BOARDSIZE 9
class ActionMeleeAttack;
class ActionUnitMove;
class ActionMageCast;
class AbstractUnit;
class AbstractCaster;
class AbstractSpell;
class AbstractAttack;
class Team;
class Question;
class GamePlayInterface;

class BattleField {
	private:
	AbstractUnit* m_unit;
	Team *m_team;
	static BattleField* instance;
	protected:
	BattleField();
	~BattleField();

	int locationX;
	int locationY;
	char location[BOARDSIZE][BOARDSIZE];
	public:

	static BattleField* getInstance();
	std::map<std::pair<int, int>, AbstractUnit*> points;
    std::map<int, AbstractUnit*> m_selected_units;
	std::map<int, Action*> m_actions;
	std::map<int, AbstractSpell*> m_available_spells;
	std::map<int, std::pair<int, int>> m_free_points_to_move;
	std::map<std::string, std::pair<AbstractWeapon*, AbstractAttack*>> m_inventory;
	std::multimap<int, AbstractUnit*> m_available_targets;

	std::map<int, Action*> listOfActions(AbstractUnit *unit);
    std::set<EActionType> filterAvailableActions(AbstractUnit* unit);

    AbstractUnit* makeWereWolf(AbstractUnit* unit);
	int askSomeQuestion1(const std::string& question, const std::function<bool(int)>& answerHandler);
	void actionOfSelectedUnit(int answer);
	bool checkSector(int x, int y, AbstractUnit *unit);
	bool checkBounds(int x, int y, AbstractUnit *unit);
	bool checkDistanceMove(int x, int y, AbstractUnit *unit);
	bool checkWeaponDistance(AbstractUnit *unit, AbstractUnit *enemy);
	bool checkMagicDistance(AbstractCaster *m_unit, AbstractUnit *enemy);

	void checkArround(AbstractUnit *unit);
	void scanEnemies(AbstractUnit *unit);
	void scanAvailableDistanceToAllUnits(AbstractUnit *unit, int range);
	void scanAvailableDistanceEnemies(AbstractUnit *unit, int range);

	int getLocation();
	void clearPoint(AbstractUnit *target);
	void clearPointAndDelUnit(AbstractUnit *target);
	void markerOnBoard(AbstractUnit* unit);
	void moveToSector(int sectorX, int sectorY, AbstractUnit* unit);
	
	int getLocationX() const;
	int getLocationY() const;
	void setLocationXY(int positionX, int positionY);
	void printBattleField() const;

	void arrangeOnBoardTeamA(int sectorX, int sectorY, AbstractUnit *unit);
	void arrangeOnBoardTeamB(int sectorX, int sectorY, AbstractUnit *unit);

	void arrangeTeamA(AbstractUnit *unit);
	void arrangeTeamB(AbstractUnit *unit);
	int getLocationTargetX(AbstractUnit *unit);
	int getLocationTargetY(AbstractUnit *unit);

	void randomFactory(int multipleOfTeam);
	void factory(int player, int team);
	void manualFactory();

	void addUnitToListOfSelect(int choice, AbstractUnit *unit);

	AbstractUnit* getSelectUnit(int choice);

	AbstractUnit* selectUnitOnMField(int x, int y);

	Team* getTeam() const;
};



