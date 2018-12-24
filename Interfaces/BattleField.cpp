/*_Created_by_K1ngp1n_*/

#include <zconf.h>
#include "BattleField.hpp"
#include "actionfactory.h"
#include "AbstractCaster.hpp"
#include "AbstractAttack.hpp"
#include "AbstractUnit.hpp"
#include "AbstractWeapon.hpp"
#include "Attribute.hpp"
#include "Undead.hpp"
#include "Beast.hpp"
#include "Human.hpp"
#include "../Units/Daemon.hpp"
#include "../Units/Necromancer.hpp"
#include "../Units/Healer.hpp"
#include "../Units/Soldier.hpp"
#include "../Units/Rogue.hpp"
#include "../Units/Warlock.hpp"
#include "../Units/Mage.hpp"
#include "../Units/Berserker.hpp"
#include "../Units/Vampire.hpp"
#include "../Units/Priest.hpp"
#include "../Controller/ActionTransformation.hpp"
#include "../Controller/ActionSummonDaemon.hpp"
#include "../Controller/ActionUseMount.hpp"
#include "../Controller/ActionMageMeditation.hpp"
#include "../Controller/ActionRangeAttack.hpp"
#include "../Controller/ActionMeleeAttack.hpp"
#include "../Controller/ActionUnitMove.hpp"
#include "../Controller/ActionMageCast.hpp"
#include "../Controller/Question.hpp"
#include "../Controller/GamePlayInterface.hpp"
#include "../Weapons/CrossBow.hpp"
#include "../Weapons/Bow.hpp"
#include "../Weapons/BlackStaff.hpp"
#include "../Weapons/Fists.hpp"
#include "../Weapons/Claws.hpp"
#include "../Abilities/RangeAttack.hpp"
#include "../Abilities/Transformation.hpp"
#include "LycanthropeAttack.hpp"

BattleField::BattleField()
	: points()
{
	points.clear();
	this->locationX = 1;
	this->locationY = 1;

	for ( int i = 1; i < BOARDSIZE; i++) {
		for( int j = 1; j < BOARDSIZE; j++ ) {
			this->location[i][j] = '_';
		}
	}
	m_team = new Team;
	m_unit = nullptr;
}

BattleField::~BattleField() {
	delete m_team;
	delete m_unit;
}

BattleField* BattleField::instance = nullptr;

BattleField* BattleField::getInstance() {
	if (instance == nullptr) {
		instance = new BattleField();
	}
	return instance;
}

AbstractUnit *BattleField::makeWereWolf(AbstractUnit *unit) {
	m_unit = unit;
	if ( !dynamic_cast<Undead*>(unit) ) {
		
		Transformation* transformation = new Transformation(m_unit);
		transformation->add(m_unit);/**source soldier state save**/
		std::cout << m_unit->getState()->getName() << " "
		<< m_unit->getWeapon()->getTitle() << std::endl;
		
		m_unit->setSpecialAbility(transformation);
		m_unit->getState()->setName("Lycanthrope");
		m_unit->setWeapon(new Claws(m_unit));
		m_unit->setAttack(new LycanthropeAttack(m_unit));
		m_unit->setAttribute(new Beast);
		m_unit->getState()->setStep(2);
		transformation->add(m_unit);/**lycan state save**/
	}
	
	return m_unit;
}

bool BattleField::checkSector(int x, int y, AbstractUnit *unit) {
	std::map<std::pair<int, int>, AbstractUnit*>
	    ::const_iterator it = points.begin();

	if ( points.count(std::make_pair(x,y)) ) {
		return true;
	} else {
		return false;
	}
}

bool BattleField::checkBounds(int x, int y, AbstractUnit *unit) {
	if ( (x <= 0 ) || (y <= 0) || ( x >= BOARDSIZE ) || ( y >= BOARDSIZE ) ) {
		return false;
	} else {
		return true;
	}
}

bool BattleField::checkDistanceMove(int x, int y, AbstractUnit *unit) {
	int baseX = getLocationTargetX(unit);
	int baseY = getLocationTargetY(unit);
	int step = unit->getState()->getStep();

	if ( baseX != x ) {
		if ( ((baseX < x) && ((x - baseX) > step ) ) || ( (baseX > x) && (baseX - x ) > step )) {
			std::cout << "You can't move so far." << std::endl;
			return false;
		}
	}
	if ( baseY != y ) {
		if ( ((baseY < y) && ((y - baseY) > step ) ) || ( (baseY > y) && (baseY - y ) > step )) {
			std::cout << "You can't move so far." << std::endl;
			return false;
		}
	}
	std::cout << "You can move." << std::endl;
	return true;
}

bool BattleField::checkWeaponDistance(AbstractUnit *unit, AbstractUnit *enemy) {
	int myX = getLocationTargetX(unit);
	int myY = getLocationTargetY(unit);
	int enemyX = getLocationTargetX(enemy);
	int enemyY = getLocationTargetY(enemy);
	int range = unit->getWeapon()->getRange();
//	std::cout << range << std::endl;
//	std::cout << unit->getState()->getName() << " " << myX << "." << myY << std::endl;
//	std::cout << enemy->getState()->getName() << " " << enemyX << "." << enemyY << std::endl;
//		    5   +   1=6      5             5   - 1=4        5
	if ( !((myX + range) >= enemyX) || !((myX - range) <= enemyX) ) {
//		std::cout << "Can't get, locationX." << std::endl;
		return false;
	}
//		    5   +   1=6      5             5   - 1=4        3
	if ( !((myY + range) >= enemyY) || !((myY - range) <= enemyY) ) {
//		std::cout << "Can't get, locationY." << std::endl;
		return false;
	}
//	std::cout << unit->getState()->getName() << " can attack."<< std::endl;
	return true;
}

bool BattleField::checkMagicDistance(AbstractCaster *m_unit, AbstractUnit *enemy) {
	int myX = getLocationTargetX(m_unit);
	int myY = getLocationTargetY(m_unit);
	int enemyX = getLocationTargetX(enemy);
	int enemyY = getLocationTargetY(enemy);
	int range = m_unit->getSpell()->getRange();

	if ( !((myX + range) >= enemyX) || !((myX - range) <= enemyX) ) {
		return false;
	}
	if ( !((myY + range) >= enemyY) || !((myY - range) <= enemyY) ) {
		return false;
	}
	return true;
}

void BattleField::markerOnBoard(AbstractUnit *unit) {
	std::string tmpName = unit->getState()->getName();
	
	char c = tmpName.at(0);
	
	c = tolower(c);
	location[getLocationTargetX(unit)][getLocationTargetY(unit)] = c;
}

void BattleField::checkArround(AbstractUnit *unit) {
int x = getLocationTargetX(unit);
int y = getLocationTargetY(unit);
int step = unit->getState()->getStep();
int count = 0;

	std::cout << "Selected " << unit->getState()->getName() << " (" << x << "." << y << ") can walk here: " << std::endl;
	if ( step == 1 ) {
		
		if ((checkBounds(x + step, y + step, unit)) && (!checkSector(x + step, y + step, unit))) {
			count++;
			
			m_free_points_to_move.insert(std::make_pair(count, std::make_pair((x + step), (y + step))));
		}
		if ((checkBounds(x - step, y - step, unit)) && (!checkSector(x - step, y - step, unit))) {
			count++;
			
			m_free_points_to_move.insert(std::make_pair(count, std::make_pair((x - step), (y - step))));
		}
		if ((checkBounds(x + step, y - step, unit)) && (!checkSector(x + step, y - step, unit))) {
			count++;
			
			m_free_points_to_move.insert(std::make_pair(count, std::make_pair((x + step), (y - step))));
		}
		if ((checkBounds(x - step, y + step, unit)) && (!checkSector(x - step, y + step, unit))) {
			count++;
			
			m_free_points_to_move.insert(std::make_pair(count, std::make_pair((x - step), (y + step))));
		}
		if ((checkBounds(x, y + step, unit)) && (!checkSector(x, y + step, unit))) {
			count++;
			
			m_free_points_to_move.insert(std::make_pair(count, std::make_pair((x), (y + step))));
		}
		if ((checkBounds(x, y - step, unit)) && (!checkSector(x, y - step, unit))) {
			count++;
			
			m_free_points_to_move.insert(std::make_pair(count, std::make_pair((x), (y - step))));
		}
		if ((checkBounds(x - step, y, unit)) && (!checkSector(x - step, y, unit))) {
			count++;
			
			m_free_points_to_move.insert(std::make_pair(count, std::make_pair((x - step), (y))));
		}
		if ((checkBounds(x + step, y, unit)) && (!checkSector(x + step, y, unit))) {
			count++;
			
			m_free_points_to_move.insert(std::make_pair(count, std::make_pair((x + step), (y))));
		}
		/**********************************************************************************/
		
	} else if ( step == 2 ) {
		int singleJump = 1;
			/**1 + 1*/
		if ( (checkBounds(x+singleJump,y+singleJump,unit)) && (!checkSector(x+singleJump, y+singleJump, unit)) ) {
			count++;
			
			m_free_points_to_move.insert(std::make_pair(count,std::make_pair((x+singleJump),(y+singleJump))));
			
			/**2 + 2*/
			if ( (checkBounds(x+step,y+step,unit)) && (!checkSector(x+step, y+step, unit)) ) {
				count++;
				
				m_free_points_to_move.insert(std::make_pair(count, std::make_pair((x + step), (y + step))));
			}
			/**1 + 2*/
			if ( (checkBounds(x+singleJump,y+step,unit)) && (!checkSector(x+singleJump, y+step, unit)) ) {
				count++;
				
				m_free_points_to_move.insert(std::make_pair(count, std::make_pair((x + singleJump), (y + step))));
			}
			/**2 + 1*/
			if ( (checkBounds(x+step,y+singleJump,unit)) && (!checkSector(x+step, y+singleJump, unit)) ) {
				count++;
				
				m_free_points_to_move.insert(std::make_pair(count, std::make_pair((x + step), (y + singleJump))));
			}
			
		}
		/****1 - 1*/
		if ( (checkBounds(x-singleJump,y-singleJump,unit)) && (!checkSector(x-singleJump, y-singleJump, unit)) ) {
			count++;
			
			m_free_points_to_move.insert(std::make_pair(count,std::make_pair((x-singleJump),(y-singleJump))));
			/**2 - 2*/
			if ( (checkBounds(x-step,y-step,unit)) && (!checkSector(x-step, y-step, unit)) ) {
				count++;
				
				m_free_points_to_move.insert(std::make_pair(count,std::make_pair((x-step),(y-step))));
			}
			/**1 - 2*/
			if ( (checkBounds(x-singleJump,y-step,unit)) && (!checkSector(x-singleJump, y-step, unit)) ) {
				count++;
				
				m_free_points_to_move.insert(std::make_pair(count,std::make_pair((x-singleJump),(y-step))));
			}
			/**2 - 1*/
			if ( (checkBounds(x-step,y-singleJump,unit)) && (!checkSector(x-step, y-singleJump, unit)) ) {
				count++;
				
				m_free_points_to_move.insert(std::make_pair(count,std::make_pair((x-step),(y-singleJump))));
			}
		}
			/**0 + 2*/
		if ( (checkBounds(x,y+step,unit)) && (!checkSector(x, y+step, unit)) ) {
			count++;
			
			m_free_points_to_move.insert(std::make_pair(count,std::make_pair((x),(y+step))));
			/**0 + 1*/
			if ( (checkBounds(x,y+singleJump,unit)) && (!checkSector(x, y+singleJump, unit)) ) {
				count++;
				
				m_free_points_to_move.insert(std::make_pair(count, std::make_pair((x), (y + singleJump))));
			}
			
		}
			/**0 - 2*/
		if ( (checkBounds(x,y-step,unit)) && (!checkSector(x, y-step, unit)) ) {
			count++;
			
			m_free_points_to_move.insert(std::make_pair(count,std::make_pair((x),(y-step))));
			
			/**0 - 1*/
			if ( (checkBounds(x,y-singleJump,unit)) && (!checkSector(x, y-singleJump, unit)) ) {
				count++;
				
				m_free_points_to_move.insert(std::make_pair(count, std::make_pair((x), (y - singleJump))));
			}
		}
			/**-2 0*/
		if ( (checkBounds(x-step,y,unit)) && (!checkSector(x-step, y, unit)) ) {
			count++;
			
			m_free_points_to_move.insert(std::make_pair(count,std::make_pair((x-step),(y))));
			/**-1 0*/
			if ( (checkBounds(x-singleJump,y,unit)) && (!checkSector(x-singleJump, y, unit)) ) {
				count++;
				
				m_free_points_to_move.insert(std::make_pair(count, std::make_pair((x - singleJump), (y))));
			}
			
		}
			/**+2 0*/
		if ( (checkBounds(x+step,y,unit)) && (!checkSector(x+step, y, unit)) ) {
			count++;
			
			m_free_points_to_move.insert(std::make_pair(count,std::make_pair((x+step),(y))));
			/**+1 0*/
			
			if ( (checkBounds(x+singleJump,y,unit)) && (!checkSector(x+singleJump, y, unit)) ) {
				count++;
				
				m_free_points_to_move.insert(std::make_pair(count, std::make_pair((x + singleJump), (y))));
			}
		}
		/**********************************************************************************/
		
	}
	count++;
	m_free_points_to_move.insert(std::make_pair(0,std::make_pair((x),(y))));/**automove**/
	m_free_points_to_move.insert(std::make_pair(99,std::make_pair((0),(0))));/**skip**/

	for ( std::map<int, std::pair<int, int>>::const_iterator it = m_free_points_to_move.begin();
	      it != m_free_points_to_move.end(); it++) {
		if ( !((*it).second.first == x && (*it).second.second == y) && !((*it).second.first == 0 && (*it).second.second == 0 ) )  {
			std::cout << (*it).first << ". (" << (*it).second.first << "." << (*it).second.second << ")" << std::endl;
		}
	}
	if ( m_free_points_to_move.count(1) ) {
		std::cout << "0. Move to nearest enemy(NOT WORKING)." << std::endl;
		std::cout << "99. Skip. " << std::endl;
	}
}

