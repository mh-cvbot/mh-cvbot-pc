//
// Created by huhua on 2022/1/23.
//


#include <mhtool/comm/pos_colors.h>

#include <utility>

PosColors::PosColors(std::vector<PosColor> pPosColors) {
  this->posColors = std::move(pPosColors);
}

bool PosColors::check(const cv::Mat &mat) {
  for (auto pc: this->posColors) {
    if (!pc.check(mat)) {
      return false;
    }
  }
  return true;
}