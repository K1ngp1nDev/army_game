/*_Created_by_K1ngp1n_*/

#pragma once

#include "Action.hpp"
#include "../Interfaces/AbstractUnit.hpp"
#include "../Interfaces/AbstractState.hpp"
#include "../Interfaces/BattleField.hpp"
#include "../Abilities/Mount.hpp"

class BattleField;
class Mount;

class ActionUseMount : public Action {
	AbstractUnit* m_rider;
//	Mount* m_mount;
	public:
	ActionUseMount(AbstractUnit* rider = nullptr)
	: Action(EActionType::Ride)
	, m_rider(rider)
	{}

	~ActionUseMount() {}

	void setRider(AbstractUnit* rider) {
		m_rider = rider;
	}



	virtual bool execute() override {
		if ( m_rider && dynamic_cast<Mount*>(m_rider->getSpecialAbility()) ) {
				m_rider->clickSpecialAbility(); //soldier.cpp
				BattleField::getInstance()->markerOnBoard(m_rider);
				return true;
		}
		BattleField::getInstance()->markerOnBoard(m_rider);
		std::cout << "Skip." << std::endl;
		return false;
	}

};

