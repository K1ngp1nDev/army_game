/*_Created_by_K1ngp1n_*/

#pragma once

#include <iostream>
#include "Action.hpp"
#include "../Interfaces/BattleField.hpp"

class AbstractUnit;
class BattleField;

class ActionUnitMove : public Action {
    int m_xBound;
    int m_yBound;
	int m_X;
	int m_Y;
    AbstractUnit* m_unit;
public:
    ActionUnitMove(int xBound = 9, int yBound = 9)
        : Action(EActionType::Move)
        , m_xBound(xBound)
        , m_yBound(yBound)
        , m_X(0)
        , m_Y(0)
        , m_unit(nullptr)
	{}
	~ActionUnitMove() {
		std::cout << "destructor ActionUnitMove" << std::endl;
	}

    void setXY(int x, int y) {
        m_X = x;
        m_Y = y;
    }

    void setBounds(int x, int y) {
        m_xBound = x;
        m_yBound = y;
    }

    void setUnit(AbstractUnit* unit) {
        m_unit = unit;
    }

	virtual bool execute() override {
//		std::cout << "actionUnitMove.hpp // execute" << std::endl;
        if (m_unit && (m_X > 0 && m_X < m_xBound) && (m_Y > 0 && m_Y < m_yBound)) {
            BattleField::getInstance()->moveToSector(m_X,m_Y,m_unit);
//			BattleField::getInstance()->
			return true;
		}
		std::cout << "Skip." << std::endl;
		BattleField::getInstance()->markerOnBoard(m_unit);

		return false;
	}
};
