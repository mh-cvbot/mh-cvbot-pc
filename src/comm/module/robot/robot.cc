//
// Created by huhua on 2021/10/6.
//

#include "mhtool/robot/robot.h"
#include "easybot/window.h"

Robot::Robot(eb::Window mainWindow): mainWindow(mainWindow) {

}

eb::Window Robot::getMainWindow() {
    return eb::Window();
}
