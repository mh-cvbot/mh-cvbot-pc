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
#include <QDockWidget>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include "./component/log/log_view.h"
#include <easybot/easybot.h>

#define WIDTH 800
#define HEIGHT 600

static void moveToRight(QMainWindow *window) {
    auto *screen = QGuiApplication::primaryScreen();
    window->move(screen->size().width() - WIDTH, (screen->size().height() - HEIGHT) / 2);
}

App::App() {
    this->resize(WIDTH, HEIGHT);
    moveToRight(this);

//    this->createMenus();
    this->createToolBars();
}

void App::createMenus() {
}

void App::createToolBars() {
    auto toolbar = new QToolBar("toolbar");
    addToolBar(toolbar);
    this->btStart = new QPushButton("开始", this);
    toolbar->addWidget(btStart);
    this->btStop = new QPushButton("停止", this);
    btStop->setEnabled(false);
    toolbar->addWidget(btStop);

    connect(btStart, &QPushButton::clicked, this, &App::start);
}

void App::start() {
    this->hasStarted = true;
    this->refreshStartUi();

    // 开始的逻辑怎么写合适？
    auto mhmainProcessId = eb::findProcessId("mhmain.exe");
    std::cout << "mhmainProcessId: " << mhmainProcessId << std::endl;

    if (mhmainProcessId == 0) {
        statusBar()->showMessage("请开启游戏");
        stop();
        return;
    }
}

void App::stop() {
    this->hasStarted = false;
    this->refreshStartUi();
}

void App::createDocker() {
    auto *dockLog = new QDockWidget(tr("Log"), this);
    dockLog->setAllowedAreas(Qt::RightDockWidgetArea | Qt::BottomDockWidgetArea);
    dockLog->setWidget(new LogView());
    addDockWidget(Qt::BottomDockWidgetArea, dockLog);
}

void App::refreshStartUi() {
    if (this->hasStarted) {
        this->btStart->setEnabled(false);
        this->btStop->setEnabled(true);
    } else {
        this->btStart->setEnabled(true);
        this->btStop->setEnabled(false);
    }
}
