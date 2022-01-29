//
// Created by huhua on 2022/1/24.
//
#include <mhtool/cv.h>
#include <easybot/easybot.h>
#include <mhtool/comm/pos_colors.h>
#include <mhtool/cv/cv_pos_indicator.h>
#include "./pos_indicator_land_mark.h"
#include <tesseract/baseapi.h>
// how about namespace without indent?
namespace mh {
namespace cv {

// I don't have any better idea.
PosIndicatorLandMark _middle({9, 50});

// Ok, now you can write a text.
bool posIndicatorState(const ::cv::Mat &mat, mh::PosIndicatorState *out) {
  if (_middle.pcs()->check(mat)) {
    *out = mh::PosIndicatorState::MIDDLE;
    return true;
  }

  return false;
}

bool posIndicator(const ::cv::Mat &mat, PosIndicator *out) {
  auto tmp = posIndicatorState(mat, &out->state);
  if (!tmp) {
    return false;
  }

  if (out->state == PosIndicatorState::MIDDLE) {
    // ok, first create the right image
    // do you want fix hsv?


//    auto tess =
    // how to cv?
    // let first try tesseract.

    // ok, the pos.
    // and write the mess code here.
  }
  return false;
}

}
}
