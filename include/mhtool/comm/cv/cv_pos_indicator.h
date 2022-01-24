//
// Created by huhua on 2022/1/24.
//

#ifndef MH_TOOL_INCLUDE_MHTOOL_COMM_CV_CV_POS_INDICATOR_H_
#define MH_TOOL_INCLUDE_MHTOOL_COMM_CV_CV_POS_INDICATOR_H_
#include <mhtool/comm/pos_indicator/pos_indicator_state.h>
#include <opencv2/core.hpp>

struct StateRst {
  bool success;
  mh::PosIndicatorState state;
};

namespace mh {
namespace cv {
  StateRst posIndicatorState(const ::cv::Mat &mat);
}
}
#endif //MH_TOOL_INCLUDE_MHTOOL_COMM_CV_CV_POS_INDICATOR_H_
