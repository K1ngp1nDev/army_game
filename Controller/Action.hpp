/*_Created_by_K1ngp1n_*/

#pragma once

#include <iostream>

enum class EActionType : int
{
    Invalid = -1,
    MeleeAttack,
    RangeAttack,
    CastSpell,
    Move,
    Meditation,
    Ride,
    SummonDaemon,
    Transformation
};

inline std::ostream& operator<<(std::ostream& os, EActionType actionType) {
    switch (actionType) {
    case EActionType::Invalid:       os << "Invalid";       break;
    case EActionType::MeleeAttack:   os << "MeleeAttack";   break;
    case EActionType::RangeAttack:   os << "RangeAttack";   break;
    case EActionType::CastSpell:     os << "CastSpell";     break;
    case EActionType::Move:          os << "Move";          break;
	case EActionType::Meditation:    os << "Meditation";    break;
	case EActionType::Ride:          os << "Ride";          break;
	case EActionType::SummonDaemon:  os << "SummonDaemon";  break;
	case EActionType::Transformation:os << "Transformation";break;
	
	    default:
        os << "EActionType::"; break;
    }
    return os;
}


class Action {
private:
    EActionType m_type;
public:
    Action(EActionType type)
        : m_type(type)
    {}

    virtual inline EActionType getType() const {
    	return m_type;
    }

	virtual ~Action() {}
	virtual bool execute() = 0;
};


