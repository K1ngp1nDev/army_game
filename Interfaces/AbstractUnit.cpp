/*_Created_by_K1ngp1n_*/

#include "AbstractState.hpp"
#include "AbstractAttack.hpp"
#include "AbstractWeapon.hpp"
#include "AbstractSpell.hpp"
#include "AbstractUnit.hpp"
#include "SpecialAbility.hpp"
#include "Attribute.hpp"
#include "Observer.hpp"
#include <memory>
//#include "Mount.hpp"

AbstractUnit::AbstractUnit(AbstractState* state)
	: m_abstractState(state)
{

	this->m_attribute = nullptr;
	this->m_weapon = nullptr;
	this->m_attack = nullptr;
	this->m_special_ability = nullptr;
	
}

AbstractUnit::~AbstractUnit() {}

std::set<EActionType> AbstractUnit::availableActions() {
//    std::set<EActionType> actions{EActionType::MeleeAttack, EActionType::Move};
	    std::set<EActionType> actions;
	
//	actions.insert(EActionType::MeleeAttack);
//	actions.insert(EActionType::Move);

//    if (m_special_ability) {
//        for (EActionType actionType: m_special_ability->availableActions()) {
//            actions.insert(actionType);
//        }
//    }
    return actions;
}

void AbstractUnit::clickSpecialAbility() {
}

void AbstractUnit::attack(AbstractUnit *enemy) {
}

void AbstractUnit::counterAttack(AbstractUnit *enemy) {
}

	AbstractState *AbstractUnit::getState() const {
		return m_abstractState;
	}


	void AbstractUnit::setState(AbstractState *newState) {
		if ( m_abstractState != newState ) {
			delete m_abstractState;
			m_abstractState = newState;
		}
	}

	AbstractAttack *AbstractUnit::getAttack() const {
		return m_attack;
	}

	void AbstractUnit::setAttack(AbstractAttack *newAttack) {
		if ( m_attack != newAttack ) {
			m_attack = newAttack;
		}
	}

	AbstractWeapon *AbstractUnit::getWeapon() const {
		return m_weapon;
	}

	void AbstractUnit::setWeapon(AbstractWeapon *newWeapon) {
		if ( m_weapon != newWeapon ) {
			m_weapon = newWeapon;
		}
	}

	SpecialAbility *AbstractUnit::getSpecialAbility() const {
		return m_special_ability;
	}

	void AbstractUnit::setSpecialAbility(SpecialAbility *newAbility) {
		if ( m_special_ability != newAbility ) {
			m_special_ability = newAbility;
		}
	}

	Attribute *AbstractUnit::getAttribute() const {
		return m_attribute;
	}

	void AbstractUnit::setAttribute(Attribute *newAttribute) {
		if ( m_attribute != newAttribute ) {
			m_attribute = newAttribute;
		}
	}

void AbstractUnit::isAlive() {
	if (getState()->getHp() <= 0 ) {
		BattleField::getInstance()->clearPointAndDelUnit(this);
		std::cout << getState()->getName() << " is dead" << std::endl;
	}
}

void AbstractUnit::takePhysicalDamage(int damage) {
	if ( (m_abstractState->getHp() - damage) < 0 ) {
		damage = m_abstractState->getHp();
	}
	m_abstractState->setHp(m_abstractState->getHp() - damage);
}

void AbstractUnit::takeMagicDamage(int damage) {
	if ( (m_abstractState->getHp() - damage) < 0 ) {
		damage = m_abstractState->getHp();
	}
	m_abstractState->setHp(m_abstractState->getHp() - damage);
}
