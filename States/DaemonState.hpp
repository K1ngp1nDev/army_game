/*_Created_by_K1ngp1n_*/

#pragma once

#include "SoldierState.hpp"


class DaemonState : public SoldierState {
//	public:
//	protected:
	DaemonState(std::string name, int strenght, int dexterity, int intelligence);

	public:
	DaemonState();
	~DaemonState() override;

	int getHpLimit() const override;
	int getHp() const override;
//	double getDamage() const override;
	const std::string getName() const override;

	int getStrenght() const override;
	int getDexterity() const override;
	int getIntelligence() const override;
	int getStep() const override;
//	int getRange() const override;

	void setName(const std::string newName) override;
	void setHpLimit(int hitPointsLimit) override;
	void setHp(int hitPoints) override;
//	void setDamage(double damage) override;

	void setStrenght(int newStrenght) override;
	void setDexterity(int newDexterity) override;
	void setIntelligence(int newIntelligence) override;
	void setStep(int newStep) override;
//	void setRange(int newRange) override;
};




