//
// Created by huhua on 2021/10/17.
//

#ifndef MH_TOOL_MH_WINDOW_H
#define MH_TOOL_MH_WINDOW_H

#include <easybot/window.h>

class MhWindow {
private:
    eb::Window mainWindow;
    eb::Window *_contentWindow;

public:
    eb::Window* contentWindow();
    explicit MhWindow(eb::Window mainWindow);
};


#endif //MH_TOOL_MH_WINDOW_H
