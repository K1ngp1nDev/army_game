///*_Created_by_K1ngp1n_*/
//
//#include "WereWolf.hpp"
//#include "../Abilities/ClassicAttack.hpp"
//#include "../Abilities/SpecialAbility.hpp"
//#include "../Abilities/Transformation.hpp"
//
//WereWolf::WereWolf(AbstractState* state)
//	: AbstractUnit(state)
//{}
//
//WereWolf::WereWolf()
//	: AbstractUnit(new HumanWolfState())
//{
//	this->m_weapon = new Fists(this);
//	this->m_attack = new ClassicAttack(this);
//	this->m_special_ability = new Transformation(this, this->getState(), m_attack, m_weapon);
////	this->m_source_attack = new WereWolfAttack(this);
////	this->m_weapon = new Teeth(this);
////	this->m_weapon = new Claws(this);
////	if ( !m_weapon->compare(this)) {
////		this->m_weapon = new Fists(this);
////	}
//}
//
//WereWolf::~WereWolf() {
////	delete human_state;
////	delete wolf_state;
//	delete m_attack;
//	delete m_weapon;
//	delete m_special_ability;
//}
//
//void WereWolf::attack(AbstractUnit *enemy) {
//	m_attack->makeAttack(this,enemy);
//}
//
//void WereWolf::counterAttack(AbstractUnit *enemy) {
//	m_attack->makeCounterAttack(this,enemy);
//}
//
//void WereWolf::clickSpecialAbility() {
//	m_special_ability->specialAbilityActivate();
//}
//
//
//
////void WereWolf::takePhysicalDamage(int damage) {
////	if ( this->human_state->isWereWolfGet() ) {
////		AbstractUnit::takePhysicalDamage(damage*0.8);
////	} else {
////		AbstractUnit::takePhysicalDamage(damage);
////	}
////}
////
////void WereWolf::takeMagicDamage(int damage) {
////	if ( this->human_state->isWereWolfGet() ) {
////
////		AbstractUnit::takeMagicDamage(damage*2);
////		std::cout << "Magic x2 " << damage*2 << std::endl;
////	} else {
////		AbstractUnit::takeMagicDamage(damage);
////	}
////
////}
//
////WereWolfState *WereWolf::getWereWolfState() const {
////	return human_state;
////}
//
//std::ostream &operator<<(std::ostream &out, const WereWolf& werewolf) {
//	out << werewolf.getState()->getName() << " HP:("
//	    << werewolf.getState()->getHp() << "/"
//	    << werewolf.getState()->getHpLimit() << "), "
//	    << werewolf.getWeapon()->getTitle() <<" dmg:("
//	    << werewolf.getWeapon()->getDamage() << ")."
//	    << std::endl;
//
//
//	return out;
//}