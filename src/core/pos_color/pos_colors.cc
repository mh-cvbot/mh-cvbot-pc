//
// Created by huhua on 2022/1/23.
//


#include "mhtool/core/pos_color/pos_colors.h"

#include <utility>
#include <iostream>

bool PosColors::check(const cv::Mat &mat, int mistake) {
  for (auto pc: this->posColors) {
    if (!pc.check(mat, mistake)) {
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

PosColors::PosColors(std::vector<PosColor> pPosColors): posColors(std::move(pPosColors)) {}