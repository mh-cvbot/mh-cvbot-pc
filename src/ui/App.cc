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
#include <chrono>
#include <QVBoxLayout>
#include <mhtool/mh/task/baotu_task.h>

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
  auto label = new QLabel();
  this->statusBar()->addPermanentWidget(label);

  auto *centralWidget = new QWidget;
  // setup main window.
  auto *mainLayout = new QVBoxLayout();
  mainLayout->addWidget(new QWidget());
  this->logView = new TaskLogView;
  mainLayout->addWidget(this->logView);
  centralWidget->setLayout(mainLayout);
  setCentralWidget(centralWidget);

  this->mhMainLoop = new MHMainLoop(label);
//  this->mhMainLoop->start();
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
    // how to do this.
    // TODO: check mh has start.
    auto *task = new BaotuTask();
    task->run().checkWithThrow();
  } catch (std::runtime_error &err) {
    std::cout << "has error: " << err.what() << std::endl;
    this->logView->addError(err.what());

    this->hasStarted = false;
    this->refreshStartUi();
  }
}

void App::stop() {
  this->hasStarted = false;
  this->refreshStartUi();
}

void App::createDocker() {
//  auto *dockLog = new QDockWidget(tr("Log"), this);
//  dockLog->setAllowedAreas(Qt::RightDockWidgetArea | Qt::BottomDockWidgetArea);
//  dockLog->setWidget(new LogView());
//  addDockWidget(Qt::BottomDockWidgetArea, dockLog);
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
//    auto window = this->mhWindow->contentWindow();
//    runtime::screenshot(window);
}