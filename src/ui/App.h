//
// Created by huhua on 2021/9/27.
//

#ifndef MH_TOOL_APP_H
#define MH_TOOL_APP_H
#include <QMainWindow>
#include <QPushButton>
#include <easybot/easybot.h>
#include "mhtool/mh/mh_window.h"
#include <mhtool/mh/mh_main_loop.h>
#include "./component/log/log_view.h"

class App : public QMainWindow {
 private:
  /**
   * For now, only for baotu task
   */
  bool hasStarted;
  QPushButton *btStart;
  QPushButton *btStop;
  void createMenus();
  void createToolBars();
  void createDocker();
  void refreshStartUi();
  MhWindow *mhWindow;
  MHMainLoop *mhMainLoop;
  TaskLogView *logView;

 private slots:
  void start();
  void stop();
  void screenshot();

 public:
  App();
};

#endif //MH_TOOL_APP_H
