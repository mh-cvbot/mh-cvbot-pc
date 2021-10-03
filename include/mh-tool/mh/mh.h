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
    bool hasInstalled();

    std::string getInstallPath();

    MhPath getPath();
};
#endif //MH_TOOL_MH_H
