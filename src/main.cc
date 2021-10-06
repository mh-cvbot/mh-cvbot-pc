//
// Created by huhua on 2021/8/7.
//
#include <iostream>
#include <QApplication>
#include <mh-tool/util/util_string.h>

#include "ui/App.h"

int main(int argc, char **argv) {
//    std::cout << "hello main 中文测试" << std::endl;
    std::cout << "梦幻西游" << std::endl;
    std::cout << utf8ToGbk("梦幻西游") << std::endl;
    QApplication q(argc, argv);

    App app;
    app.show();

    return q.exec();
}