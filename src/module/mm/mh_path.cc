//
// Created by huhua on 2021/10/3.
//

#include <mh-tool/mh/mh_path.h>

#include <utility>

namespace fs = boost::filesystem;

MhPath::MhPath(const std::string& path): root(path) {
}

std::string MhPath::launcherPath() {
    return (this->root / fs::path("my.exe")).string();
}