void BattleField::scanEnemies(AbstractUnit *unit) {
	int distanceX = BattleField::getInstance()->getLocationTargetX(unit);
	int distanceY = BattleField::getInstance()->getLocationTargetY(unit);
	int range = unit->getWeapon()->getRange();
	int count = 1;
	std::string tmpName = unit->getState()->getName();

	if ( AbstractCaster* caster = dynamic_cast<AbstractCaster*>(unit) ) {
		range = caster->getWeapon()->getRange();

		for( std::map<std::pair<int, int>, AbstractUnit*>::const_iterator it = points.begin();
		     it != points.end(); it++) {

			if ( (( it->first.first >= distanceX - range ) && ( it->first.second >= distanceY - range ))
			     && (( it->first.first <= distanceX + range ) && ( it->first.second <= distanceY + range ))
			     && ((BattleField::getInstance()->getTeam()->showPlayerTeam(it->second))
			         != ((BattleField::getInstance()->getTeam()->showPlayerTeam(caster)) ))	) {
//
				m_available_targets.insert(std::make_pair(count,it->second));
				count++;
			}
		}
		count = 1;
		for ( std::multimap<int,AbstractUnit*>::const_iterator iterator = m_available_targets.begin();
		      iterator != m_available_targets.end(); iterator++, count++ ) {
			std::cout << (iterator)->first << ". " << (iterator)->second->getState()->getName() << " : ("
			          << BattleField::getInstance()->getLocationTargetX((iterator)->second) << "."
			          << BattleField::getInstance()->getLocationTargetY((iterator)->second) << ")" << std::endl;
		}
		if ( m_available_targets.count(2) ) {
			//if key 2 == true, already key 1 == true
			count -= 1;
			int tmpKey = rand() % count + 1;

			std::cout << "0. Attack random enemy." << std::endl;
//		std::cout << "TMP TEST " << tmpKey << std::endl;

			m_available_targets.insert(std::make_pair(0,m_available_targets.find(tmpKey)->second));/**random enemy**/

		} else {
//			m_available_targets.clear();
			markerOnBoard(unit);
		}
	} else {
		for( std::map<std::pair<int, int>, AbstractUnit*>::const_iterator it = points.begin();
		     it != points.end(); it++) {

			if ( (( it->first.first >= distanceX - range ) && ( it->first.second >= distanceY - range ))
			     && (( it->first.first <= distanceX + range ) && ( it->first.second <= distanceY + range ))
			     && ((BattleField::getInstance()->getTeam()->showPlayerTeam(it->second))
			         != ((BattleField::getInstance()->getTeam()->showPlayerTeam(unit)) ))	) {
//
				m_available_targets.insert(std::make_pair(count,it->second));
				count++;
			}
		}
		count = 1;
		for ( std::multimap<int,AbstractUnit*>::const_iterator iterator = m_available_targets.begin();
		      iterator != m_available_targets.end(); iterator++, count++ ) {
			std::cout << (iterator)->first << ". " << (iterator)->second->getState()->getName() << ", ["
			<< (iterator)->second->getState()->getHp() << "/" << (iterator)->second->getState()->getHpLimit()
			<< ", with a " << (iterator)->second->getWeapon()->getTitle()
			<< ", (" << BattleField::getInstance()->getLocationTargetX((iterator)->second) << "."
			 << BattleField::getInstance()->getLocationTargetY((iterator)->second) << ")" << std::endl;
		}
		if ( m_available_targets.count(2) ) {

			count -= 1;
			int tmpKey = rand() % count + 1;

			std::cout << "0. Attack random enemy." << std::endl;
//		std::cout << "TMP TEST " << tmpKey << std::endl;

			m_available_targets.insert(std::make_pair(0,m_available_targets.find(tmpKey)->second));/**random enemy**/

		} else {
//			m_available_targets.clear();
			markerOnBoard(unit);
		}
	}
}

void BattleField::scanAvailableDistanceEnemies(AbstractUnit *unit, int range) {
	int distanceX = BattleField::getInstance()->getLocationTargetX(unit);
	int distanceY = BattleField::getInstance()->getLocationTargetY(unit);
	int count = 1;

//	if ( AbstractCaster* caster = dynamic_cast<AbstractCaster*>(unit) ) {
//		for (const std::pair<Spell, AbstractSpell*>& spellPair : caster->getSpellBook()) {
////			std::cout << (int) spellPair.first << ". "
////			          << spellPair.second->getSpellName() << std::endl;
//
//			m_available_spells.insert(std::make_pair((int) spellPair.first, spellPair.second));
//			range = spellPair.second->getRange();
//			std::cout << spellPair.second->getSpellName()  << " RANGE TEST: "  << range << std::endl;
			for ( std::map<std::pair<int, int>, AbstractUnit *>::const_iterator it = points.begin();
			      it != points.end(); it++ ) {

				if (((it->first.first >= distanceX - range) && (it->first.second >= distanceY - range))
				    && ((it->first.first <= distanceX + range) && (it->first.second <= distanceY + range))
				    && ((BattleField::getInstance()->getTeam()->showPlayerTeam(it->second))
				        != ((BattleField::getInstance()->getTeam()->showPlayerTeam(unit))))) {

//					std::cout << it->second->getState()->getName() << " "
//					<< BattleField::getInstance()->getLocationTargetX(it->second)
//					<< "."
//					<< BattleField::getInstance()->getLocationTargetY(it->second)
//					<< " add. " << std::endl;
					m_available_targets.insert(std::make_pair(count, it->second));
////					std::cout <<
					count++;
					/**-----**----**/
				}
			}
	          m_available_targets.insert(std::make_pair(0, unit)); // self point
	m_available_targets.insert(std::make_pair(99, unit)); // false point

//		std::cout << "0. Abort. ***NOT WORKING***" << std::endl;

		/*************************************************************************************/

		/*************************************************************************************/
//		caster
//		for ( caster->getSpellBook().find)
//check range of available spells / heal, blast..
//	} else {
//
////check range of weapon > 1 / bow, crossbow
//	}
}

void BattleField::scanAvailableDistanceToAllUnits(AbstractUnit *unit, int range) {
	int distanceX = BattleField::getInstance()->getLocationTargetX(unit);
	int distanceY = BattleField::getInstance()->getLocationTargetY(unit);
	int count = 1;

		/*************************************************************************************/
		for ( std::map<std::pair<int, int>, AbstractUnit *>::const_iterator it = points.begin();
		      it != points.end(); it++ ) {

			if ( (( it->first.first >= distanceX - range ) && ( it->first.second >= distanceY - range ))
			    && (( it->first.first <= distanceX + range ) && ( it->first.second <= distanceY + range )) ) {

				m_available_targets.insert(std::make_pair(count, it->second));

				count++;
			}
		}
		m_available_targets.insert(std::make_pair(0, unit)); // random point
		m_available_targets.insert(std::make_pair(99, unit)); // false point
}

void BattleField::clearPoint(AbstractUnit *target) {
	for( std::map<std::pair<int, int>, AbstractUnit*>::const_iterator it = points.begin();
	     it != points.end(); it++) {
		if((it->second) == target) {
//			std::cout << "delete point of " << (it)->second->getState()->getName() << std::endl;
			location[(it)->first.first][(it)->first.second] = 'x';

			points.erase(it);
			break;
		}
	}

	for( std::map<int, AbstractUnit*>::const_iterator iterator = m_selected_units.begin();
	     iterator != m_selected_units.end(); iterator++) {
		if ( iterator->second == target ) {
			m_selected_units.erase(iterator->first);
			break;
		}
	}

	getTeam()->removeUnit(getTeam()->showPlayerTeam(target), target);
}

void BattleField::clearPointAndDelUnit(AbstractUnit *target) {
	for( std::map<std::pair<int, int>, AbstractUnit*>::const_iterator it = points.begin();
	     it != points.end(); it++) {
		if((it->second) == target) {
//			std::cout << "FLAG BATTLE.CPP clearPointAndDelUnit   --- 1 " << std::endl;
//			std::cout << "delete point of " << (it)->second->getState()->getName() << std::endl;
			location[(it)->first.first][(it)->first.second] = 'x';
			
			points.erase(it);
			break;
		}
	}

	for( std::map<int, AbstractUnit*>::const_iterator iterator = m_selected_units.begin();
	     iterator != m_selected_units.end(); iterator++) {
		if ( iterator->second == target ) {
//			std::cout << "FLAG BATTLE.CPP clearPointAndDelUnit   --- 2 " << std::endl;

			m_selected_units.erase(iterator->first);
			break;
		}
	}

	getTeam()->removeUnit(getTeam()->showPlayerTeam(target), target);
	if ( target->getState()->getHp() <= 0 ) {
//		std::cout << "FLAG BATTLE.CPP clearPointAndDelUnit   --- 3 " << std::endl;

		delete target;
		return;
	}
}

void BattleField::moveToSector(int sectorX, int sectorY, AbstractUnit* unit) {
	std::map<std::pair<int, int>, AbstractUnit*>::const_iterator it = points.begin();
	std::string tmpName = unit->getState()->getName();

	if ( !checkBounds(sectorX,sectorY,unit)) {
		markerOnBoard(unit);
		
		return;
	}
	if ( !checkDistanceMove(sectorX,sectorY,unit) ) {
		markerOnBoard(unit);
		
		return;
	}
	if ( !checkSector(sectorX, sectorY, unit) ) {
		//
		for( std::map<std::pair<int, int>, AbstractUnit*>::const_iterator it = points.begin();
			 it != points.end(); it++) {
			if((it->second) == unit) {
				location[(it)->first.first][(it)->first.second] = '.';

				points.erase(it);
				break;
			}
		}
		//
		points.insert(std::make_pair(std::make_pair(sectorX,sectorY),unit));
		std::cout << unit->getState()->getName() << " going to ("
		          << sectorX << "." << sectorY << ")."<< std::endl;
		
		markerOnBoard(unit);
		
		
		return;
	} else {
		std::cout << unit->getState()->getName() << " can't move to the point ("
		<< sectorX << "." << sectorY << "), it is already taken " << std::endl;
		
		markerOnBoard(unit);
		
	}
}

int BattleField::getLocationX() const {
	return locationX;
}

int BattleField::getLocationY() const {
	return locationY;
}

void BattleField::setLocationXY(int positionX, int positionY) {
	if ( this->locationX != positionX ) {
		this->locationX = positionX;
	}
	if ( this->locationY != positionY ) {
		this->locationY = positionY;
	}
}

