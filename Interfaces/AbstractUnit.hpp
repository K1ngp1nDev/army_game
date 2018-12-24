/*_Created_by_K1ngp1n_*/

#pragma once

#include <set>
#include <iostream>

class AbstractState;
class AbstractAttack;
class AbstractWeapon;
class AbstractSpell;
class SpecialAbility;
class Attribute;
class Observer;
enum class EActionType : int;

class AbstractUnit {
	protected:
	AbstractWeapon * m_weapon;
	AbstractAttack *m_attack;
	AbstractState* m_abstractState;
	SpecialAbility* m_special_ability;
	Attribute* m_attribute;
	AbstractUnit(AbstractState* state);
	public:
	virtual ~AbstractUnit() = 0;

	virtual void takePhysicalDamage(int damage);
	virtual void takeMagicDamage(int damage);

    virtual std::set<EActionType> availableActions();

	virtual void clickSpecialAbility();

	virtual void attack(AbstractUnit *enemy);
	virtual void counterAttack(AbstractUnit *enemy);

	virtual AbstractState *getState() const;
	virtual void setState(AbstractState *newState);

	virtual AbstractAttack *getAttack() const;
	virtual void setAttack(AbstractAttack *newAttack);

	virtual AbstractWeapon *getWeapon() const;
	virtual void setWeapon(AbstractWeapon *newWeapon);

	virtual SpecialAbility *getSpecialAbility() const;
	virtual void setSpecialAbility(SpecialAbility *newAbility);
	
	virtual Attribute *getAttribute() const;
	virtual void setAttribute(Attribute *newAttribute);
	
	virtual void isAlive();

//	virtual void addHits(int hits);
//	const std::set<AbstractUnit*>& getObservers() const;
//	const std::set<AbstractUnit*>& getObservables() const;

//	virtual void addObserver(AbstractUnit* observer);
//	virtual void removeObserver(AbstractUnit* observer);
//	virtual void addObservable(AbstractUnit* observable);
//	virtual void removeObservable(AbstractUnit* observable);

//	virtual void informObservers();
//	virtual void informObservables();
};



//std::ostream& operator<<(std::ostream& out, const AbstractUnit& unit);



