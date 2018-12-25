/*_Created_by_K1ngp1n_*/

#pragma once

#include "SoldierState.hpp"

class SoldierState;

class HumanWolfState : public SoldierState {
	bool isWereWolf;
	HumanWolfState(std::string name, int strenght, int dexterity, int intelligence);

	public:
	HumanWolfState();
	~HumanWolfState() override;

	bool isWereWolfGet();
	void setWereWolf(bool value);
};