int BattleField::getLocation() {
	std::cout << locationX << "." << locationY << std::endl;
	return location[getLocationX()][getLocationY()];
}

int BattleField::getLocationTargetX(AbstractUnit *unit) {
int x = 0;
	for( std::map<std::pair<int, int>, AbstractUnit*>::const_iterator it = points.begin();
	     it != points.end(); it++) {
		if((it->second) == unit) {
			x = (it)->first.first;
//			location[x][y] = '*';
			break;
		}
	}
	if ( x == 0 ) {
//		std::cout << unit->getState()->getName() << " is not found on field." << std::endl;
	}
	return x;
}

int BattleField::getLocationTargetY(AbstractUnit *unit) {
	int y = 0;
	for( std::map<std::pair<int, int>, AbstractUnit*>::const_iterator it = points.begin();
	     it != points.end(); it++) {
		if((it->second) == unit) {
			y = (it)->first.second;
//			location[x][y] = '*';
			break;
		}
	}
	if ( y == 0 ) {
//		std::cout << unit->getState()->getName() << " is not found on field." << std::endl;
	}
	return y;
}
void BattleField::arrangeTeamA(AbstractUnit *unit) {
	arrangeOnBoardTeamA(1, 1, unit);
}

void BattleField::arrangeTeamB(AbstractUnit *unit) {
	arrangeOnBoardTeamB(8, 8, unit);
}

void BattleField::arrangeOnBoardTeamA(int sectorX, int sectorY, AbstractUnit *unit) {
	std::map<std::pair<int, int>, AbstractUnit *>::const_iterator it = points.begin();
	std::string tmpName = unit->getState()->getName();
//AAAAAAAAAAAAAAAAAAAAAAAAAAA
	int lastX = BOARDSIZE - 1;
//AAAAAAAAAAAAAAAAAAAAAAAAAAA
	int lastY = BOARDSIZE - 4;
//AAAAAAAAAAAAAAAAAAAAAAAAAAA

	if (!points.count(std::make_pair(sectorX, sectorY))) {
		

		points.insert(std::make_pair(std::make_pair(sectorX, sectorY), unit));
		markerOnBoard(unit);
		
		return;
	} else {
		for ( int i = 1; ((sectorX < lastX) || (sectorY < lastY)); i++ ) {
			if (points.count(std::make_pair(sectorX, sectorY))) {
				if (sectorX < lastX) {
					sectorX++;
				} else if (!points.count(std::make_pair(sectorX, sectorY))) {

					
					points.insert(std::make_pair(std::make_pair(sectorX, sectorY), unit));
					markerOnBoard(unit);
					
					return;
				} else {
					if ( sectorY < lastY ) {
						sectorY++;
						sectorX = 1;
					} else {

						std::cout << "All points is busy, can't add member." << std::endl;
						return;
					}
				}
			} else if (!points.count(std::make_pair(sectorX, sectorY))) {
				
				points.insert(std::make_pair(std::make_pair(sectorX, sectorY), unit));
				markerOnBoard(unit);
				
				return;
			}
		}
	}
}

void BattleField::arrangeOnBoardTeamB(int sectorX, int sectorY, AbstractUnit *unit) {
	std::map<std::pair<int, int>, AbstractUnit *>::const_iterator it = points.begin();
	std::string tmpName = unit->getState()->getName();

//BBBBBBBBBBBBBBBBBBBBBBBBBBB
	int lastX = BOARDSIZE - 7;
//BBBBBBBBBBBBBBBBBBBBBBBBBBB
	int lastY = BOARDSIZE - 4;
//BBBBBBBBBBBBBBBBBBBBBBBBBBB

	if (!points.count(std::make_pair(sectorX, sectorY))) {

		points.insert(std::make_pair(std::make_pair(sectorX, sectorY), unit));
		markerOnBoard(unit);
		
		return;
	} else {
		for ( int i = 1; ((sectorX > 1) || (sectorY > lastY)); i++ ) {
			if (points.count(std::make_pair(sectorX, sectorY))) {
				if (sectorX > 1) {
					sectorX--;
				} else if (!points.count(std::make_pair(sectorX, sectorY))) {

					points.insert(std::make_pair(std::make_pair(sectorX, sectorY), unit));
					markerOnBoard(unit);
					
					return;
				} else {
					if ( sectorX < lastX ) {
						sectorX = 8;
						sectorY--;
					} else {
						std::cout << "All points is busy, can't add member." << std::endl;
						return;
					}
				}
			} else if (!points.count(std::make_pair(sectorX, sectorY))) {

				points.insert(std::make_pair(std::make_pair(sectorX, sectorY), unit));
				markerOnBoard(unit);
				
				return;
			}
		}
	}
}

void BattleField::printBattleField() const {
	std::cout << "\n\n\n\n\n\n\n "<< std::endl;
	std::cout << "     *BATTLE FIELD*" << std::endl;
	std::cout << "*BLUE*             *RED*" << std::endl;

	std::cout << "*** 1 2 3 4 5 6 7 8 ***" << std::endl;

	for ( int i = 1; i < BOARDSIZE; i++ ) {
		std::cout << " " << i << " |";
		for ( int j = 1; j < BOARDSIZE; j++ ) {
			std::cout << this->location[i][j] << "|";
//			std::cout << getBoard() << "_";
		}
		std::cout << " " << i << std::endl;
	}
	std::cout << "*** 1 2 3 4 5 6 7 8 ***" << std::endl;
	std::cout << "*BLUE*             *RED*" << std::endl << std::endl;

}



Team *BattleField::getTeam() const {
	return m_team;
}

AbstractUnit* BattleField::selectUnitOnMField(int x, int y) {
//	std::map<std::pair<int, int>, AbstractUnit*>::const_iterator it = points.begin();

	for( std::map<std::pair<int, int>, AbstractUnit*>::const_iterator it = points.begin();
	     it != points.end(); it++) {
		if ( (x == it->first.first) && (y == it->first.second)) {
//					std::cout<< (it)->second->getState()->getName()  <<std::endl;
					m_unit = (it)->second;
		}
	}
	return m_unit;
}

bool fooOfMaxPlayersOnBoard(int value) {
	if ( value > 0 && value <= 30 ) {
		return true;
	}
	return false;
}

bool fooOfQuantPlayers(int value) {
	if ( value > 0 && value < 11 ) {
		return true;
	}
	return false;
}

bool fooOfSelectTeam(int value) {
	if ( value == 1 || value == 2 ) {
		return true;
	}
	return false;
}

void BattleField::manualFactory() {
	int key;
	int quantOfPlayersInTeam;
	int questionOfPLayer;
	int quantPlayersAdded = 0;
	int team = 0;
	std::string question;

	question = "*1*. (Equal teams)\n"
	           "*2*. (Not equal teams)\n"
	           "     Enter your choice: \n";

	key = askSomeQuestion1(question, &fooOfMaxPlayersOnBoard);
	/**************************************/

	if ( key == 1 ) { /*****EQUAL*****/

		question = "How many units will be in the teams?\n"
		           "      min: *1*, max: *30* \n";

		quantOfPlayersInTeam = askSomeQuestion1(question, &fooOfMaxPlayersOnBoard);
		/**************************************/

		question = "Select team: \n"
		           "*1* - BLUE;\n"
		           "*2* - RED;\n";

		if ( team == 0 ) {

			team = askSomeQuestion1(question, &fooOfSelectTeam);

			/**************************************/
			question = "Whom do you create: \n"
			           "*1*. Soldier.\n"
			           "*2*. Rogue. \n"
			           "*3*. Warlock\n"
			           "*4*. Mage\n"
			           "*5*. Berserker\n"
					   "*6*. Healer\n"
					   "*7*. Vampire\n"
			           "*8*. Priest\n"
			           "*9*. Necromancer\n"
			           "*10*. WereWolf\n";


			for ( ; quantPlayersAdded < quantOfPlayersInTeam; ) {
				questionOfPLayer = askSomeQuestion1(question, &fooOfQuantPlayers);
				factory(questionOfPLayer, team);
				quantPlayersAdded++;
				std::cout << quantPlayersAdded << " of "
				          << quantOfPlayersInTeam << " created in "
				          << team << " team." << std::endl;

			}
			/**************************************/

			quantPlayersAdded = 0;
			if ( team == 1 ) {
				team += 1;
			} else {
				team -= 1;
			}
			std::cout << std::endl << std::endl;

			std::cout << "Inverse team " << team << " selected." << std::endl;

			for ( ; quantPlayersAdded < quantOfPlayersInTeam; ) {
				questionOfPLayer = askSomeQuestion1(question, &fooOfQuantPlayers);
				factory(questionOfPLayer, team);
				quantPlayersAdded++;

				std::cout << quantPlayersAdded << " of "
				          << quantOfPlayersInTeam << " created in "
				          << team << " team." << std::endl;
			}
			/**************************************/
		} else if ( team == 1 ) {

			team = 2;

			/**************************************/
			question = "Whom do you create: \n"
			           "*1*. Soldier.\n"
			           "*2*. Rogue. \n"
			           "*3*. Warlock\n"
			           "*4*. Mage\n"
					   "*5*. Berserker\n"
			           "*6*. Healer\n"
			           "*7*. Vampire\n"
			           "*8*. Priest\n"
			           "*9*. Necromancer\n"
			           "*10*. WereWolf\n";
			
			std::cout << quantPlayersAdded << " of "
			          << quantOfPlayersInTeam << " created in "
			          << team << " team." << std::endl;

			for ( ; quantPlayersAdded <= quantOfPlayersInTeam; quantPlayersAdded++ ) {
				questionOfPLayer = askSomeQuestion1(question, &fooOfQuantPlayers);
				factory(questionOfPLayer, team);
			}
		} else {
			team = 1;

			/**************************************/
			question = "Whom do you create: \n"
			           "*1*. Soldier.\n"
			           "*2*. Rogue. \n"
			           "*3*. Warlock\n"
			           "*4*. Mage\n"
					   "*5*. Berserker\n"
			           "*6*. Healer\n"
			           "*7*. Vampire\n"
			           "*8*. Priest\n"
			           "*9*. Necromancer\n"
			           "*10*. WereWolf\n";
			
			std::cout << quantPlayersAdded << " of "
			          << quantOfPlayersInTeam << " created in "
			          << team << " team." << std::endl;

			for ( ; quantPlayersAdded <= quantOfPlayersInTeam; quantPlayersAdded++ ) {
				questionOfPLayer = askSomeQuestion1(question, &fooOfQuantPlayers);
				factory(questionOfPLayer, team);
			}
		}
	}
	if ( key == 2 ) { /*****NOT*EQUAL*****/

		question =  "Select team: \n"
			        "*1* - BLUE\n"
					"*2* - RED\n";

		team = askSomeQuestion1(question, &fooOfSelectTeam);
		/***************************************************************************/
		question = "How many units will be in the teams?\n"
		           "      min: *1*, max: *30* \n";
		/***************************************************************************/
		quantOfPlayersInTeam = askSomeQuestion1(question, &fooOfMaxPlayersOnBoard);
		/***************************************************************************/

		question = "Whom do you create: \n"
		           "*1*. Soldier.\n"
		           "*2*. Rogue. \n"
		           "*3*. Warlock\n"
		           "*4*. Mage\n"
				   "*5*. Berserker\n"
		           "*6*. Healer\n"
		           "*7*. Vampire\n"
		           "*8*. Priest\n"
		           "*9*. Necromancer\n"
		           "*10*. WereWolf\n";
		
		for ( ; quantPlayersAdded < quantOfPlayersInTeam; ) {
			questionOfPLayer = askSomeQuestion1(question, &fooOfQuantPlayers);
			factory(questionOfPLayer, team);
			quantPlayersAdded++;
			std::cout << quantPlayersAdded << " of "
			          << quantOfPlayersInTeam << " created in "
			          << team << " team." << std::endl;

		}
		/***************************************************************************/
		quantPlayersAdded = 0;
		if ( team == 1 ) {
			team += 1;
		} else {
			team -= 1;
		}
		std::cout << std::endl << std::endl;

		std::cout << "Inverse team " << team << " selected." << std::endl;
		/***************************************************************************/

		question = "How many units will be in the teams?\n"
		           "      min: *1*, max: *30* \n";

		quantOfPlayersInTeam = askSomeQuestion1(question, &fooOfMaxPlayersOnBoard);

		/***************************************************************************/

		question = "Whom do you create: \n"
		           "*1*. Soldier.\n"
		           "*2*. Rogue. \n"
		           "*3*. Warlock\n"
		           "*4*. Mage\n"
		           "*5*. Berserker\n"
		           "*6*. Healer\n"
		           "*7*. Vampire\n"
		           "*8*. Priest\n"
		           "*9*. Necromancer\n"
		           "*10*. WereWolf\n";
		
		/***************************************************************************/

		for ( ; quantPlayersAdded < quantOfPlayersInTeam; ) {
			questionOfPLayer = askSomeQuestion1(question, &fooOfQuantPlayers);
			factory(questionOfPLayer, team);
			quantPlayersAdded++;

			std::cout << quantPlayersAdded << " of "
			          << quantOfPlayersInTeam << " created in "
			          << team << " team." << std::endl;
		}
		/***************************************************************************/
	}
}


