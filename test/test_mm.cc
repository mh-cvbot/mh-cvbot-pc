//
// Created by huhua on 2021/9/28.
//

#include <gtest/gtest.h>
#include <mh-tool/mm.h>
#include <iostream>

TEST(test_mm, isInstalled) {
    MM mm;
    std::cout << mm.getInstallPath() << std::endl;
}