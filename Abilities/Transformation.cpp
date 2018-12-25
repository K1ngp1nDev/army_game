/*_Created_by_K1ngp1n_*/

#include "Transformation.hpp"
#include "LycanthropeAttack.hpp"
#include "../Interfaces/Beast.hpp"
#include "../Weapons/Claws.hpp"
#include "../States/MageState.hpp"
#include "../Interfaces/Human.hpp"
#include "../Interfaces/AbstractCaster.hpp"
#include "../Interfaces/AbstractUnit.hpp"
#include "../Interfaces/AbstractAttack.hpp"
#include "../Interfaces/AbstractWeapon.hpp"

Transformation::Transformation(AbstractUnit *unit)
	: SpecialAbility(unit)
	, m_unit(unit)
{}

Transformation::~Transformation() {}

void Transformation::specialAbilityActivate() {
	
	std::cout << "Transform to ";
	if ( !dynamic_cast<Beast*>(m_unit->getAttribute()) ) {

		
		m_list_of_names.insert(std::make_pair("source", m_unit->getState()->getName()));
		m_list_of_weapons.insert(std::make_pair("source", std::make_pair(m_unit->getWeapon(), m_unit->getAttack())));
//
		m_unit->setAttribute(new Beast);
		m_unit->getState()->setStep(2);
		m_unit->setWeapon(new Claws(m_unit));
		m_unit->setAttack(new LycanthropeAttack(m_unit));

		m_unit->getState()->setName("Lycanthrope");
		std::cout << m_unit->getState()->getName() << " now" << std::endl;
		BattleField::getInstance()->markerOnBoard(m_unit);
	} else {

			m_unit->getState()->setName(m_list_of_names.find("source")->second);
			std::cout << m_list_of_names.find("source")->second << std::endl;
		
		m_unit->setWeapon(m_list_of_weapons["source"].first);
		std::cout << m_list_of_weapons["source"].first->getTitle() << std::endl;
		
		m_unit->setAttack(m_list_of_weapons["source"].second);
		m_unit->getState()->setStep(1);
		m_unit->setAttribute(new Human);

			std::cout << m_unit->getState()->getName() << " now" << std::endl;
			BattleField::getInstance()->markerOnBoard(m_unit);
	}
}

void Transformation::add(AbstractUnit *unit) {
	m_unit = unit;
	/**name, weapon, attack**/
	if (!dynamic_cast<Beast*>(m_unit->getAttribute() )) {
		
		   /**source/alter 			name 					weapon				attack**/
		std::cout << "source add " << unit->getState()->getName() << std::endl;
//
		m_list_of_names.insert(std::make_pair("source", m_unit->getState()->getName()));
		m_list_of_weapons.insert(std::make_pair("source", std::make_pair(m_unit->getWeapon(), m_unit->getAttack())));
	} else {
		std::cout << "alter add " << m_unit->getState()->getName() << std::endl;
		
		m_list_of_names.insert(std::make_pair("alter", m_unit->getState()->getName()));
		m_list_of_weapons.insert(std::make_pair("alter", std::make_pair(m_unit->getWeapon(), m_unit->getAttack())));
	}
}

