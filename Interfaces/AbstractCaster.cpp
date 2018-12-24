/*_Created_by_K1ngp1n_*/

#include "AbstractCaster.hpp"
#include "../Spells/Heal.hpp"
#include "../Spells/FireBall.hpp"
#include "../Spells/Blast.hpp"

AbstractCaster::AbstractCaster(AbstractState* state)
: AbstractUnit(state)

{
	this->m_spell = nullptr;
	_spellbook.insert(std::make_pair(Spell::Heal, new Heal("HEAL", 80, 40, 3)));
	_spellbook.insert(std::make_pair(Spell::FireBall, new FireBall("FIREBALL", 80, 60, 3)));
	_spellbook.insert(std::make_pair(Spell::Blast, new Blast("COLD BLAST", 80, 55, 4)));

}

AbstractCaster::~AbstractCaster() {
	delete m_spell;
}

AbstractSpell *AbstractCaster::getSpell() const {
	return m_spell;
}

MageState* AbstractCaster::getMageState() const {
	MageState* mag_state = static_cast<MageState*>(getState());
	return mag_state;
}

std::set<EActionType> AbstractCaster::availableActions() {
	std::set<EActionType> actions = AbstractUnit::availableActions();
//		actions.insert(EActionType::CastSpell);
//		actions.insert(EActionType::Meditation);

	return actions;
}

void AbstractCaster::clickSpecialAbility() {
	AbstractUnit::clickSpecialAbility();
}

SpecialAbility *AbstractCaster::getSpecialAbility() const {
	return AbstractUnit::getSpecialAbility();
}

void AbstractCaster::setSpecialAbility(SpecialAbility *newAbility) {
	AbstractUnit::setSpecialAbility(newAbility);
}




