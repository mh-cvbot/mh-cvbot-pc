//
// Created by huhua on 2022/1/23.
//

#ifndef MH_TOOL_INCLUDE_MHTOOL_COMM_MODAL_POS_INDICATOR_STATE_H_
#define MH_TOOL_INCLUDE_MHTOOL_COMM_MODAL_POS_INDICATOR_STATE_H_
namespace mh {
enum PosIndicatorState {
  LITTLE,
  MIDDLE,
  BIG,
};

inline std::ostream& operator<<(std::ostream& os, const mh::PosIndicatorState& thiz) {
  switch (thiz) {
    case mh::PosIndicatorState::LITTLE:
      os << "little";
      break;
    case mh::PosIndicatorState::MIDDLE:
      os << "middle";
      break;
    case mh::PosIndicatorState::BIG:
      os << "big";
      break;
  }
  return os;
}
}
#endif //MH_TOOL_INCLUDE_MHTOOL_COMM_MODAL_POS_INDICATOR_STATE_H_
