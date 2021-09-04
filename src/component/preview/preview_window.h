//
// Created by huhua on 2021/8/30.
//

#ifndef MH_TOOL_PREVIEW_WINDOW_H
#define MH_TOOL_PREVIEW_WINDOW_H


class PreviewWindow {
private:
    bool hasStarted = false;

    int frame = 60;
    // yes, you can stop by click the x button;

public:
    PreviewWindow(eb::Window window);
    void start();
};


#endif //MH_TOOL_PREVIEW_WINDOW_H
