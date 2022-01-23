//
// Created by huhua on 2021/9/28.
//

#ifndef MH_TOOL_MH_H
#define MH_TOOL_MH_H

#include <string>
#include "./mh_path.h"

/**
 * Should be single instance? strange.
 */
class MH {
public:
    static std::string MH_MAIN_EXE;
    static std::string MH_TAB_EXE;
    const static int CONTENT_WIDTH = 800;
    const static int CONTENT_HEIGHT = 600;

    int startedCount();

    void start();

    bool hasInstalled();

    std::string getInstallPath();

    MhPath getPath();
};
#endif //MH_TOOL_MH_H
