//
// Created by huhua on 2021/8/7.
//
#include <iostream>
#include <QApplication>

#include "ui/App.h"
#include <qt_windows.h>

int main(int argc, char **argv) {
//    TCHAR NPath[MAX_PATH];
//    GetCurrentDirectory(MAX_PATH, NPath);
//    std::cout << "current dir: " << NPath << std::endl;

    QApplication q(argc, argv);

//    App app;
//    app.show();

    return QApplication::exec();
}