void BattleField::factory(int player, int team) {
	switch ( player ) {
		case 1: {
			Soldier *soldier = new Soldier;
			m_unit = soldier;
//			soldier->availableActions().insert(EActionType::RangeAttack);
//			m_unit->availableActions().insert(EActionType::Move);
//			m_unit->availableActions().insert(EActionType::MeleeAttack);
//			m_unit->availableActions().insert(EActionType::Ride);
//			m_unit->availableActions().insert(EActionType::RangeAttack);
			
			std::cout << *soldier << " created." << std::endl;
			if (team % 2 == 0) {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red, soldier);
				printBattleField();
			} else {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue, soldier);
				printBattleField();
			}
			break;
		}
		case 2: {
			Rogue *rogue = new Rogue;
//			rogue->availableActions().insert(EActionType::RangeAttack);
			
			std::cout << *rogue << " created." << std::endl;
			if (team % 2 == 0) {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red, rogue);
				printBattleField();

			} else {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue, rogue);
				printBattleField();
			}
			break;
		}
		case 3: {
			Warlock *warlock = new Warlock;
			std::cout << *warlock << " created." << std::endl;
			if (team % 2 == 0) {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red, warlock);
				printBattleField();

			} else {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue, warlock);
				printBattleField();
			}
			break;
		}
		case 4: {
			Mage *mage = new Mage;
			std::cout << *mage << " created." << std::endl;
			if (team % 2 == 0) {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red, mage);
				printBattleField();

			} else {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue, mage);
				printBattleField();
			}
			break;
		}
		case 5: {
			Berserker *berserker = new Berserker;
			std::cout << *berserker << " created." << std::endl;
			if (team % 2 == 0) {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red, berserker);
				printBattleField();
				
			} else {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue, berserker);
				printBattleField();
			}
			break;
		}
		case 6: {
			Healer *healer = new Healer;
			std::cout << *healer << " created." << std::endl;
			if (team % 2 == 0) {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red, healer);
				printBattleField();
				
			} else {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue, healer);
				printBattleField();
			}
			break;
		}
		case 7: {
			Vampire *vampire = new Vampire;
			std::cout << *vampire << " created." << std::endl;
			if (team % 2 == 0) {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red, vampire);
				printBattleField();
				
			} else {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue, vampire);
				printBattleField();
			}
			break;
		}
		case 8: {
			Priest *priest = new Priest;
			std::cout << *priest << " created." << std::endl;
			if (team % 2 == 0) {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red, priest);
				printBattleField();
				
			} else {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue, priest);
				printBattleField();
			}
			break;
		}
		case 9: {
			Necromancer *necromancer = new Necromancer;
			std::cout << *necromancer << " created." << std::endl;
			if (team % 2 == 0) {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red, necromancer);
				printBattleField();
				
			} else {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue, necromancer);
				printBattleField();
			}
			break;
		}
		case 10: {
			Soldier* wereWolf = new Soldier;
			makeWereWolf(wereWolf);
			std::cout << *wereWolf << " created." << std::endl;
			if (team % 2 == 0) {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red, wereWolf);
				printBattleField();
				
			} else {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue, wereWolf);
				printBattleField();
			}
			break;
		}
	}
}
/**
"Whom do you create: \n"
"*1*. Soldier.\n"
"*2*. Rogue. \n"
"*3*. Warlock\n"
"*4*. Mage\n"
"*5*. Berserker\n"
"*6*. Healer\n"
"*7*. Vampire\n"
"*8*. Priest\n"
"*9*. Necromancer\n"
"*10*. WereWolf\n";
*/
void BattleField::randomFactory(int multipleOfTeam) {
	int unit = rand() % 10 + 1;
// rotation of special units
//	if (unit > 2 && unit < 11) {
//		unit = rand() % 10 + 1;
//	}

	switch ( unit ) {
		case 1: {
			Soldier *soldier = new Soldier;

//				soldier->availableActions().insert(EActionType::Ride);
//				soldier->availableActions().insert(EActionType::RangeAttack);
//				soldier->availableActions().insert(EActionType::Move);
//				soldier->availableActions().insert(EActionType::MeleeAttack);
			
			std::cout << *soldier << " created." << std::endl;
			if (multipleOfTeam % 2 == 0) {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red, soldier);
			} else {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue, soldier);
			}
//			sleep(1);
			break;
		}
		case 2: {
			Rogue *rogue = new Rogue;
//				rogue->availableActions().insert(EActionType::RangeAttack);
//				rogue->availableActions().insert(EActionType::Move);
//				rogue->availableActions().insert(EActionType::MeleeAttack);
			std::cout << *rogue << " created." << std::endl;
			if (multipleOfTeam % 2 == 0) {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red, rogue);
			} else {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue, rogue);
			}
//			sleep(1);
			break;
		}
		case 3: {
			Warlock *warlock = new Warlock;
//				warlock->availableActions().insert(EActionType::RangeAttack);
//				warlock->availableActions().insert(EActionType::Move);
//				warlock->availableActions().insert(EActionType::MeleeAttack);
			std::cout << *warlock << " created." << std::endl;
			if (multipleOfTeam % 2 == 0) {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red, warlock);
			} else {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue, warlock);
			}
//			sleep(1);
			break;
			
		}
		case 4: {
			Mage *mage = new Mage;
//				soldier->availableActions().insert(EActionType::RangeAttack);
//				mage->availableActions().insert(EActionType::Move);
//				mage->availableActions().insert(EActionType::MeleeAttack);
			std::cout << *mage << " created." << std::endl;
			if (multipleOfTeam % 2 == 0) {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red, mage);
			} else {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue, mage);
			}
//			sleep(1);
			break;
			
		}
		case 5: {
			Berserker *berserker = new Berserker;
			std::cout << *berserker << " created." << std::endl;
			if (multipleOfTeam % 2 == 0) {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red, berserker);
			} else {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue, berserker);
			}
//			sleep(1);
			break;
			
		}
		case 6: {
			Healer *healer = new Healer;
			std::cout << *healer << " created." << std::endl;
			if (multipleOfTeam % 2 == 0) {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red, healer);
			} else {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue, healer);
			}
//			sleep(1);
			break;
			
		}
		case 7: {
			Vampire *vampire = new Vampire;
			std::cout << *vampire << " created." << std::endl;
			if (multipleOfTeam % 2 == 0) {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red, vampire);
			} else {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue, vampire);
			}
//			sleep(1);
			break;
			
		}
		case 8: {
			Priest *priest = new Priest;
			std::cout << *priest << " created." << std::endl;
			if (multipleOfTeam % 2 == 0) {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red, priest);
			} else {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue, priest);
			}
//			sleep(1);
			break;
			
		}
		case 9: {
			Necromancer *necromancer = new Necromancer;
			std::cout << *necromancer << " created." << std::endl;
			if (multipleOfTeam % 2 == 0) {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red, necromancer);
			} else {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue, necromancer);
			}
//			sleep(1);
			break;
			
		}
		case 10: {
			Soldier *wereWolf = new Soldier;
			makeWereWolf(wereWolf);
			std::cout << *wereWolf << " created." << std::endl;
			if (multipleOfTeam % 2 == 0) {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::red, wereWolf);
			} else {
				BattleField::getInstance()->getTeam()->addUnitToTeam(select_team::blue, wereWolf);
			}
//			sleep(1);
			break;
			
		}
	}
}

bool checkWeaponMeleeRange(AbstractWeapon* weapon) {
	if ( weapon->getRange() > 1 ) {
		return false;
	}
	return true;
}

void BattleField::addUnitToListOfSelect(int choice, AbstractUnit *unit) {
	m_selected_units.insert(std::make_pair(choice,unit));
}

//void BattleField::removeUnitToListOfSelect(int choice, AbstractUnit *unit) {
//	m_selected_units.erase(choice);
//	std::cout << choice << ". " << unit->getState()->getName() << " deleted from list" << std::endl;
//}

