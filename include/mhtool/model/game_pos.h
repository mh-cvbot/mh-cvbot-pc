//
// Created by huhua on 2022/1/23.
//

#ifndef MH_TOOL_INCLUDE_MHTOOL_COMM_MODAL_POS_INDICATOR_H_
#define MH_TOOL_INCLUDE_MHTOOL_COMM_MODAL_POS_INDICATOR_H_
#include <opencv2/core.hpp>
#include "easybot/easybot.h"
#include "mhtool/comm/module/pos_indicator/pos_indicator_state.h"

using namespace mh;

namespace mh {

class GamePos {
 public:
  std::string name;
  eb::Pos pos;
  PosIndicatorState state;

  bool isNear(const GamePos &indicator);
  bool isNear(const eb::Pos &other);
  bool operator==(const mh::GamePos &other);
  friend bool operator==(const mh::GamePos &thiz, const mh::GamePos &other);
  friend std::ostream& operator<<(std::ostream& os, const GamePos& thiz);
};

}
#endif //MH_TOOL_INCLUDE_MHTOOL_COMM_MODAL_POS_INDICATOR_H_
