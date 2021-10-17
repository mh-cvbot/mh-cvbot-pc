//
// Created by huhua on 2021/10/3.
//

#ifndef MH_TOOL_MH_PATH_H
#define MH_TOOL_MH_PATH_H

#include <string>
#include <boost/filesystem.hpp>

class MhPath {
private:
    boost::filesystem::path root;

public:
    MhPath(const std::string& path);
    std::string launcherPath();
};


#endif //MH_TOOL_MH_PATH_H
