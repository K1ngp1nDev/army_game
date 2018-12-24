/*_Created_by_K1ngp1n_*/

#pragma once

#include "SoldierState.hpp"

class SoldierState;

class MageState : public SoldierState {
	protected:
	int manaLimit;
	int mana;
	MageState(std::string name, int strenght, int dexterity, int intelligence);

	public:
	MageState();
	~MageState() override ;


	virtual int getManaLimit() const;
	virtual int getMana() const;

	virtual void setManaLimit(int newManaLimit);
	virtual void setMana(int newMana);

	virtual void addMana(int points);
	virtual void expendMana(int cost);

	int getHpLimit() const override;
	int getHp() const override;
	const std::string getName() const override;

	void setName(const std::string newName) override;
	void setHpLimit(int hitPointsLimit) override;
	void setHp(int hitPoints) override;

	int getStrenght() const override;
	int getDexterity() const override;
	int getIntelligence() const override;
	int getStep() const override;

	void setStrenght(int newStrenght) override;
	void setDexterity(int newDexterity) override;
	void setIntelligence(int newIntelligence) override;
	void setStep(int newStep) override;
};



