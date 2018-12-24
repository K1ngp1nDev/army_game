/*_Created_by_K1ngp1n_*/

#include "Observer.hpp"
#include "AbstractUnit.hpp"
#include "AbstractState.hpp"
#include "Undead.hpp"
#include "BattleField.hpp"

Observer::Observer() {
}

Observer::~Observer() {
}

Observer* Observer::instance = nullptr;

Observer *Observer::getInstance() {
	if ( instance == nullptr ) {
		instance = new Observer();
	}
	return instance;
}

void Observer::add(AbstractUnit *observer, AbstractUnit *observable) {
	m_list_of_victims[observer].insert(observable);
}

void Observer::informObserver(AbstractUnit* unit) {
	std::cout << "FLAG Observer.cpp" << std::endl;
	std::map<AbstractUnit*, std::set<AbstractUnit*>>::const_iterator it = m_list_of_victims.begin();
	
	if ( !m_list_of_victims.empty() ) {
		
		if ( it->second.count(unit) ) {
			int hitsUp = unit->getState()->getHpLimit() / 10;
			
			for ( ; it != m_list_of_victims.end(); it++ ) {
				if ( !dynamic_cast<Undead*>(unit->getAttribute()) ) {
					
					if ( (it->first->getState()->getHp() + hitsUp) > it->first->getState()->getHpLimit() ) {
						
						std::cout << unit->getState()->getName()
						<< " is dead, and gave his portion hits to "
						<< it->first->getState()->getName()
						<< " (" << BattleField::getInstance()->getLocationTargetX(it->first) << "."
						<< BattleField::getInstance()->getLocationTargetY(it->first)
						<< ") " << it->first->getState()->getHp()
						<< " + " << hitsUp << std::endl;
						
						it->first->getState()->setHp(it->first->getState()->getHpLimit() );
					} else {
						std::cout <<  unit->getState()->getName()
						          << " is dead, and gave his portion hits to " <<
						          it->first->getState()->getName() << " "
						          << it->first->getState()->getHp() << " + " << hitsUp  <<
						          std::endl;
						it->first->getState()->setHp(it->first->getState()->getHp() + hitsUp);
					}
				}
				m_list_of_victims.find(it->first)->second.erase(unit);
			}
		}
	}
}

void Observer::informObservable(AbstractUnit *unit) {
	std::map<AbstractUnit *, std::set<AbstractUnit *>>::const_iterator it = m_list_of_victims.begin();
	
	if ( !m_list_of_victims.empty() ) {
		
		if ( it->first == unit ) {
			
			for ( ; it != m_list_of_victims.end(); it++ ) {
				
				m_list_of_victims.find(it->first)->second.clear();//clear set(value)
				
			}
			std::cout << unit->getState()->getName() << " was removed from keys." << std::endl;
			m_list_of_victims.erase(it->first);//clear key
		}
	}
	
}

bool Observer::checkSoul(AbstractUnit* victim) const {
	for( std::map<AbstractUnit *, std::set<AbstractUnit *>>::const_iterator it = m_list_of_victims.begin();
	     it != m_list_of_victims.end(); it++) {

		if ( it->second.count(victim) ) {
			//victim already in list of souls
			return false;
		}

	}
	return true;
}
