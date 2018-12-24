/*_Created_by_K1ngp1n_*/

#pragma once

#include "Action.hpp"
#include "../Interfaces/AbstractUnit.hpp"
#include "../Interfaces/BattleField.hpp"

class BattleField;

class ActionMeleeAttack : public Action {
	AbstractUnit* m_attacker;
	AbstractUnit* m_attacked;
public:
    ActionMeleeAttack(AbstractUnit* attacker = nullptr
    	, AbstractUnit* attacked = nullptr)
        : Action(EActionType::MeleeAttack)
        , m_attacker(attacker)
		, m_attacked(attacked)
	{}

    ~ActionMeleeAttack() {
	}
	virtual void setAttacker(AbstractUnit* unit) {
		m_attacker = unit;
	}
	virtual void setAttacked(AbstractUnit* unit) {
		m_attacked = unit;
	}

	virtual bool execute() override {
		if (m_attacker && m_attacked && m_attacker != m_attacked) {
			BattleField::getInstance()->markerOnBoard(m_attacker);
			m_attacker->attack(m_attacked);

			return true;
		}
		std::cout << "Skip." << std::endl;
		BattleField::getInstance()->markerOnBoard(m_attacker);

		return false;
	}
};
