/*_Created_by_K1ngp1n_*/

#pragma once

#include "../Interfaces/AbstractSpell.hpp"

class Heal : public AbstractSpell {
	public:
	Heal(const std::string name="Heal", int cost=40, int points=60, int range=3);
	~Heal() override;

	void castSpell(AbstractUnit* target) override ;

};



