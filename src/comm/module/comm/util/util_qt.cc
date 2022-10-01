//
// Created by huhua on 2021/9/27.
//

#include <mhtool/util/util_qt.h>


std::string toString(const QPoint &p) {
    return "QPoint(" + std::to_string(p.x()) + ", " + std::to_string(p.y()) + ")";
}

QImage mat2QImage(const cv::Mat & mat) {
  return {(unsigned char *) mat.data, mat.cols, mat.rows, static_cast<int>(mat.step),
          QImage::Format_RGB888};
}

