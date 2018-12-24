/*_Created_by_K1ngp1n_*/

#include <zconf.h>
#include "Team.hpp"
#include "../Interfaces/AbstractUnit.hpp"
#include "../Interfaces/AbstractCaster.hpp"
#include "../Interfaces/AbstractState.hpp"
#include "../Interfaces/AbstractWeapon.hpp"


Team::Team(){
	srand (time(NULL));
}

Team::~Team() {}

void Team::addUnitToTeam(select_team team, AbstractUnit *unit) {
	m_team_units.insert(std::make_pair(team,unit));
	if ( (int)team % 2 == 0 ) {
		BattleField::getInstance()->arrangeTeamB(unit);
	} else {
		BattleField::getInstance()->arrangeTeamA(unit);
	}
}

void Team::removeUnit(int team, AbstractUnit *unit) {
	if ((int) select_team::blue == team) {
		
		for ( std::multimap<select_team, AbstractUnit *>::iterator iterator = m_team_units.begin();
		      iterator != m_team_units.end(); iterator++ ) {
			if (iterator->second == unit) {
 				m_team_units.erase(iterator);
				return;
				
			}
		}
	} else {
		
		for ( std::multimap<select_team, AbstractUnit *>::iterator iterator = m_team_units.begin();
		      iterator != m_team_units.end(); iterator++ ) {
			if (iterator->second == unit) {
				m_team_units.erase(iterator);
				return;
			}
		}
	}
}

void Team::showUnitsOnField(int team) {
	int count = 0;
	switch (team) {
		case 0 : {

			for ( std::multimap<select_team, AbstractUnit *>::const_iterator it = m_team_units.begin();
			      it != m_team_units.end(); it++ ) {
				count++;

				if (AbstractCaster *_caster = dynamic_cast<AbstractCaster *>(it->second)) {
					
					std::cout << count << "). " << _caster->getState()->getName()
					          << ", HP:[" << _caster->getState()->getHp() << "/"
					          << _caster->getState()->getHpLimit() << "], MP:["
					          << _caster->getMageState()->getMana() << "/"
					          << _caster->getMageState()->getManaLimit() << "], with *"
					          << _caster->getWeapon()->getTitle() << "* ("
					          << BattleField::getInstance()->getLocationTargetX(_caster) << "."
					          << BattleField::getInstance()->getLocationTargetY(_caster) << "), team: "
					          << (int) it->first << std::endl;
					
					BattleField::getInstance()->addUnitToListOfSelect(count, it->second);
				} else {
					
					std::cout << count << "). " << it->second->getState()->getName()
					          << ", HP:[" << it->second->getState()->getHp() << "/"
					          << it->second->getState()->getHpLimit() << "], with *"
					          << it->second->getWeapon()->getTitle() << "* ("
					          << BattleField::getInstance()->getLocationTargetX(it->second) << "."
					          << BattleField::getInstance()->getLocationTargetY(it->second) << "), team: "
					          << (int) it->first << std::endl;

					BattleField::getInstance()->addUnitToListOfSelect(count, it->second);
				}
			}
		}
			break;

		case 1 : {

			for (std::multimap<select_team, AbstractUnit *>::const_iterator it = m_team_units.begin();
			      it != m_team_units.end(); it++) {
				if ( team == (int) it->first ) {
					count++;
					if ( AbstractCaster* _caster = dynamic_cast<AbstractCaster*>(it->second) ) {
						
						std::cout << count << "). " << _caster->getState()->getName()
						          << ", HP:[" << _caster->getState()->getHp() << "/"
						          << _caster->getState()->getHpLimit() << "], MP:["
						          << _caster->getMageState()->getMana() << "/"
						          << _caster->getMageState()->getManaLimit() << "], with *"
						          << _caster->getWeapon()->getTitle() << "* ("
						          << BattleField::getInstance()->getLocationTargetX(_caster) << "."
						          << BattleField::getInstance()->getLocationTargetY(_caster) << "), team: "
						          << (int) it->first << std::endl;
						
						BattleField::getInstance()->addUnitToListOfSelect(count, it->second);
					} else {
						
						std::cout << count << "). " << it->second->getState()->getName()
						          << ", HP:[" << it->second->getState()->getHp() << "/"
						          << it->second->getState()->getHpLimit() << "], with *"
						          << it->second->getWeapon()->getTitle() << "* ("
						          << BattleField::getInstance()->getLocationTargetX(it->second) << "."
						          << BattleField::getInstance()->getLocationTargetY(it->second) << "), team: "
						          << (int) it->first << std::endl;

						BattleField::getInstance()->addUnitToListOfSelect(count,it->second);
					}
				}
			}
		}
			break;
		case 2 : {
			for ( std::multimap<select_team, AbstractUnit *>::const_iterator it = m_team_units.begin();
			      it != m_team_units.end(); it++ ) {
				if ( team == (int) it->first ) {
					count++;
					if ( AbstractCaster* _caster = dynamic_cast<AbstractCaster*>(it->second) ) {
						
						std::cout << count << "). " << _caster->getState()->getName()
						          << ", HP:[" << _caster->getState()->getHp() << "/"
						          << _caster->getState()->getHpLimit() << "], MP:["
						          << _caster->getMageState()->getMana() << "/"
						          << _caster->getMageState()->getManaLimit() << "], with *"
						          << _caster->getWeapon()->getTitle() << "* ("
						          << BattleField::getInstance()->getLocationTargetX(_caster) << "."
						          << BattleField::getInstance()->getLocationTargetY(_caster) << "), team: "
						          << (int) it->first << std::endl;
						
						BattleField::getInstance()->addUnitToListOfSelect(count, it->second);
					} else {
						
						std::cout << count << "). " << it->second->getState()->getName()
						          << ", HP:[" << it->second->getState()->getHp() << "/"
						          << it->second->getState()->getHpLimit() << "], with *"
						          << it->second->getWeapon()->getTitle() << "* ("
						          << BattleField::getInstance()->getLocationTargetX(it->second) << "."
						          << BattleField::getInstance()->getLocationTargetY(it->second) << "), team: "
						          << (int) it->first << std::endl;

						BattleField::getInstance()->addUnitToListOfSelect(count,it->second);
					}
				}
			}
		}
			break;
		default: {
			std::cout << "Team not found. Try again." << std::endl;
			int key;

			std::cin>>key;
			BattleField::getInstance()->getTeam()->showUnitsOnField(key);
		}
	}
}

int Team::showPlayerTeam(AbstractUnit *unit) const {
int returnTeam;

	for( std::multimap<select_team, AbstractUnit*>::const_iterator it = m_team_units.begin();
	it != m_team_units.end(); it++) {
		if ( (it)->second == unit ) {
			returnTeam = (int)it->first;
			break;
		}
	}
	return returnTeam;
}

void Team::randomFillUnitsOnBoard() {
	int randQuntifyOfTeamMembers = (rand() % 30 + 1) * 2;
	std::cout << "Units in team now: " << randQuntifyOfTeamMembers / 2 << std::endl;

	for ( int i = 1; i <= randQuntifyOfTeamMembers; i++ ) {
		BattleField::getInstance()->randomFactory(i);
	}
}

bool Team::checkTeam() const { // check alive in teams
	for( std::multimap<select_team, AbstractUnit*>::const_iterator it = m_team_units.begin();
	     it != m_team_units.end(); it++) {
		if ( !m_team_units.count(select_team::blue) || !m_team_units.count(select_team::red) ) {
			return false;
		}
	}
	return true;
}




