#pragma once

#include <Action.hpp>

class ActionFactory {
public:
    static Action* create(EActionType actionType);
};

