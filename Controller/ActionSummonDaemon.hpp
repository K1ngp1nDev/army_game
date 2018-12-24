/*_Created_by_K1ngp1n_*/

#pragma once

#include "Action.hpp"
#include "../Units/Warlock.hpp"
#include "../Units/Daemon.hpp"

class Daemon;
class Warlock;

class ActionSummonDaemon : public Action {
	Warlock* m_warlock;
	Daemon* m_daemon;
public:
	ActionSummonDaemon(Warlock* warlock = nullptr)
	: Action(EActionType::SummonDaemon)
	, m_warlock(warlock)
	, m_daemon(nullptr)
	{}
	
	~ActionSummonDaemon() {}
	
	void setWarlock(Warlock* warlock) {
		m_warlock = warlock;
	}
	
	virtual bool execute() override {
		if ( m_warlock ) {
			m_warlock->summonDaemon();
			BattleField::getInstance()->markerOnBoard(m_warlock);
			return true;
		}
		std::cout << "Skip." << std::endl;
		BattleField::getInstance()->markerOnBoard(m_warlock);
		
		return false;
	}
	
	
	
	
};