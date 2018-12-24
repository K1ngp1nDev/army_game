/*_Created_by_K1ngp1n_*/

#include "SpecialAbility.hpp"

SpecialAbility::SpecialAbility(AbstractUnit *unit)
	: m_unit(unit)
{}

SpecialAbility::~SpecialAbility() {

}

void SpecialAbility::specialAbilityActivate() {

}

void SpecialAbility::specialAbilityToTarget(AbstractUnit *target) {

}

std::set<EActionType> SpecialAbility::availableActions() const {
    return std::set<EActionType>();
}
