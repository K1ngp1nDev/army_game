/*_Created_by_K1ngp1n_*/

#pragma once

#include "../States/SoldierState.hpp"
#include "../Interfaces/AbstractUnit.hpp"
#include "../Abilities/ClassicAttack.hpp"
#include "../Abilities/Mount.hpp"
#include "../Weapons/VikingSword.hpp"
#include "../Weapons/Fists.hpp"

class SoldierState;
class ClassicAttack;

 class Soldier : public AbstractUnit {
 	Mount* m_mount;
 	protected:
 	Soldier(AbstractState* state);
	public:
	Soldier();
	virtual~Soldier();

	void clickSpecialAbility() override;
	void attack(AbstractUnit *enemy) override;
	void counterAttack(AbstractUnit *enemy) override;

 };

std::ostream& operator<<(std::ostream& out, const Soldier& soldier);


