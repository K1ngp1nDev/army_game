/*_Created_by_K1ngp1n_*/

#pragma once

#include "../Interfaces/AbstractCaster.hpp"
#include "../Abilities/ClassicAttack.hpp"
#include "../Units/Daemon.hpp"

class WarlockState;
class ClassicAttack;
class Daemon;

class Warlock : public AbstractCaster {
	Daemon* m_daemon;
	AbstractSpell* spell;
	Warlock(AbstractState* state);
	public:
	Warlock();
	~Warlock() override;

	void castSpell(AbstractUnit *target, Spell spell) override;
	void attack(AbstractUnit *enemy) override;
	void counterAttack(AbstractUnit *enemy) override;

	void summonDaemon();
	Daemon* getDaemon() const;
	void setDemon(Daemon* daemon) ;
	void clickSpecialAbility() override;

};

std::ostream& operator<<(std::ostream& out, const Warlock& warlock);



