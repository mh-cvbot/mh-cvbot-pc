//
// Created by huhua on 2022/1/23.
//


#include <mhtool/comm/module/pos_colors.h>

#include <utility>
#include <iostream>

PosColors::PosColors(std::vector<PosColor> pPosColors) {
  this->posColors = std::move(pPosColors);
}

bool PosColors::check(const cv::Mat &mat) {
  for (auto pc: this->posColors) {
//    std::cout << "pc: " << pc << std::endl;
    if (!pc.check(mat)) {
      return false;
    }
  }
  return true;
}
std::ostream &operator<<(std::ostream &os, const PosColors &thiz) {
  os << "PosColors(";
  for (const auto& pc: thiz.posColors) {
    os << pc << ", ";
  }
  os << ")";
  return os;
}
