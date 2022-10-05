//
// Created by huhua on 2021/9/27.
//

#include "./app.h"
#include <QtWidgets>
#include <iostream>
#include "mhtool/task/baotu_task.h"
#include <pictool/pictool.h>
#include <mhtool/mh/mh.h>
#include <mhtool/core/cv/game_state_cv.h>

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

  auto pictool = new QPushButton("&Pictool", this);
  toolbar->addWidget(pictool);
  connect(pictool, &QPushButton::clicked, this, &App::doPictool);

  auto debug = new QPushButton("&Debug", this);
  toolbar->addWidget(debug);
  connect(debug, &QPushButton::clicked, this, &App::debug);
}

void App::start() {
  this->hasStarted = true;
  this->refreshStartUi();

  try {
    // how to do this.
    auto *task = new BaotuTask();
    task->realRun().checkWithThrow();
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
    // TODO: how to do a qt toast?
    std::cout << "not started" << std::endl;
    return;
  }

  // how to do this screenshot?
  auto documentLocation = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
  auto fullPath = QDir(documentLocation);
  auto outPath = fullPath.filePath(QDateTime::currentDateTime().toString("yyyy-MM-dd_hh-mm-ss-zzz")
      + ".bmp");
  std::cout << "path: " << outPath.toStdString() << std::endl;
  auto gameWin = MH::inst()->gameWin();
  cv::Mat out;
  gameWin->screenshot(out, 2);
  cv::imwrite(outPath.toStdString(), out);
}

void App::doPictool() {
  cv::Mat out;
  mh::MH::inst()->gameWin()->screenshot(out, 2);
  pt::open(out);
}

void App::debug() {
  auto mh = mh::MH::inst();
  auto win = mh->gameWin();
//  cv::Mat mat;
//  mh->gameWin()->screenshot(mat, 2);
//  cv::Mat out;
//  cv::cvtColor(mat, out, cv::COLOR_BGR2RGB);
//  GameStateCV cv;
//  auto gameState = cv.cv(out);
//  std::cout << "gameState: " << gameState << std::endl;
//  std::cout << "debug called" << std::endl;
  // how to do this?
  win->moveCursor(716 * 2, 543 * 2);
  Sleep(30);
  eb::smartClick();
}
