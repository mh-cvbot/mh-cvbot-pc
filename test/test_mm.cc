//
// Created by huhua on 2021/9/28.
//

#include <gtest/gtest.h>
#include <mh-tool/mh/mh.h>
#include <iostream>

TEST(test_mm, isInstalled) {
    MH mm;
    std::cout << mm.getInstallPath() << std::endl;
    std::cout << mm.getPath().launcherPath() << std::endl;
}