AbstractUnit *BattleField::getSelectUnit(int choice) {
m_unit = nullptr;
//int count = 1;

	for ( std::map<int, AbstractUnit *>::const_iterator it = m_selected_units.begin();
	      it != m_selected_units.end(); it++ ) {

		if ( choice == it->first ) {
			if ( dynamic_cast<Undead *>(it->second->getAttribute())) {
				m_unit = it->second;
				
				if (Soldier *soldier = dynamic_cast<Soldier *>(it->second)) {
					m_unit = soldier;
					
					if (!checkWeaponMeleeRange(soldier->getWeapon())) { //crossbow hold now
						m_inventory.insert(std::make_pair(soldier->getWeapon()->getTitle(),
						                                  std::make_pair(soldier->getWeapon(), soldier->getAttack())));
//						m_inventory.insert(std::make_pair("teeth"
//							, std::make_pair(new Teeth(soldier), new VampireAttack(soldier))));
						
					} else { // melee weapon hold now (TEETH)
						m_inventory.insert(std::make_pair(soldier->getWeapon()->getTitle(),
						                                  std::make_pair(soldier->getWeapon(), soldier->getAttack())));
						m_inventory.insert(std::make_pair("crossbow", std::make_pair(new CrossBow(soldier),
						                                                             new RangeAttack(soldier))));
					}
					
					std::cout << soldier->getState()->getName() << " selected." << std::endl << std::endl;
					/*****************************************************************************/
					std::string tmpName = soldier->getState()->getName();
					
					location[getLocationTargetX(soldier)][getLocationTargetY(soldier)] = tmpName.at(0);
					printBattleField();
					/*****************************************************************************/
					listOfActions(soldier);
					/*****************************************************************************/
					for ( std::map<int, Action *>::const_iterator iterator = m_actions.begin();
					      iterator != m_actions.end(); iterator++ ) {
						std::cout << (*iterator).first << ". " << (*iterator).second->getType() << std::endl;
					}
					return soldier;
				} else if (Rogue *rogue = dynamic_cast<Rogue *>(it->second)) {
					m_unit = rogue;
					
					if (!checkWeaponMeleeRange(rogue->getWeapon())) { //crossbow hold now
						
						std::cout << "add " << rogue->getWeapon()->getTitle() << " in map" << std::endl;
						m_inventory.insert(std::make_pair(rogue->getWeapon()->getTitle(),
						                                  std::make_pair(rogue->getWeapon(), rogue->getAttack())));

//						m_inventory.insert(std::make_pair("teeth"
//							, std::make_pair(new Teeth(rogue), new VampireAttack(rogue))));
						
					} else { // melee weapon hold now (TEETH)
						std::cout << "add " << rogue->getWeapon()->getTitle() << " in map" << std::endl;
						
						m_inventory.insert(std::make_pair(rogue->getWeapon()->getTitle(),
						                                  std::make_pair(rogue->getWeapon(), rogue->getAttack())));
						m_inventory.insert(
							std::make_pair("bow", std::make_pair(new Bow(rogue), new RangeAttack(rogue))));
					}
					
					std::cout << rogue->getState()->getName() << " selected." << std::endl << std::endl;
					/*****************************************************************************/
					std::string tmpName = rogue->getState()->getName();
					
					location[getLocationTargetX(rogue)][getLocationTargetY(rogue)] = tmpName.at(0);
					printBattleField();
					/*****************************************************************************/
					listOfActions(rogue);
					/*****************************************************************************/
					for ( std::map<int, Action *>::const_iterator iterator = m_actions.begin();
					      iterator != m_actions.end(); iterator++ ) {
						std::cout << (*iterator).first << ". " << (*iterator).second->getType() << std::endl;
					}
					return rogue;
				}
				/************UNDEAD MARKER */
				std::cout << m_unit->getState()->getName() << " selected." << std::endl << std::endl;
				/*****************************************************************************/
				std::string tmpName = m_unit->getState()->getName();
				
				location[getLocationTargetX(m_unit)][getLocationTargetY(m_unit)] = tmpName.at(0);
				printBattleField();
				/*****************************************************************************/
				listOfActions(m_unit);
				/*****************************************************************************/
				for ( std::map<int, Action *>::const_iterator iterator = m_actions.begin();
				      iterator != m_actions.end(); iterator++ ) {
					std::cout << (*iterator).first << ". " << (*iterator).second->getType() << std::endl;
				}
				return m_unit;
				/*****************************************************************************/
			} else if (dynamic_cast<Beast *>(it->second->getAttribute())) {
				m_unit = it->second;
				
				m_inventory.insert(std::make_pair(m_unit->getWeapon()->getTitle(),
				                                  std::make_pair(m_unit->getWeapon(), m_unit->getAttack())));
				std::cout << m_unit->getState()->getName() << " selected." << std::endl << std::endl;
				/*****************************************************************************/
				std::string tmpName = m_unit->getState()->getName();
				
				location[getLocationTargetX(m_unit)][getLocationTargetY(m_unit)] = tmpName.at(0);
				printBattleField();
				/*****************************************************************************/
				listOfActions(m_unit);
				/*****************************************************************************/
				for ( std::map<int, Action *>::const_iterator iterator = m_actions.begin();
				      iterator != m_actions.end(); iterator++ ) {
					std::cout << (*iterator).first << ". " << (*iterator).second->getType() << std::endl;
				}
				return m_unit;
				
			} else if (AbstractCaster *caster = dynamic_cast<AbstractCaster *>(it->second)) {
				m_unit = caster;
				
				caster->setAttack(new ClassicAttack(caster));
				caster->setWeapon(new Fists(caster));
				m_inventory.insert(std::make_pair(caster->getWeapon()->getTitle(),
				                                  std::make_pair(caster->getWeapon(), caster->getAttack())));
				caster->setWeapon(new BlackStaff(caster));
				m_inventory.insert(std::make_pair(caster->getWeapon()->getTitle(),
				                                  std::make_pair(caster->getWeapon(), caster->getAttack())));
				
				
				std::cout << caster->getState()->getName() << " selected." << std::endl << std::endl;
				/*****************************************************************************/
				std::string tmpName = caster->getState()->getName();
				
				location[getLocationTargetX(caster)][getLocationTargetY(caster)] = tmpName.at(0);
				printBattleField();
				/*****************************************************************************/
				listOfActions(caster);
				/*****************************************************************************/
				for ( std::map<int, Action *>::const_iterator iterator = m_actions.begin();
				      iterator != m_actions.end(); iterator++ ) {
					std::cout << (*iterator).first << ". " << (*iterator).second->getType() << std::endl;
				}
				return caster;
			} else if (Soldier *soldier = dynamic_cast<Soldier *>(it->second)) {
				m_unit = soldier;
				
				if (!checkWeaponMeleeRange(m_unit->getWeapon())) { //crossbow hold now
//
					m_inventory.insert(std::make_pair(soldier->getWeapon()->getTitle(),
					                                  std::make_pair(soldier->getWeapon(), soldier->getAttack())));
					
					soldier->setAttack(new ClassicAttack(soldier));
					soldier->setWeapon(new Fists(soldier));
					m_inventory.insert(std::make_pair(soldier->getWeapon()->getTitle(),
					                                  std::make_pair(soldier->getWeapon(), soldier->getAttack())));
					soldier->setWeapon(new VikingSword(soldier));
					m_inventory.insert(std::make_pair(soldier->getWeapon()->getTitle(),
					                                  std::make_pair(soldier->getWeapon(), soldier->getAttack())));
					soldier->setAttack(new RangeAttack(soldier));
					soldier->setWeapon(new CrossBow(soldier));
				} else { // melee weapon hold now
					soldier->setAttack(new RangeAttack(soldier));
					soldier->setWeapon(new CrossBow(soldier));
					m_inventory.insert(std::make_pair(soldier->getWeapon()->getTitle(),
					                                  std::make_pair(soldier->getWeapon(), soldier->getAttack())));
					
					soldier->setAttack(new ClassicAttack(soldier));
					soldier->setWeapon(new Fists(soldier));
					m_inventory.insert(std::make_pair(soldier->getWeapon()->getTitle(),
					                                  std::make_pair(soldier->getWeapon(), soldier->getAttack())));
					soldier->setWeapon(new VikingSword(soldier));
					m_inventory.insert(std::make_pair(soldier->getWeapon()->getTitle(),
					                                  std::make_pair(soldier->getWeapon(), soldier->getAttack())));
				}
				
				std::cout << soldier->getState()->getName() << " selected." << std::endl << std::endl;
				/*****************************************************************************/
				std::string tmpName = soldier->getState()->getName();
				
				location[getLocationTargetX(soldier)][getLocationTargetY(soldier)] = tmpName.at(0);
				printBattleField();
				/*****************************************************************************/
//
//				soldier->availableActions().insert(EActionType::Ride);
//				filterAvailableActions(soldier);
				listOfActions(soldier);
				/*****************************************************************************/
				for ( std::map<int, Action *>::const_iterator iterator = m_actions.begin();
				      iterator != m_actions.end(); iterator++ ) {
					
					std::cout << (*iterator).first << ". " << (*iterator).second->getType() << std::endl;
				}
				return soldier;
			} else if (Rogue *rogue = dynamic_cast<Rogue *>(it->second)) {
				m_unit = rogue;
				
				if (!checkWeaponMeleeRange(m_unit->getWeapon())) { //bow hold now
//
					m_inventory.insert(std::make_pair(rogue->getWeapon()->getTitle(),
					                                  std::make_pair(rogue->getWeapon(), rogue->getAttack())));
					
					rogue->setAttack(new RogueAttack(rogue));
					rogue->setWeapon(new Fists(rogue));
					m_inventory.insert(std::make_pair(rogue->getWeapon()->getTitle(),
					                                  std::make_pair(rogue->getWeapon(), rogue->getAttack())));
					rogue->setWeapon(new Dagger(rogue));
					m_inventory.insert(std::make_pair(rogue->getWeapon()->getTitle(),
					                                  std::make_pair(rogue->getWeapon(), rogue->getAttack())));
					rogue->setAttack(new RangeAttack(rogue));
					rogue->setWeapon(new Bow(rogue));
				} else { // melee weapon hold now
					rogue->setAttack(new RangeAttack(rogue));
					rogue->setWeapon(new Bow(rogue));
					m_inventory.insert(std::make_pair(rogue->getWeapon()->getTitle(),
					                                  std::make_pair(rogue->getWeapon(), rogue->getAttack())));
					
					rogue->setAttack(new RogueAttack(rogue));
					rogue->setWeapon(new Fists(rogue));
					m_inventory.insert(std::make_pair(rogue->getWeapon()->getTitle(),
					                                  std::make_pair(rogue->getWeapon(), rogue->getAttack())));
					rogue->setWeapon(new Dagger(rogue));
					m_inventory.insert(std::make_pair(rogue->getWeapon()->getTitle(),
					                                  std::make_pair(rogue->getWeapon(), rogue->getAttack())));
				}
				
				std::cout << rogue->getState()->getName() << " selected." << std::endl << std::endl;
				/*****************************************************************************/
				std::string tmpName = rogue->getState()->getName();
				
				location[getLocationTargetX(rogue)][getLocationTargetY(rogue)] = tmpName.at(0);
				printBattleField();
				/*****************************************************************************/
				listOfActions(rogue);
				/*****************************************************************************/
				for ( std::map<int, Action *>::const_iterator iterator = m_actions.begin();
				      iterator != m_actions.end(); iterator++ ) {
					std::cout << (*iterator).first << ". " << (*iterator).second->getType() << std::endl;
				}
				return rogue;
			} else {
				/*****************************************************************************/
				m_unit = it->second;
				std::cout << m_unit->getState()->getName() << " selected." << std::endl << std::endl;
				
				/*****************************************************************************/
				std::string tmpName = m_unit->getState()->getName();
				
				location[getLocationTargetX(m_unit)][getLocationTargetY(m_unit)] = tmpName.at(0);
				printBattleField();
				/*****************************************************************************/
				/**********/
				/**********/ listOfActions(m_unit);/**********/
				/**********/
				for ( std::map<int, Action *>::const_iterator iterator = m_actions.begin();
				      iterator != m_actions.end(); iterator++ ) {
					std::cout << (*iterator).first << ". " << (*iterator).second->getType() << std::endl;
				}
				
				return m_unit;
			}
		}
	}
	return m_unit;
}

bool canCastSpell(AbstractCaster* mage, Spell spellType) {
	AbstractSpell* spell = mage->getSpellBook().at(spellType);

	if (spell->getCost() > mage->getMageState()->getMana()) {
		return false;
	}
	switch (spellType) {
		case Spell::Blast:
		case Spell::FireBall:
		case Spell::Heal:
		default:
			return false;
	}
}

bool canCastAnySpell(AbstractCaster* mage) {
	if ( AbstractPhysician* physician = dynamic_cast<AbstractPhysician*>(mage) ) {
		for (const std::pair<Spell, AbstractSpell*>& spellPair : physician->_getHealerSpellBook()) {
			if (canCastSpell(physician, spellPair.first)) {
				return true;
			}
		}
	} else {
		
		for (const std::pair<Spell, AbstractSpell*>& spellPair : mage->getSpellBook()) {
			if (canCastSpell(mage, spellPair.first)) {
				return true;
			}
		}
	}
	return false;
}

std::map<int, Action*> BattleField::listOfActions(AbstractUnit *unit) {
	int count = 0;

	for (EActionType actionType : filterAvailableActions(unit)) {

	    if (Action* action = ActionFactory::create(actionType)) {

		    count++;
		    m_actions.insert(std::make_pair(count,action));
        }
    }
    return m_actions;
}

std::set<EActionType> BattleField::filterAvailableActions(AbstractUnit* unit) {
	std::set<EActionType> filteredActions;
//	m_unit = unit;
		/*********INFECTED BY WEREWOLF***************/
	if ( dynamic_cast<Transformation*>(unit->getSpecialAbility())
	  && (!dynamic_cast<Beast*>(unit->getAttribute())) ) {
		
		if (dynamic_cast<Soldier *>(unit)
		    || dynamic_cast<Rogue *>(unit)) {
			filteredActions.insert(EActionType::RangeAttack);
		} else if (dynamic_cast<AbstractCaster *>(unit)) {
			filteredActions.insert(EActionType::CastSpell);
			filteredActions.insert(EActionType::Meditation);
			
		}
		if (dynamic_cast<Warlock *>(unit)) {
			filteredActions.insert(EActionType::SummonDaemon);
		}
		filteredActions.insert(EActionType::Transformation);
		filteredActions.insert(EActionType::MeleeAttack);
		filteredActions.insert(EActionType::Move);
		return filteredActions;
		/*********WOLF STATE NOW******************/
	} else if ( dynamic_cast<Beast*>(unit->getAttribute()) ) {
		filteredActions.insert(EActionType::Transformation);
		filteredActions.insert(EActionType::MeleeAttack);
		filteredActions.insert(EActionType::Move);
		return filteredActions;
		/***DEMON by SOLD != RANGE*************/
	} else if ( dynamic_cast<Daemon*>(unit) ) {
		filteredActions.insert(EActionType::MeleeAttack);
		filteredActions.insert(EActionType::Move);
		return filteredActions;
		/*****SOLD + mount RIDE **/
	} else if ( dynamic_cast<Soldier*>(unit) ) {
		filteredActions.insert(EActionType::MeleeAttack);
		filteredActions.insert(EActionType::RangeAttack);
		filteredActions.insert(EActionType::Ride);
		filteredActions.insert(EActionType::Move);
		return filteredActions;
		/**ROGUE without mount **/
	} else if ( dynamic_cast<Rogue*>(unit) ) {
		filteredActions.insert(EActionType::MeleeAttack);
		filteredActions.insert(EActionType::Move);
		filteredActions.insert(EActionType::RangeAttack);
		return filteredActions;
		/**********ALL MAGE & WARLOCK*************/
	} else if ( dynamic_cast<AbstractCaster*>(unit) ) {
		filteredActions.insert(EActionType::CastSpell);
		filteredActions.insert(EActionType::Meditation);
		
		if (dynamic_cast<Warlock *>(unit)) {
			filteredActions.insert(EActionType::SummonDaemon);
		}
	filteredActions.insert(EActionType::MeleeAttack);
	filteredActions.insert(EActionType::Move);
		return filteredActions;
		/***BERSERK AND OTHER STNDRT UNITS*************/
	} else {
		filteredActions.insert(EActionType::MeleeAttack);
		filteredActions.insert(EActionType::Move);
		
	}
	
	return filteredActions;
}



