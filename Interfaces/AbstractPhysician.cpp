/*_Created_by_K1ngp1n_*/

#include "AbstractPhysician.hpp"
#include "../Spells/Heal.hpp"
#include "../Spells/Blast.hpp"
#include "../Spells/FireBall.hpp"

AbstractPhysician::AbstractPhysician(AbstractState* state)
	: AbstractCaster(state)
{
	this->m_spell = nullptr;
																			//need, points, range
	healer_spellbook.insert(std::make_pair(Spell::Heal, new Heal("GREATER HEAL", 80, 80, 4)));
	healer_spellbook.insert(std::make_pair(Spell::FireBall, new FireBall("LOW FIREBALL", 80, 30, 3)));
	healer_spellbook.insert(std::make_pair(Spell::Blast, new Blast("COLD BLAST", 80, 40, 3)));
}

AbstractPhysician::~AbstractPhysician() {}

AbstractSpell *AbstractPhysician::getSpell() const {
	return m_spell;
}

MageState* AbstractPhysician::getMageState() const {
	MageState* mag_state = static_cast<MageState*>(getState());
	return mag_state;
}

void AbstractPhysician::clickSpecialAbility() {
	AbstractCaster::clickSpecialAbility();
}

SpecialAbility *AbstractPhysician::getSpecialAbility() const {
	return AbstractCaster::getSpecialAbility();
}

void AbstractPhysician::setSpecialAbility(SpecialAbility *newAbility) {
	AbstractCaster::setSpecialAbility(newAbility);
}


