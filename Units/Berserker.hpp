/*_Created_by_K1ngp1n_*/

#pragma once

#include "../States/BerserkState.hpp"
#include "../Interfaces/AbstractUnit.hpp"
#include "../Abilities/ClassicAttack.hpp"
#include "../Weapons/Axe.hpp"
#include "../Weapons/Fists.hpp"

class BerserkState;
class ClassicAttack;

class Berserker : public AbstractUnit {
	protected:
	Berserker(AbstractState* state);
	public:
	Berserker();
	~Berserker();

	void clickSpecialAbility() override;
	void attack(AbstractUnit *enemy) override;
	void counterAttack(AbstractUnit *enemy) override;
	
	void takeMagicDamage(int damage) override;
	
};

std::ostream& operator<<(std::ostream& out, const Berserker& berserker);


