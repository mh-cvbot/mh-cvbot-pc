//
// Created by huhua on 2021/8/7.
//
#include <QApplication>

#include "./preview/preview_ui.h"

int main(int argc, char **argv) {
//    TCHAR NPath[MAX_PATH];
//    GetCurrentDirectory(MAX_PATH, NPath);
//    std::cout << "current dir: " << NPath << std::endl;

    QApplication q(argc, argv);
    auto *preview = new PreviewUI(nullptr);
    preview->show();

    return QApplication::exec();
}