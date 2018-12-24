#include "actionfactory.h"
#include "ActionMageCast.hpp"
#include "ActionMeleeAttack.hpp"
#include "ActionUnitMove.hpp"
#include "ActionMageMeditation.hpp"
#include "ActionRangeAttack.hpp"
#include "ActionUseMount.hpp"
#include "ActionSummonDaemon.hpp"
#include "ActionTransformation.hpp"

Action* ActionFactory::create(EActionType actionType)
{
    switch (actionType) {
	    case EActionType::MeleeAttack:      return new ActionMeleeAttack;
	    case EActionType::RangeAttack:      return new ActionRangeAttack;
	    case EActionType::CastSpell:        return new ActionMageCast;
        case EActionType::Move:             return new ActionUnitMove;
        case EActionType::Meditation:       return new ActionMageMeditation;
        case EActionType::Ride:             return new ActionUseMount;
	    case EActionType::SummonDaemon:     return new ActionSummonDaemon;
	    case EActionType::Transformation:   return new ActionTransformation;
	
	    default:

        return nullptr;
    }
}
