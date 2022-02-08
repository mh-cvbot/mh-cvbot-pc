//
// Created by huhua on 2022/1/23.
//


#include <mhtool/comm/pos_color.h>

#include <utility>
#include <iostream>

PosColor::PosColor(cv::Point2i pPos, const cv::Vec3b& pColor, int pDst): pos(std::move(pPos)), color(pColor), dst(pDst) {

}

bool PosColor::check(const cv::Mat &mat) {
  auto _c = mat.at<cv::Vec3b>(this->pos);
//  std::cout << "real: " << this->pos << ", color: " << _c << std::endl;
  auto checkSingleColor = [](uchar _dst, uchar src, int range) -> bool {
    return (int)_dst - range <= (int)src && ((int)src >= (int)_dst + range);
  };

  return checkSingleColor(this->color[0], _c[0], this->dst)
      && checkSingleColor(this->color[1], _c[1], this->dst)
      && checkSingleColor(this->color[2], _c[2], this->dst);
}

std::ostream &operator<<(std::ostream &os, const PosColor &thiz) {
  os << "PosColor(pos: " << thiz.pos << ", " << "color: " << thiz.color << ")";
  return os;
}
