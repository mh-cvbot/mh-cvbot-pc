//
// Created by huhua on 2022/1/23.
//

#ifndef MH_TOOL_INCLUDE_MHTOOL_COMM_MODAL_POS_INDICATOR_H_
#define MH_TOOL_INCLUDE_MHTOOL_COMM_MODAL_POS_INDICATOR_H_
#include <opencv2/core.hpp>
#include <easybot/easybot.h>
#include "mhtool/comm/module/pos_indicator/pos_indicator_state.h"

using namespace mh;

namespace mh {
class PosIndicator {
 public:
  std::string name;
  eb::Pos pos;
  PosIndicatorState state;

  bool isNear(const PosIndicator &indicator);
  bool isNear(const eb::Pos &other);
  bool operator==(const mh::PosIndicator &other);
  friend bool operator==(const mh::PosIndicator &thiz, const mh::PosIndicator &other);
  friend std::ostream& operator<<(std::ostream& os, const PosIndicator& thiz);
};
}
#endif //MH_TOOL_INCLUDE_MHTOOL_COMM_MODAL_POS_INDICATOR_H_
