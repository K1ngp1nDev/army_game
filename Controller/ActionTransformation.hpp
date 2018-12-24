/*_Created_by_K1ngp1n_*/

#pragma once

#include "Action.hpp"
#include "../Interfaces/AbstractUnit.hpp"
#include "../Interfaces/BattleField.hpp"

class ActionTransformation : public Action {
	AbstractUnit* m_unit;
	public:
	ActionTransformation(AbstractUnit* unit = nullptr)
	: Action(EActionType::Transformation)
	, m_unit(unit)
	{}
	
	~ActionTransformation() {}
	
	void setUnit(AbstractUnit* unit) {
		m_unit = unit;
	}
	
	virtual bool execute() override {
		if ( m_unit ) {
			m_unit->clickSpecialAbility();
			BattleField::getInstance()->markerOnBoard(m_unit);
			return true;
		}
		BattleField::getInstance()->markerOnBoard(m_unit);
		std::cout << "Skip." << std::endl;
		return false;
	}
	
};
