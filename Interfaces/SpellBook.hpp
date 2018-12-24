/*_Created_by_K1ngp1n_*/

#pragma once

#include "AbstractSpell.hpp"
#include <map>

class AbstractSpell;

enum class Spell {
    Invalid = -1,
    Heal = 1,
	FireBall,
	Blast,
};

enum class HealingSpell {
	Invalid = -1,
	GreaterHeal = 1,
	LowFireBall,
	LowBlast
};
//
//enum class UndeadSpell {
//	SummonDaemon = 5,
////	Curse,
////	Poison,
////	DrainLife,
//};

using spellbook = std::map<Spell, AbstractSpell*>;
using healing_spellbook = std::map<HealingSpell, AbstractSpell*>;
//using undead_spellbook = std::map<UndeadSpell, AbstractSpell*>;