//	for (EActionType actionType : unit->availableActions()) {
//        switch (actionType) {
//        case EActionType::CastSpell: {
//			AbstractCaster* mage = static_cast<AbstractCaster*>(unit);
//			if (canCastAnySpell(mage)) {
//				filteredActions.insert(actionType);
//			}
//        }
//        case EActionType::Ride: {
//        	std::cout << "case RIDE test" << std::endl;
//	        if ( dynamic_cast<Mount*>(unit->getSpecialAbility())
//	        && (!dynamic_cast<Beast*>(unit->getAttribute()))) {
//		        filteredActions.insert(actionType);
//	        }
//        }
//        case EActionType::RangeAttack: {
//	        if ((!dynamic_cast<Beast *>(unit->getAttribute()))) {
////	            && dynamic_cast<Soldier*>() ) {
//		        filteredActions.insert(actionType);
//	        }
//        }
//        case EActionType::Transformation: {
//	        if (dynamic_cast<Transformation *>(unit->getSpecialAbility()) ) {
//		        filteredActions.insert(actionType);
//	        }
//        }
//        case EActionType::SummonDaemon:
//	    case EActionType::Meditation:
//	    case EActionType::MeleeAttack: {
//	    	std::cout << "testmeleeattack in listofaction" << std::endl;
//		    filteredActions.insert(actionType);
//
//	    }
//	    case EActionType::Move:
//        filteredActions.insert(actionType);
//        default:
//            break;
//        }


bool mover(int answer) {
	if ( BattleField::getInstance()->m_free_points_to_move.count(answer) ) {
		return true;
	}
	return false;
}

bool target_check(int answer) {
	if ( BattleField::getInstance()->m_available_targets.count(answer) ) {
		return true;
	}
	return false;
}

bool spell_check(int answer) {
	if ( BattleField::getInstance()->m_available_spells.count(answer) ) {
		return true;
	}
	return false;
}

int BattleField::askSomeQuestion1(const std::string& question, const std::function<bool(int)>& answerHandler) {
	int answer = askQuestion(question);
	if ( !answerHandler(answer)) {
		std::cout << "try again" << std::endl;
		return askSomeQuestion1(question, answerHandler);
	}
	return answer;
}

int differenceX(AbstractUnit *m_unit, AbstractUnit *target) {
	int diffX = 0;

	if ( BattleField::getInstance()->getLocationTargetX(m_unit) < BattleField::getInstance()->getLocationTargetX(target) ) {
		diffX = BattleField::getInstance()->getLocationTargetX(target) - BattleField::getInstance()->getLocationTargetX(m_unit);
	} else if ( BattleField::getInstance()->getLocationTargetX(m_unit) == BattleField::getInstance()->getLocationTargetX(target) ) {
		diffX = 0;
	} else {
		diffX = BattleField::getInstance()->getLocationTargetX(m_unit) - BattleField::getInstance()->getLocationTargetX(target);
	}

	return diffX;
}

int differenceY(AbstractUnit *m_unit, AbstractUnit *target) {
	int diffY = 0;

	if ( BattleField::getInstance()->getLocationTargetY(m_unit) < BattleField::getInstance()->getLocationTargetY(target) ) {
		diffY = BattleField::getInstance()->getLocationTargetY(target) - BattleField::getInstance()->getLocationTargetY(m_unit);
	} else if ( BattleField::getInstance()->getLocationTargetY(m_unit) == BattleField::getInstance()->getLocationTargetY(target) ) {
		diffY = 0;
	} else {
		diffY = BattleField::getInstance()->getLocationTargetY(m_unit) - BattleField::getInstance()->getLocationTargetY(target);
	}

	return diffY;
}
//int diffY(AbstractUnit* unit, AbstractUnit* target) {
//	int diff;
//
//	return diff;
//}


