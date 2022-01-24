//
// Created by huhua on 2021/9/27.
//

#include "App.h"
#include <iostream>
#include <QApplication>
#include <QDesktopWidget>
#include <QScreen>
#include <QDockWidget>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include "./component/log/log_view.h"
#include "mhtool/comm/mh/mh.h"
#include "mhtool/comm/runtime/runtime.h"
#include <boost/filesystem.hpp>
#include <easybot/easybot.h>
#include <chrono>


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
    connect(btStop, &QPushButton::clicked, this, &App::stop);

    auto screenshot = new QPushButton("截图", this);
    toolbar->addWidget(screenshot);
    connect(screenshot, &QPushButton::clicked, this, &App::screenshot);
}

void App::start() {
    this->hasStarted = true;
    this->refreshStartUi();

    try {
        // 开始的逻辑怎么写合适？
//        auto pMhMain = eb::Process::findByName(MH::MH_MAIN_EXE);
        auto pMhTab = eb::Process::findByName(MH::MH_TAB_EXE);
        auto pMhMain = eb::Process::findByName(MH::MH_MAIN_EXE);

        std::cout << "pid: " << pMhTab.getPid() << std::endl;
        std::cout << "mhmain pid: " << pMhMain.getPid() << std::endl;

        if (pMhTab.getPid() == 0) {
            statusBar()->showMessage("请开启游戏");
            stop();
            return;
        }

        auto windows = pMhTab.getWindows();

        if (windows.empty()) {
            statusBar()->showMessage("没有找到任何窗口");
            stop();
            return;
        }

        auto window = windows[0];
        for (const auto &w: windows) {
            if (IsWindowVisible(w.hwnd)) {
                std::cout << "is win visible" << std::endl;
                window = w;
                break;
            }
        }

        auto found = IsWindowVisible(window.hwnd);
        if (!found) {
            statusBar()->showMessage("没有找到目标窗口");
            stop();
            return;
        }

        this->mhWindow = new MhWindow(window);

        if (eb::gbk2utf8(window.title) == "梦幻西游 ONLINE")  {
            statusBar()->showMessage("没有登录");
            return;
        }

        statusBar()->showMessage("请继续完成逻辑");
    } catch (std::runtime_error &err) {
        std::cout << "has error: " << err.what() << std::endl;
        this->hasStarted = false;
        this->refreshStartUi();
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

void App::screenshot() {
    if (!this->hasStarted) {
        std::cout << "not started" << std::endl;
        return;
    }
    auto window = this->mhWindow->contentWindow();
    runtime::screenshot(window);
}