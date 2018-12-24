/*_Created_by_K1ngp1n_*/

#include "Mount.hpp"
#include "AbstractUnit.hpp"
#include "AbstractState.hpp"

Mount::Mount(AbstractUnit *rider)
	: SpecialAbility(rider)
	, step(2)
	, m_rider(rider)
	{}

Mount::~Mount() {
	delete m_rider;
}

int Mount::getStep() const {
	return this->step;
}

void Mount::specialAbilityActivate() {
	if ( m_rider->getState()->getStep() == 1 ) {
		m_rider->getState()->setStep(step);
		std::cout << m_rider->getState()->getName() << " ride a horse." << std::endl;
	} else {
		m_rider->getState()->setStep(1);
		std::cout << m_rider->getState()->getName() << " get down of horse." << std::endl;
	}
}



