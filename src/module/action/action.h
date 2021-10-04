//
// Created by huhua on 2021/9/28.
//

#ifndef MH_TOOL_ACTION_H
#define MH_TOOL_ACTION_H

#include <string>

class Action {
public:
    /**
     * 运行一个action
     * @return 错误信息，empty string为没有错误
     */
    virtual std::string action() = 0;
};


#endif //MH_TOOL_ACTION_H
