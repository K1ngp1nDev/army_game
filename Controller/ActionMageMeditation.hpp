/*_Created_by_K1ngp1n_*/

#pragma once

#include "Action.hpp"
#include "../Interfaces/AbstractCaster.hpp"

class ActionMageMeditation : public Action {
	AbstractCaster* m_mage;
	public:
	ActionMageMeditation(AbstractCaster* mage = nullptr)
	: Action(EActionType::Meditation)
	, m_mage(mage)
	{}

	~ActionMageMeditation() {}

	void setSpellCaster(AbstractCaster* mage) {
		m_mage = mage;
	}

	virtual bool execute() override {
		if ( m_mage && (m_mage->getMageState()->getMana() < m_mage->getMageState()->getManaLimit()) ) {
			std::cout << m_mage->getMageState()->getName() << " *meditate* and up mana from ["
			<< m_mage->getMageState()->getMana() << "] to [";
			m_mage->getMageState()->addMana(m_mage->getMageState()->getManaLimit() / 4 );
			std::cout << m_mage->getMageState()->getMana() << "]" << std::endl;
			BattleField::getInstance()->markerOnBoard(m_mage);
			return true;

		}
		BattleField::getInstance()->markerOnBoard(m_mage);
		std::cout << "Skip." << std::endl;

		return false;
	}

};