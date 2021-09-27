//
// Created by huhua on 2021/9/28.
//

#ifndef MH_TOOL_ACTION_START_MM_H
#define MH_TOOL_ACTION_START_MM_H

#include "./action.h"

class ActionStartMM : public Action {
public:
    // why I need define this? strange.
    std::string action() override;
};


#endif //MH_TOOL_ACTION_START_MM_H
