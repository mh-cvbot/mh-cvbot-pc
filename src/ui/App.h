//
// Created by huhua on 2021/9/27.
//

#ifndef MH_TOOL_APP_H
#define MH_TOOL_APP_H
#include <QMainWindow>

class App: public QMainWindow {
private:
    void createMenus();
    void createToolBars();
    void createDocker();

private slots:
    void start();
    void stop();

public:
    App();
};

#endif //MH_TOOL_APP_H
