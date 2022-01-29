//
// Created by huhua on 2022/1/23.
//

#include "pos_indicator_land_mark.h"
PosIndicatorLandMark::PosIndicatorLandMark(const cv::Point2i &pos) {
  this->_pcs = new PosColors({
    {pos, {152, 136, 64}},
    // calc _middle pos is 9, 50
    {{pos.x + 16 - 9, pos.y + 52 - 50}, {224, 224, 120}},
    {{pos.x + 10 - 9, pos.y + 59 - 50}, {144, 116, 8}},
    {{pos.x + 22 - 9, pos.y + 59 - 50}, {144, 116, 8}},
  });
}

PosIndicatorLandMark::~PosIndicatorLandMark() {
  if (this->_pcs != nullptr) {
    delete this->_pcs;
    this->_pcs = nullptr;
  }
}

PosColors* PosIndicatorLandMark::pcs() {
  return this->_pcs;
}