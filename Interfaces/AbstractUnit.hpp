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


};


