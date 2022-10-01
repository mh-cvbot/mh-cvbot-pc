//
// Created by huhua on 2021/8/7.
//
#include <QApplication>

#include <iostream>
#include "./preview/preview_ui.h"

int main(int argc, char **argv) {
//    TCHAR NPath[MAX_PATH];
//    GetCurrentDirectory(MAX_PATH, NPath);
//    std::cout << "current dir: " << NPath << std::endl;

    QApplication q(argc, argv);

    std::cout << "5" << std::endl;
    PreviewUI preview;
    preview.show();

    return QApplication::exec();
}