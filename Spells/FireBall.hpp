/*_Created_by_K1ngp1n_*/

#pragma once


#include "../Interfaces/AbstractSpell.hpp"

class FireBall : public AbstractSpell {
	public:
	FireBall(const std::string name="FireBall", int cost=50, int points=100, int range=3);
	~FireBall();

	void castSpell(AbstractUnit* target) override ;

};



