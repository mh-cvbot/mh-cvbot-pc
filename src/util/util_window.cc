//
// Created by huhua on 2021/8/8.
//

#include <mh-tool/util_window.h>

HBITMAP windowTakeHBitmap(HWND hwnd) {
    RECT rect;
    GetWindowRect(hwnd, &rect);
    auto width = rect.right - rect.left;
    auto height = rect.bottom - rect.top;

    auto srcDc = GetDC(hwnd);
    HDC memDc = CreateCompatibleDC(srcDc);

    auto dstBitmap = CreateCompatibleBitmap(srcDc, width, height);

    SelectObject(memDc, dstBitmap);

    BitBlt(srcDc, 0, 0, width, height, memDc, 0, 0, SRCCOPY);
    return dstBitmap;
}

void windowTakeImg(HWND hwnd, cv::Mat out) {
    RECT rect;
    GetWindowRect(hwnd, &rect);
    auto width = rect.right - rect.left;
    auto height = rect.bottom - rect.top;

    // TODO, how to free?
    HBITMAP hBmp = windowTakeHBitmap(hwnd);
    BITMAP bmp;

    GetObject(hBmp, sizeof(BITMAP), &bmp);
}

