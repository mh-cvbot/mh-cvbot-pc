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
  std::string name;
  cv::Point2i pos;
  PosIndicatorState state;

  bool operator==(const mh::PosIndicator &other);
  friend bool operator==(const mh::PosIndicator &thiz, const mh::PosIndicator &other);
  friend std::ostream& operator<<(std::ostream& os, const PosIndicator& thiz);
};
}
#endif //MH_TOOL_INCLUDE_MHTOOL_COMM_MODAL_POS_INDICATOR_H_
