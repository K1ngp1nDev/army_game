/*_Created_by_K1ngp1n_*/

#pragma once

#include "../States/DaemonState.hpp"
#include "../Units/Soldier.hpp"
#include "../Units/Warlock.hpp"
#include "../Abilities/DaemonAttack.hpp"

class Warlock;

class Daemon : public Soldier {
	Warlock * m_owner;
	Daemon(AbstractState* state);
	public:
	Daemon(Warlock*owner);

	~Daemon() override ;


	void attack(AbstractUnit *enemy) override;
	void counterAttack(AbstractUnit *enemy) override;
	Warlock* getOwner() const;

};
std::ostream& operator<<(std::ostream& out, const Daemon& daemon);



