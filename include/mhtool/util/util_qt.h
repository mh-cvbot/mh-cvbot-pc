//
// Created by huhua on 2021/9/27.
//

#ifndef MH_TOOL_UTIL_QT_H
#define MH_TOOL_UTIL_QT_H
#include <string>
#include <QPoint>
#include <QImage>
#include <opencv2/opencv.hpp>

/**
 * QPoint toString
 */
std::string toString(const QPoint &p);

QImage mat2QImage(const cv::Mat& mat);

#endif //MH_TOOL_UTIL_QT_H
