//
// Created by huhua on 2022/1/23.
//

#include "pos_indicator_land_mark.h"
PosIndicatorLandMark::PosIndicatorLandMark(const cv::Point2i &pos) {
  this->_pcs = new PosColors({
    {pos, {64, 136, 152}},
    {{0, 0}, {64, 136, 152}},
  });
}

PosIndicatorLandMark::~PosIndicatorLandMark() {
  if (this->_pcs != nullptr) {
    delete this->_pcs;
    this->_pcs = nullptr;
  }
}
