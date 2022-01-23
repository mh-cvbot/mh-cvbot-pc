//
// Created by huhua on 2022/1/4.
//

#include <mhtool/comm/cv.h>
#include <easybot/easybot.h>
#include <mhtool/comm/pos_colors.h>


// how about namespace without indent?
namespace mh {
namespace cv {

PosIndicator posIndicator(const ::cv::Mat &mat) {
  // first need judge the type of PosIndicator state.
  // first we need get the state.

  const PosColor pc1({9, 50}, {64, 136, 152});
  const PosColor pc2({16, 52}, {120, 224, 224});
  const PosColor pc3({16, 52}, {120, 224, 224});
  // first get the pos state.
  PosColors pcLittle = PosColors(std::vector<PosColor>{pc1, pc2, pc3});

  return PosIndicator();
}
}
}