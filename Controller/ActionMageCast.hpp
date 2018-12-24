/*_Created_by_K1ngp1n_*/
#pragma once

#include "Action.hpp"
#include "../Interfaces/AbstractCaster.hpp"
#include "../Interfaces/AbstractPhysician.hpp"
#include "../Units/Berserker.hpp"

class Berserker;

class ActionMageCast : public Action {
	AbstractCaster* m_mage;
	AbstractUnit* m_target;
    Spell m_spell;
public:
    ActionMageCast(AbstractCaster* mage = nullptr, AbstractUnit* target = nullptr)
        : Action(EActionType::CastSpell)
        , m_mage(mage)
        , m_target(target)
        , m_spell(Spell::Invalid)
	{}

	~ActionMageCast() {}

    void setSpellCaster(AbstractCaster* mage) {
        if (m_spell != Spell::Invalid) {
        	if (m_mage->getSpellBook().find(m_spell) != m_mage->getSpellBook().end()) {
		        m_mage = mage;
	        }
        } else {
            m_mage = mage;
        }
	}
    void setTarget(AbstractUnit* unit) {
        m_target = unit;
	}
    void setSpell(Spell spell) {
        if (m_mage) {
		        if (m_mage->getSpellBook().find(spell) != m_mage->getSpellBook().end()) {
			        m_spell = spell;
		        }
//	        }
        } else {
            m_spell = spell;
        }
    }

    int getSpellType() {
    	return (int)m_spell;
    }

	virtual bool execute() override {
		    if (m_mage && m_target && m_spell != Spell::Invalid) {
			    m_mage->castSpell(m_target, m_spell);
			    BattleField::getInstance()->markerOnBoard(m_mage);
			
			    return true;
		    }
        std::cout << "Skip." << std::endl;
		BattleField::getInstance()->markerOnBoard(m_mage);

		return false;
	}

};
