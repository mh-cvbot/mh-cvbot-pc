//
// Created by huhua on 2021/9/27.
//

#ifndef MH_TOOL_APP_H
#define MH_TOOL_APP_H
#include <QMainWindow>
#include <QPushButton>
#include <easybot/easybot.h>

class App: public QMainWindow {
private:
    bool hasStarted;
    QPushButton *btStart;
    QPushButton *btStop;
    void createMenus();
    void createToolBars();
    void createDocker();

    void refreshStartUi();

    eb::Window window;


private slots:
    void start();
    void stop();
    void screenshot();

public:
    App();
};

#endif //MH_TOOL_APP_H
