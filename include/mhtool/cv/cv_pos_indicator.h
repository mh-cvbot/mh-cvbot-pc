//
// Created by huhua on 2022/1/24.
//

#ifndef MH_TOOL_INCLUDE_MHTOOL_COMM_CV_CV_POS_INDICATOR_H_
#define MH_TOOL_INCLUDE_MHTOOL_COMM_CV_CV_POS_INDICATOR_H_
#include "mhtool/comm/module/pos_indicator/pos_indicator_state.h"
#include <opencv2/core.hpp>
#include "mhtool/model/game_pos.h"

namespace mh {
namespace cv1 {
bool posIndicatorState(const ::cv::Mat &mat, mh::PosIndicatorState *out);
bool posIndicator(const ::cv::Mat &mat, GamePos *out);
}
}
#endif //MH_TOOL_INCLUDE_MHTOOL_COMM_CV_CV_POS_INDICATOR_H_
