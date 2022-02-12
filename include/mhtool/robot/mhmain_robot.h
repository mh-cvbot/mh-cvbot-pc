//
// Created by huhua on 2021/10/4.
//

#ifndef MH_TOOL_MHMAIN_ROBOT_H
#define MH_TOOL_MHMAIN_ROBOT_H
#include <mh-tool/account/account.h>
#include <mh-tool/account/role.h>
#include <qt_windows.h>

class MhMainRobot {
private:
    Account account;
    Role role;

    DWORD pid;

public:
    /**
     * 是否已经开启
     */
    bool hasStart();

    /**
     * 是否已经登录
     */
    bool hasLogin();

    /**
     * 从窗口获取当前的账号角色名
     */
    fetchRoleName();
};
#endif //MH_TOOL_MHMAIN_ROBOT_H
