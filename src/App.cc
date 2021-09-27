//
// Created by huhua on 2021/9/27.
//

#include "App.h"
#include <iostream>
#include <QApplication>
#include <Qt>
#include <QDesktopWidget>
#include <mh-tool/util_qt.h>
#include <QGuiApplication>
#include <QScreen>

#define WIDTH 800
#define HEIGHT 600

static void moveToRight(QMainWindow *window) {
    auto *screen = QGuiApplication::primaryScreen();
    window->move(screen->size().width() - WIDTH, (screen->size().height() - HEIGHT) / 2);
}

App::App() {
    this->resize(WIDTH, HEIGHT);
    moveToRight(this);
}
