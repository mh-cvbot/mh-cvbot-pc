//
// Created by huhua on 2021/9/28.
//

#ifndef MH_TOOL_MM_H
#define MH_TOOL_MM_H

#include <string>
/**
 * Should be single instance? strange.
 */
class MM {
public:
    bool hasInstalled();

    std::string getMainExePath();
};
#endif //MH_TOOL_MM_H
