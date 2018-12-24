/*_Created_by_K1ngp1n_*/

#pragma once

#include "Action.hpp"
#include "../Interfaces/AbstractUnit.hpp"
#include "../Interfaces/AbstractWeapon.hpp"
#include "../Interfaces/AbstractState.hpp"
#include "../Interfaces/BattleField.hpp"

class ActionRangeAttack : public Action {
	AbstractUnit* m_archer;
	AbstractUnit* m_target;
	int caseForArrow;
public:
	ActionRangeAttack(AbstractUnit* archer = nullptr, AbstractUnit* target = nullptr)
	: Action(EActionType::RangeAttack)
	, m_archer(archer)
	, m_target(target)
	, caseForArrow(0)
	{}
	~ActionRangeAttack() {}

	void setArcher(AbstractUnit* archer) {
		m_archer = archer;
	}

	void setTarget(AbstractUnit* target) {
		m_target = target;
	}

	void reloadWeapon() {
		caseForArrow = 1;
	}

	virtual bool execute() override {
		if ( m_archer && m_target && caseForArrow > 0 ) {
//			std::cout << "target hp: " << m_target->getState()->getHp() << std::endl;

//			m_target->takePhysicalDamage(m_archer->getWeapon()->getDamage());
//			std::cout << "bolt hit enemy (-" << m_archer->getWeapon()->getDamage() << ")" << std::endl;
//			std::cout << "target hp: " << m_target->getState()->getHp() << std::endl;
			m_archer->attack(m_target);
			caseForArrow = 0;
			BattleField::getInstance()->markerOnBoard(m_archer);
			return true;
		}
		BattleField::getInstance()->markerOnBoard(m_archer);

		return false;
	}
};