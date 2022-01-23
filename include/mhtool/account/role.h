//
// Created by huhua on 2021/10/4.
//

#ifndef MH_TOOL_ROLE_H
#define MH_TOOL_ROLE_H

#include <mh-tool/account/account.h>

class Role {
    Account account;
    std::string serverName1;
    std::string serverName2;

    /**
     * 角色名
     */
    std::string name;
};

#endif //MH_TOOL_ROLE_H
