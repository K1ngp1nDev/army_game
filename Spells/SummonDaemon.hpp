/*_Created_by_K1ngp1n_*/

#pragma once

#include "../Interfaces/AbstractSpell.hpp"
#include "../Units/Daemon.hpp"
#include "../Units/Warlock.hpp"

class Daemon;
class Warlock;

class SummonDaemon : public AbstractSpell{
//	Warlock* mm_owner;
	public:
	SummonDaemon(const std::string name="Summon_Daemon", int cost=80, int points=0, int range=1);
	~SummonDaemon() override ;

	void castSpell(AbstractUnit *master) override;
};



