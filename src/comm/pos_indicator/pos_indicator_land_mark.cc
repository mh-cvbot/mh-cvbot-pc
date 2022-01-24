//
// Created by huhua on 2022/1/23.
//

#include "pos_indicator_land_mark.h"
PosIndicatorLandMark::PosIndicatorLandMark(const cv::Point2i &pos) {
  this->_pcs = new PosColors({
    {pos, {64, 136, 152}},
    // calc middle pos is 9, 50
    {{pos.x + 16 - 9, pos.y + 52 - 50}, {120, 224, 224}},
    {{pos.x + 10 - 9, pos.y + 59 - 50}, {8, 116, 144}},
    {{pos.x + 22 - 9, pos.y + 59 - 50}, {8, 116, 144}},
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