void BattleField::actionOfSelectedUnit(int answer) {
	std::string question = "QUESTION";
	int key;

	if (ActionUnitMove *_move = dynamic_cast<ActionUnitMove *>(m_actions.find(answer)->second)) {

		printBattleField();
		checkArround(m_unit);

		if ( !m_free_points_to_move.count(1) ) {
	  
			std::cout << "You can't _move, all points is busy arround." << std::endl;
			_move->setUnit(m_unit);
			_move->setXY(0,0);
			_move->execute();

		} else {
			_move->setUnit(m_unit);
			question = "      Your move \n";
			key = askSomeQuestion1(question, &mover);

			if ( key == 0 ) { /*******AUTO MOVE TO NEAREST ENEMY***********/
				_move->setUnit(m_unit);
//
//				int quant = 0;
//
//
//				for ( std::map<int, std::pair<int, int>>::const_iterator it = m_free_points_to_move.begin();
//				      it != m_free_points_to_move.end(); it++, quant++ );
//				quant -= 2; // self point minus && rand point
//
//				if ( quant > 0 ) {
//					std::map<int, std::pair<int, int>>::const_iterator it;
//					it = m_free_points_to_move.find(1);
//
//
//					m_available_targets.clear(); //clear container for move anyway
//
//					scanAvailableDistanceEnemies(m_unit, 8); // scan enemies for move at 8*8-1(self) cell square
//					int nearestEnemyKey = 1;
//					int diffX;
//					int diffY;
//
//					for ( std::map<int,AbstractUnit*>::const_iterator it = m_available_targets.begin();
//					it != m_available_targets.end(); it++ ) {
////					std::cout << "it: " << it->first << " " << getLocationTargetX(it->second) << "." << getLocationTargetY(it->second) << std::endl;
//
//
//						if ( ((differenceX(m_unit, m_available_targets.find(nearestEnemyKey)->second)) > differenceX(m_unit, it->second)
//						|| ( differenceY(m_unit, m_available_targets.find(nearestEnemyKey)->second)) > differenceY(m_unit,it->second))
//						&& (getLocationTargetX(m_unit) != getLocationTargetX(it->second) && (getLocationTargetY(m_unit) != getLocationTargetY(it->second))) ) {
//
//							std::cout << "TEST 1 ---------- new target: " << it->second->getState()->getName() << " "
//							          << getLocationTargetX(it->second) << "." << getLocationTargetY(it->second)
//							          << std::endl;
//							m_available_targets.insert(std::make_pair(nearestEnemyKey, it->second));
//						}
//					}
//					/**********/
//					std::cout << "nearest key : " << nearestEnemyKey << std::endl;
//					/*********/
//
//					int tmpRemember = 1;
//
//					for ( std::map<int, std::pair<int, int>>::const_iterator it = m_free_points_to_move.begin();
//					    it != m_free_points_to_move.end(); it++ ) {
////
//						if ( (it->first > 0 && it->first < 99) ) {
////							std::cout << "nearest key TESTTTTTT SUKAAA : " << nearestEnemyKey << std::endl;
//
//							/**************************************************************************************/
//							/**(Rog(X) + Rog(step) < BOARD(8)) && (Rog(X) + Rog(step) < Mag(X) )**/
//							if ( (((getLocationTargetX(m_unit) + m_unit->getState()->getStep()) < BOARDSIZE)
//							     && ((getLocationTargetX(m_unit) + m_unit->getState()->getStep())
//							         < getLocationTargetX(m_available_targets.find(nearestEnemyKey)->second)))
//							    /**(Rog(Y) + Rog(step) < BOARD(8)) && (Rog(Y) + Rog(step) < Mag(Y) )**/
//							    && (((getLocationTargetY(m_unit) + m_unit->getState()->getStep()) < BOARDSIZE)
//							        && ((getLocationTargetY(m_unit) + m_unit->getState()->getStep())
//							            < getLocationTargetY(m_available_targets.find(nearestEnemyKey)->second))) ) {
//								/**************************************************************************************/
//
//								diffX = getLocationTargetX(m_available_targets.find(nearestEnemyKey)->second) -
//								        it->second.first;
//								diffY = getLocationTargetY(m_available_targets.find(nearestEnemyKey)->second) -
//								        it->second.second;
//								// tmpRemember = 1 point
//								if ( diffX < 0 ) {
//									diffX *= -1;
//								}
//								if ( diffY < 0 ) {
//									diffY *= -1;
//								}
//								/************************HERE IS - xeP Co6a4uU**********************************/
//								if ( (getLocationTargetX(m_available_targets.find(nearestEnemyKey)->second)
//								- m_free_points_to_move.find(tmpRemember)->second.first) < diffX
//								&& (getLocationTargetY(m_available_targets.find(nearestEnemyKey)->second)
//								- m_free_points_to_move.find(tmpRemember)->second.second) < diffY ) {
////									std::cout << "1. (blue)XY + step < BOARD && (blu)XY + step < (red)XY.\n"
//									std::cout << "test1    " << tmpRemember << " "
//									          << m_free_points_to_move.find(tmpRemember)->second.first << " < "
//									          << diffX << " && "
//									          << m_free_points_to_move.find(tmpRemember)->second.second << " < "
//									          << diffY << std::endl<< std::endl;
//									tmpRemember = it->first;
//								}
//							} else if ( (((getLocationTargetX(m_unit) - m_unit->getState()->getStep()) > 0)
//							             && ((getLocationTargetX(m_unit) - m_unit->getState()->getStep())
//							                 > getLocationTargetX(m_available_targets.find(nearestEnemyKey)->second)))
////
//							            && (((getLocationTargetY(m_unit) - m_unit->getState()->getStep()) > 0)
//							                && ((getLocationTargetY(m_unit) - m_unit->getState()->getStep())
//							                    >  getLocationTargetY(m_available_targets.find(nearestEnemyKey)->second))) ) {
//								/**************************************************************************************/
//
//								diffX = it->second.first - getLocationTargetX(m_available_targets.find(nearestEnemyKey)->second);
//								diffY = it->second.second - getLocationTargetY(m_available_targets.find(nearestEnemyKey)->second);
//
//								if ( diffX < 0 ) {
//									diffX *= -1;
//								}
//								if ( diffY < 0 ) {
//									diffY *= -1;
//								}
//
//								if ( (m_free_points_to_move.find(tmpRemember)->second.first
//								    - getLocationTargetX(m_available_targets.find(nearestEnemyKey)->second)) < diffX
//								    && (m_free_points_to_move.find(tmpRemember)->second.second
//								    - getLocationTargetY(m_available_targets.find(nearestEnemyKey)->second)) < diffY ) {
////									std::cout << "2. (blue)XY + step < BOARD && (blu)XY + step < (red)XY.\n"
//									std::cout << "test2    " <<tmpRemember << " "
//									          << m_free_points_to_move.find(tmpRemember)->second.first << " < "
//									          << diffX << " && "
//									          << m_free_points_to_move.find(tmpRemember)->second.second << " < "
//									          << diffY << std::endl<< std::endl;
//									tmpRemember = it->first;
//								}
//							} else if ( (((getLocationTargetX(m_unit) - m_unit->getState()->getStep()) > 0 )
//							             && ((getLocationTargetX(m_unit) - m_unit->getState()->getStep())
//							                 > getLocationTargetX(m_available_targets.find(nearestEnemyKey)->second)))
//							            /**(Rog(Y) + Rog(step) < BOARD(8)) && (Rog(Y) + Rog(step) < Mag(Y) )**/
//							            && (((getLocationTargetY(m_unit) + m_unit->getState()->getStep()) < BOARDSIZE)
//							                && ((getLocationTargetY(m_unit) + m_unit->getState()->getStep())
//							                    < getLocationTargetY(m_available_targets.find(nearestEnemyKey)->second))) ) {
//								/**************************************************************************************/
//
//								diffX = getLocationTargetX(m_available_targets.find(nearestEnemyKey)->second) -
//								        it->second.first;
//								diffY = getLocationTargetY(m_available_targets.find(nearestEnemyKey)->second) -
//								        it->second.second;
//
//								if ( diffX < 0 ) {
//									diffX *= -1;
//								}
//								if ( diffY < 0 ) {
//									diffY *= -1;
//								}
//
//								if ( (getLocationTargetX(m_available_targets.find(nearestEnemyKey)->second)
//								- m_free_points_to_move.find(tmpRemember)->second.first) > diffX
//								&& (getLocationTargetY(m_available_targets.find(nearestEnemyKey)->second)
//								- m_free_points_to_move.find(tmpRemember)->second.second) < diffY ) {
////									std::cout << "3 x - 1, && >= xEenemy && y + 1 < y(enemy)\n"
//									std::cout << "test3    " << tmpRemember << " "
//									          << m_free_points_to_move.find(tmpRemember)->second.first << " > "
//									          << diffX << " && "
//									          << m_free_points_to_move.find(tmpRemember)->second.second << " < "
//									          << diffY << std::endl<< std::endl;
//									tmpRemember = it->first;
//								}
//							} else if ( (((getLocationTargetX(m_unit) + m_unit->getState()->getStep()) < BOARDSIZE )
//							             && ((getLocationTargetX(m_unit) + m_unit->getState()->getStep())
//							                 < getLocationTargetX(m_available_targets.find(nearestEnemyKey)->second)))
//							            /**(Rog(Y) + Rog(step) < BOARD(8)) && (Rog(Y) + Rog(step) < Mag(Y) )**/
//							            && (((getLocationTargetY(m_unit) - m_unit->getState()->getStep()) > 0)
//							                && ((getLocationTargetY(m_unit) - m_unit->getState()->getStep())
//							                    > getLocationTargetY(m_available_targets.find(nearestEnemyKey)->second))) ) {
//								/**************************************************************************************/
//
//								diffX = getLocationTargetX(m_available_targets.find(nearestEnemyKey)->second) -
//								        it->second.first;
//								diffY = it->second.second - getLocationTargetY(m_available_targets.find(nearestEnemyKey)->second);/***********/
//
//								if ( diffX < 0 ) {
//									diffX *= -1;
//								}
//								if ( diffY < 0 ) {
//									diffY *= -1;
//								}
//
//								if ( (getLocationTargetX(m_available_targets.find(nearestEnemyKey)->second)
//								- m_free_points_to_move.find(tmpRemember)->second.first) < diffX
//								    && (m_free_points_to_move.find(tmpRemember)->second.second
//								    - - getLocationTargetY(m_available_targets.find(nearestEnemyKey)->second)) > diffY ) {
////									std::cout << "4 x + 1, && <= xEenemy && y - 1 > y(enemy)\n"
//									std::cout << "test4    " << tmpRemember << " "
//									          << m_free_points_to_move.find(tmpRemember)->second.first << " < "
//									          << diffX << " && "
//									          << m_free_points_to_move.find(tmpRemember)->second.second << " > "
//									          << diffY << std::endl<< std::endl;
//									tmpRemember = it->first;
//								}
//							}
//						} else {
//							std::cout << "it: " << it->first <<std::endl;
//
//						}
//					}
////					nearestEnemyKey = tmpRemember;
//					std::cout << "nearest point: " << tmpRemember << " - "
//					          << m_free_points_to_move.find(tmpRemember)->second.first << "."
//					          <<  m_free_points_to_move.find(tmpRemember)->second.second << std::endl;
//					_move->setXY(m_free_points_to_move.find(tmpRemember)->second.first
//						, m_free_points_to_move.find(tmpRemember)->second.second);
//					_move->execute();
//					/**if ( quant > 0 ) {
//						key = rand() % quant + 1;
//
//						_move->setXY(m_free_points_to_move.find(key)->second.first,
//									 m_free_points_to_move.find(key)->second.second);
//						_move->execute();
//					**/
//				} else {
//					std::cout << "You can't _move, all points is busy arround." << std::endl;
//				}
				std::cout << "auto move(NOT WORKING)" << std::endl;
				_move->execute();
			} else if ( key == 99 ) {
				_move->execute();
			} else {
				_move->setXY(m_free_points_to_move.find(key)->second.first,
				             m_free_points_to_move.find(key)->second.second);
				_move->execute();
			}
		}
	} else if (ActionMeleeAttack *_attack =
		dynamic_cast<ActionMeleeAttack *>(m_actions.find(answer)->second)) {

		if ( Soldier* soldier = dynamic_cast<Soldier*>(m_unit)) {
			m_unit = soldier;

			if ( !checkWeaponMeleeRange(m_unit->getWeapon()) ) {
				std::cout << soldier->getState()->getName() << " take up a sword." << std::endl;
				m_unit->setWeapon(m_inventory.find("viking sword")->second.first);
				m_unit->setAttack(m_inventory.find("viking sword")->second.second);
			}


		} else if ( Rogue* rogue = dynamic_cast<Rogue*>(m_unit)) {
			m_unit = rogue;

			if ( !checkWeaponMeleeRange(m_unit->getWeapon()) ) {
				std::cout << rogue->getState()->getName() << " take up a dagger." << std::endl;
				m_unit->setWeapon(m_inventory.find("dagger")->second.first);
				m_unit->setAttack(m_inventory.find("dagger")->second.second);
			}
		}

		scanEnemies(m_unit);
		std::cout << m_unit->getState()->getName() << " "
		<< m_unit->getWeapon()->getTitle() << std::endl;
		if (m_available_targets.empty()) {
			std::cout << "No one to attack." << std::endl;

		} else {
			_attack->setAttacker(m_unit);

			question = "      Select target: \n";
			key = askSomeQuestion1(question, &target_check);

			if ( key == 0 ) {
				int quant = 0;

				for ( std::multimap<int, AbstractUnit *>::const_iterator it = m_available_targets.begin();
				      it != m_available_targets.end(); it++, quant++ );
				quant -= 1; // self point minus.
				key = rand() % quant + 1;

//			std::cout << "rand key " << key << " : (" << m_free_points_to_move.find(key)->second.first
//			<< "." << m_free_points_to_move.find(key)->second.second << ")" << std::endl;
				_attack->setAttacked(m_available_targets.find(key)->second);
				_attack->execute();
//			_move->execute();
//			printBattleField();
			} else if ( key == 99 ) {
//				std::cout << "Skip. " << std::endl;
				_attack->execute();
			} else {
				_attack->setAttacked(m_available_targets.find(key)->second);
				_attack->execute();
			}
		}
	} else if (ActionMageCast *_cast =
		dynamic_cast<ActionMageCast *>(m_actions.find(answer)->second)) {
		if ( AbstractPhysician* physician = dynamic_cast<AbstractPhysician*>(m_unit) ) {

			_cast->setSpellCaster(physician);
			
			question = "      Select spell: \n";
			
			////////////////////////////////////////////////////////////////////////////////////
			
			for ( const std::pair<Spell, AbstractSpell *> &spellPair : physician->_getHealerSpellBook()) {
				if ( (int) spellPair.first == 1 ) {
					std::cout <<  (int) spellPair.first << ". "
					          << spellPair.second->getSpellName()  << ". Cure (+"
					          << spellPair.second->getPoints() << ") at a distance : "
					          << spellPair.second->getRange() << ". Mana cost: "
					          << spellPair.second->getCost()
					          << std::endl;
				} else {
					std::cout <<  (int) spellPair.first << ". "
					          << spellPair.second->getSpellName()  << ". Hit (-"
					          << spellPair.second->getPoints() << ") at a distance : "
					          << spellPair.second->getRange() << ". Mana cost: "
					          << spellPair.second->getCost()
					          << std::endl;
				}
				m_available_spells.insert(std::make_pair((int) spellPair.first, spellPair.second));
			}
			
			////////////////////////////////////////////////////////////////////////////////////
			key = askSomeQuestion1(question, &spell_check);
			
			
			for ( const std::pair<Spell, AbstractSpell *> &spellPair : physician->_getHealerSpellBook()) {
				if (key == (int) spellPair.first) {
					
					_cast->setSpell(spellPair.first);
					
					if ((int) spellPair.first == 1) { // enum count Spell HEAL
						m_available_targets.clear();
						scanAvailableDistanceToAllUnits(physician, spellPair.second->getRange());
					} else {
						m_available_targets.clear();
						scanAvailableDistanceEnemies(physician, spellPair.second->getRange());
					}
					
					std::cout << spellPair.second->getSpellName() << " selected.\n\n" << std::endl;
				}
			}
			
			question = "      Select target: \n";
			
			for ( std::multimap<int, AbstractUnit *>::const_iterator it = m_available_targets.begin();
			      it != m_available_targets.end(); it++ ) {
				
				if (!((getLocationTargetX(it->second) == getLocationTargetX(physician))
				      && (getLocationTargetY(it->second) == getLocationTargetY(physician))
				      && _cast->getSpellType() != 1 ) && it->first > 0 && it->first != 99 ) { // battle spell selected
					
					if ( AbstractCaster * _caster = dynamic_cast<AbstractCaster*>(it->second) ) {
						std::cout << it->first << ". " << _caster->getState()->getName()
						          << ", HP:[" << _caster->getState()->getHp() << "/" << _caster->getState()->getHpLimit()
						          << "], MP:[" << _caster->getMageState()->getMana() << "/" << _caster->getMageState()->getManaLimit()
						          << "], with a " << _caster->getWeapon()->getTitle()
						          << ". (" << getLocationTargetX(_caster) << "." << getLocationTargetY
						          (_caster)
						          << "), team:"
						          << BattleField::getInstance()->getTeam()->showPlayerTeam(_caster) << std::endl;
					} else {
						std::cout << it->first << ". " << it->second->getState()->getName()
						          << ", [" << it->second->getState()->getHp() << "/" << it->second->getState()->getHpLimit()
								  << "], with a " << it->second->getWeapon()->getTitle()
								  << ". (" << getLocationTargetX(it->second) << "." << getLocationTargetY(it->second)
						          << "), team:"
						          << BattleField::getInstance()->getTeam()->showPlayerTeam(it->second) << std::endl;
					}
				} else if (!((getLocationTargetX(it->second) == getLocationTargetX(physician))
				             && (getLocationTargetY(it->second) == getLocationTargetY(physician))
				             && _cast->getSpellType() == 1 ) && it->first > 0 && it->first != 99 ) { // heal spell selected
					
					if ( AbstractCaster * _caster = dynamic_cast<AbstractCaster*>(it->second) ) {
						std::cout << it->first << ". " << _caster->getState()->getName()
						          << ", HP:[" << _caster->getState()->getHp() << "/" << _caster->getState()->getHpLimit()
						          << "], MP:[" << _caster->getMageState()->getMana() << "/" << _caster->getMageState()->getManaLimit()
						          << "], with a " << _caster->getWeapon()->getTitle()
						          << ". (" << getLocationTargetX(_caster) << "." << getLocationTargetY
							          (_caster)
						          << "), team:"
						          << BattleField::getInstance()->getTeam()->showPlayerTeam(_caster) << std::endl;
					} else {
						std::cout << it->first << ". " << it->second->getState()->getName()
						          << ", [" << it->second->getState()->getHp() << "/" << it->second->getState()->getHpLimit()
						          << "], with a " << it->second->getWeapon()->getTitle()
						          << ". (" << getLocationTargetX(it->second) << "." << getLocationTargetY(it->second)
						          << "), team:"
						          << BattleField::getInstance()->getTeam()->showPlayerTeam(it->second) << std::endl;
					}
				}
			}
			if ( m_available_targets.count(2) ) {
				std::cout << "0. Random target." << std::endl;
			}
			std::cout << "99. Skip." << std::endl;
			
			key = askSomeQuestion1(question, &target_check);
			
			if ( m_available_targets.count(2) ) {
				if ( key == 0 ) {
					int quant = 0;
					
					for ( std::multimap<int, AbstractUnit *>::const_iterator it = m_available_targets.begin();
					      it != m_available_targets.end(); it++, quant++ );
					quant -= 3; // self point && rand key 99 minus && last quant++ in for(;;)
					
					key = rand() % quant + 1;
					
					_cast->setTarget(m_available_targets.find(key)->second);
					_cast->execute();
					
				} else if ( key == 99 ) {
//			std::cout << "Skip. " << std::endl;
					_cast->execute();
				} else {
					_cast->setTarget(m_available_targets.find(key)->second);
					_cast->execute();
				}
			} else if ( (m_available_targets.count(1)) && !(m_available_targets.count(2)) ) {
				//if only zero target
				_cast->setTarget(m_available_targets.find(key)->second);
				_cast->execute();
				
			} else {
				//	false
				_cast->execute();
			}
			
			/*********************************************************/
		} else {
			
			AbstractCaster *caster = static_cast<AbstractCaster *>(m_unit);
//
			_cast->setSpellCaster(caster);
			
			question = "      Select spell: \n";
			
			////////////////////////////////////////////////////////////////////////////////////
			
			for ( const std::pair<Spell, AbstractSpell *> &spellPair : caster->getSpellBook()) {
				if ( (int) spellPair.first == 1 ) {
					std::cout <<  (int) spellPair.first << ". "
					          << spellPair.second->getSpellName()  << ". Cure (+"
					          << spellPair.second->getPoints() << ") at a distance : "
					          << spellPair.second->getRange() << ". Mana cost: "
					          << spellPair.second->getCost()
					          << std::endl;
				} else {
					std::cout <<  (int) spellPair.first << ". "
					          << spellPair.second->getSpellName()  << ". Hit (-"
					          << spellPair.second->getPoints() << ") at a distance : "
					          << spellPair.second->getRange() << ". Mana cost: "
					          << spellPair.second->getCost()
					          << std::endl;
				}
				m_available_spells.insert(std::make_pair((int) spellPair.first, spellPair.second));
			}
			
			////////////////////////////////////////////////////////////////////////////////////
			key = askSomeQuestion1(question, &spell_check);
			
			
			for ( const std::pair<Spell, AbstractSpell *> &spellPair : caster->getSpellBook()) {
				if (key == (int) spellPair.first) {
					
					_cast->setSpell(spellPair.first);
					
					if ((int) spellPair.first == 1) { // enum count Spell HEAL
						m_available_targets.clear();
						scanAvailableDistanceToAllUnits(caster, spellPair.second->getRange());
					} else {
						m_available_targets.clear();
						scanAvailableDistanceEnemies(caster, spellPair.second->getRange());
					}
					
					std::cout << spellPair.second->getSpellName() << " selected.\n\n" << std::endl;
				}
			}
			
			question = "      Select target: \n";
			
			for ( std::multimap<int, AbstractUnit *>::const_iterator it = m_available_targets.begin();
			      it != m_available_targets.end(); it++ ) {
				
				if (!((getLocationTargetX(it->second) == getLocationTargetX(caster))
				      && (getLocationTargetY(it->second) == getLocationTargetY(caster))
				      && _cast->getSpellType() != 1 ) && it->first > 0 && it->first != 99 ) { // battle spell selected
					
					if ( AbstractCaster * _caster = dynamic_cast<AbstractCaster*>(it->second) ) {
						
						
						std::cout << it->first << ". " << _caster->getState()->getName()
						          << ", HP:[" << _caster->getState()->getHp() << "/" << _caster->getState()->getHpLimit()
						          << "], MP:[" << _caster->getMageState()->getMana() << "/" << _caster->getMageState()->getManaLimit()
						          << "], with a " << _caster->getWeapon()->getTitle()
						          << ". (" << getLocationTargetX(_caster) << "." << getLocationTargetY
							          (_caster)
						          << "), team:"
						          << BattleField::getInstance()->getTeam()->showPlayerTeam(_caster) << std::endl;
					} else {
						std::cout << it->first << ". " << it->second->getState()->getName()
						          << ", [" << it->second->getState()->getHp() << "/" << it->second->getState()->getHpLimit()
						          << "], with a " << it->second->getWeapon()->getTitle()
						          << ". (" << getLocationTargetX(it->second) << "." << getLocationTargetY(it->second)
						          << "), team:"
						          << BattleField::getInstance()->getTeam()->showPlayerTeam(it->second) << std::endl;
					}
				} else if (!((getLocationTargetX(it->second) == getLocationTargetX(caster))
				             && (getLocationTargetY(it->second) == getLocationTargetY(caster))
				             && _cast->getSpellType() == 1 ) && it->first > 0 && it->first != 99 ) { // heal spell selected
					
					if ( AbstractCaster * _caster = dynamic_cast<AbstractCaster*>(it->second) ) {
						std::cout << it->first << ". " << _caster->getState()->getName()
						          << ", HP:[" << _caster->getState()->getHp() << "/" << _caster->getState()->getHpLimit()
						          << "], MP:[" << _caster->getMageState()->getMana() << "/" << _caster->getMageState()->getManaLimit()
						          << "], with a " << _caster->getWeapon()->getTitle()
						          << ". (" << getLocationTargetX(_caster) << "." << getLocationTargetY
							          (_caster)
						          << "), team:"
						          << BattleField::getInstance()->getTeam()->showPlayerTeam(_caster) << std::endl;
					} else {
						std::cout << it->first << ". " << it->second->getState()->getName()
						          << ", [" << it->second->getState()->getHp() << "/" << it->second->getState()->getHpLimit()
						          << "], with a " << it->second->getWeapon()->getTitle()
						          << ". (" << getLocationTargetX(it->second) << "." << getLocationTargetY(it->second)
						          << "), team:"
						          << BattleField::getInstance()->getTeam()->showPlayerTeam(it->second) << std::endl;
					}
				}
			}
			if ( m_available_targets.count(2) ) {
				std::cout << "0. Random target." << std::endl;
			}
			std::cout << "99. Skip." << std::endl;
			
			key = askSomeQuestion1(question, &target_check);
			
			if ( m_available_targets.count(2) ) {
				if ( key == 0 ) {
					int quant = 0;
					
					for ( std::multimap<int, AbstractUnit *>::const_iterator it = m_available_targets.begin();
					      it != m_available_targets.end(); it++, quant++ );
					quant -= 3; // self point && rand key 99 minus && last quant++ in for(;;)
					
					key = rand() % quant + 1;
					
					_cast->setTarget(m_available_targets.find(key)->second);
					_cast->execute();
					
				} else if ( key == 99 ) {
//			std::cout << "Skip. " << std::endl;
					_cast->execute();
				} else {
					_cast->setTarget(m_available_targets.find(key)->second);
					_cast->execute();
				}
			} else if ( (m_available_targets.count(1)) && !(m_available_targets.count(2)) ) {
				//if only zero target
				_cast->setTarget(m_available_targets.find(key)->second);
				_cast->execute();
				
			} else {
				//	false
				_cast->execute();
			}
		}
		
	} else if (ActionMageMeditation *_meditation = dynamic_cast<ActionMageMeditation *>(m_actions.find(answer)
		->second)) {
		AbstractCaster *caster = static_cast<AbstractCaster *>(m_unit);
//
		_meditation->setSpellCaster(caster);
		if ( caster->getMageState()->getMana() < caster->getMageState()->getManaLimit() ) {
			_meditation->execute();
		} else {
			std::cout << "Your mana is full." << std::endl;
			_meditation->execute();
		}

	} else if (ActionRangeAttack *_rangeAttack = dynamic_cast<ActionRangeAttack *>(m_actions.find(answer)->second)) {

		_rangeAttack->setArcher(m_unit);
	if ( !dynamic_cast<Beast*>(m_unit->getAttribute()) ) {
		
		if ( Soldier* soldier = dynamic_cast<Soldier*>(m_unit)) {
			if ( checkWeaponMeleeRange(soldier->getWeapon()) ) {
				
				std::cout << soldier->getState()->getName() << " take up a " << m_inventory.find("crossbow")
					->second.first->getTitle() << std::endl;
				soldier->setWeapon(m_inventory.find("crossbow")->second.first);
				soldier->setAttack(m_inventory.find("crossbow")->second.second);
			}
			m_unit = soldier;
			_rangeAttack->reloadWeapon();
			
		} else if ( Rogue* rogue = dynamic_cast<Rogue*>(m_unit)) {
			
			
			if ( checkWeaponMeleeRange(rogue->getWeapon()) ) {
				
				std::cout << rogue->getState()->getName() << " take up a " << m_inventory.find("bow")
					->second.first->getTitle() << std::endl;
				rogue->setWeapon(m_inventory.find("bow")->second.first);
				rogue->setAttack(m_inventory.find("bow")->second.second);
			}
			m_unit = rogue;
			_rangeAttack->reloadWeapon();
			
		}
		
		m_available_targets.clear();
		scanAvailableDistanceEnemies(m_unit, m_unit->getWeapon()->getRange());
		
		if ( !m_available_targets.count(1) ) {
			std::cout << "No one to attack." << std::endl;
			
			markerOnBoard(m_unit);
			
		} else {
			
			question = "      Select target: \n";
			
			for ( std::multimap<int, AbstractUnit *>::const_iterator it = m_available_targets.begin();
			      it != m_available_targets.end(); it++ ) {
				
				if (!((getLocationTargetX(it->second) == getLocationTargetX(m_unit))
				      && (getLocationTargetY(it->second) == getLocationTargetY(m_unit)))) { //
					
					if (AbstractCaster *_caster = dynamic_cast<AbstractCaster *>(it->second)) {
						std::cout << it->first << ". " << _caster->getState()->getName()
						          << ", HP:[" << _caster->getState()->getHp() << "/" << _caster->getState()->getHpLimit()
						          << "], MP:[" << _caster->getMageState()->getMana() << "/" << _caster->getMageState()->getManaLimit()
						          << "], with a " << _caster->getWeapon()->getTitle()
						          << ". (" << getLocationTargetX(_caster) << "." << getLocationTargetY
							          (_caster)
						          << "), team:"
						          << BattleField::getInstance()->getTeam()->showPlayerTeam(_caster) << std::endl;
					} else {
						std::cout << it->first << ". " << it->second->getState()->getName()
						          << ", [" << it->second->getState()->getHp() << "/" << it->second->getState()->getHpLimit()
						          << "], with a " << it->second->getWeapon()->getTitle()
						          << ". (" << getLocationTargetX(it->second) << "." << getLocationTargetY(it->second)
						          << "), team:"
						          << BattleField::getInstance()->getTeam()->showPlayerTeam(it->second) << std::endl;
					}
				}
			}
			if (m_available_targets.count(2)) {
				std::cout << "0. Random target." << std::endl;
			}
			std::cout << "99. Skip." << std::endl;
			
			key = askSomeQuestion1(question, &target_check);
			
			if (m_available_targets.count(2)) {
				if (key == 0) {
					int quant = 0;
					
					for ( std::multimap<int, AbstractUnit *>::const_iterator it = m_available_targets.begin();
					      it != m_available_targets.end(); it++, quant++ );
					quant -= 3; // self point && rand key 99 minus && last quant++ in for(;;)
					
					key = rand() % quant + 1;
					
					_rangeAttack->setTarget(m_available_targets.find(key)->second);
					_rangeAttack->execute();
					
				} else if (key == 99) {
//			std::cout << "Skip. " << std::endl;
					_rangeAttack->execute();
				} else {
					_rangeAttack->setTarget(m_available_targets.find(key)->second);
					_rangeAttack->execute();
				}
			} else if ((m_available_targets.count(1)) && !(m_available_targets.count(2))) {
				//if only zero target
				_rangeAttack->setTarget(m_available_targets.find(key)->second);
				_rangeAttack->execute();
				
			} else {
				//	false
				_rangeAttack->execute();
			}
		}
	}

	} else if (ActionUseMount *_useMount = dynamic_cast<ActionUseMount *>(m_actions.find(answer)->second)) {
		if ( !dynamic_cast<Beast*>(m_unit->getAttribute()) ) {
			_useMount->setRider(m_unit);
			_useMount->execute();
		}
	} else if (ActionSummonDaemon *_summon = dynamic_cast<ActionSummonDaemon *>(m_actions.find(answer)->second)) {
		Warlock* warlock = static_cast<Warlock*>(m_unit);

		_summon->setWarlock(warlock);
		_summon->execute();
		
	} else if (ActionTransformation *_transformation = dynamic_cast<ActionTransformation *>(m_actions.find(answer)->second)) {
		_transformation->setUnit(m_unit);
		_transformation->execute();
	}
}