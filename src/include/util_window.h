//
// Created by huhua on 2021/8/8.
//

#ifndef MH_TOOL_UTIL_WINDOW_H
#define MH_TOOL_UTIL_WINDOW_H
#include <Windows.h>
#include <opencv2/opencv.hpp>

// caller response for release
HBITMAP windowTakeHBitmap(HWND hwnd);
void windowTakeImg(HWND  hwnd, cv::Mat out);
#endif //MH_TOOL_UTIL_WINDOW_H
