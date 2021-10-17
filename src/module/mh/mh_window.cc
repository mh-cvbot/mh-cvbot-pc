//
// Created by huhua on 2021/10/17.
//

#include <mh-tool/module/mh/mh.h>
#include <mh-tool/module/mh/mh_window.h>

#include <utility>

MhWindow::MhWindow(eb::Window mainWindow): mainWindow(std::move(mainWindow)), _contentWindow(nullptr) {
    auto subWindows = this->mainWindow.getSubWindows();
    for (const auto &win: subWindows) {
        if (win.rect.width == MH::CONTENT_WIDTH && win.rect.height == MH::CONTENT_HEIGHT) {
           this->_contentWindow = new eb::Window(win.hwnd);
        }
    }
}

eb::Window* MhWindow::contentWindow() {
    return this->_contentWindow;
}
