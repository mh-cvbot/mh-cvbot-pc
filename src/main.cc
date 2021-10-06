//
// Created by huhua on 2021/8/7.
//
#include <iostream>
#include <QApplication>
#include <mh-tool/util/util_string.h>

#include "ui/App.h"

int main(int argc, char **argv) {
    QApplication q(argc, argv);

    App app;
    app.show();

    return q.exec();
}