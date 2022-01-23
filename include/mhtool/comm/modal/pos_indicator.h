//
// Created by huhua on 2022/1/23.
//

#ifndef MH_TOOL_INCLUDE_MHTOOL_COMM_MODAL_POS_INDICATOR_H_
#define MH_TOOL_INCLUDE_MHTOOL_COMM_MODAL_POS_INDICATOR_H_
#include <opencv2/core.hpp>
#include "./pos_indicator_state.h"

namespace mh {
class PosIndicator {
 public:
  cv::Point2i pos;
  std::string name;
  PosIndicatorState state;
};
}
#endif //MH_TOOL_INCLUDE_MHTOOL_COMM_MODAL_POS_INDICATOR_H_
