//
// Created by huhua on 2021/8/7.
//
#include <iostream>
#include <QApplication>
#include <QPushButton>

#include "ui/App.h"

int main(int argc, char **argv) {
    std::cout << "hello main 中文测试" << std::endl;
    QApplication q(argc, argv);

    App app;
    app.show();

    return q.exec();
}