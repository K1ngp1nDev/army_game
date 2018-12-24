/*_Created_by_K1ngp1n_*/

#pragma once

#include "../Interfaces/AbstractSpell.hpp"

class Blast : public AbstractSpell {
	public:
	Blast(const std::string name = "Blast", int cost = 50, double points = 55, int range = 4);
	~Blast();

	void castSpell(AbstractUnit* target) override ;

};



