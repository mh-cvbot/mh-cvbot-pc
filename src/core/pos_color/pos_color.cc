//
// Created by huhua on 2022/1/23.
//


#include "mhtool/core/pos_color.h"

#include <utility>
#include <iostream>

PosColor::PosColor(cv::Point2i pPos, const cv::Vec3b& pColor, int pDst):
pos(std::move(pPos)), color(pColor), dst(pDst) {}

bool PosColor::check(const cv::Mat &mat) {
  return this->check(mat, this->dst);
}

bool PosColor::check(const ::cv::Mat &mat, int mistake) {
  auto _c = mat.at<cv::Vec3b>(this->pos);
  auto checkSingleColor = [](uchar _dst, uchar src, int range) -> bool {
    return (int)_dst - range <= (int)src && ((int)src >= (int)_dst + range);
  };

  return checkSingleColor(this->color[0], _c[0], mistake)
      && checkSingleColor(this->color[1], _c[1], mistake)
      && checkSingleColor(this->color[2], _c[2], mistake);
}

std::ostream &operator<<(std::ostream &os, const PosColor &thiz) {
  os << "PosColor(pos: " << thiz.pos << ", " << "color: " << thiz.color << ")";
  return os;
}
