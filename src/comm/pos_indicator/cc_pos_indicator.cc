//
// Created by huhua on 2022/1/24.
//
#include <mhtool/comm/cv.h>
#include <easybot/easybot.h>
#include <mhtool/comm/pos_colors.h>
#include <mhtool/comm/cv/cv_pos_indicator.h>
#include "./pos_indicator_land_mark.h"


// how about namespace without indent?
namespace mh {
namespace cv {

PosIndicatorLandMark landMarkLittle({9, 50});

// Ok, now you can write a text.
StateRst posIndicatorState(const ::cv::Mat &mat) {
  if (landMarkLittle.pcs()->check(mat)) {
    return {
      true,
      mh::PosIndicatorState::MIDDLE,
    };
  }

  return {
    false,
    mh::PosIndicatorState ::LITTLE,
  };
}

PosIndicator posIndicator(const ::cv::Mat &mat) {
  // first need judge the type of PosIndicator state.
  // first we need get the state.
  return PosIndicator();
}
}
}
