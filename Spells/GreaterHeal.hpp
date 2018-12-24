/*_Created_by_K1ngp1n_*/

#pragma once

#include "../Interfaces/AbstractSpell.hpp"

class GreaterHeal : public AbstractSpell {
	public:
	GreaterHeal(const std::string name = "GreaterHeal", int cost = 70, int points = 120, int range=3);

	~GreaterHeal() override;

	void castSpell(AbstractUnit *target) override;
};



