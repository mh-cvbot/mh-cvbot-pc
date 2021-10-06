//
// Created by huhua on 2021/10/4.
//

#ifndef MH_TOOL_ROBOT_H
#define MH_TOOL_ROBOT_H

#include <easybot/easybot.h>

/**
 * A robot is a account or many account?
 */
class Robot {
public:
    Robot(eb::Window mainWindow);
    eb::Window getMainWindow();

private:
    eb::Window mainWindow;
};
#endif //MH_TOOL_ROBOT_H
