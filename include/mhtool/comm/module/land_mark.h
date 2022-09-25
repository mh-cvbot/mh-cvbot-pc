//
// Created by huhua on 2022/1/23.
//

#ifndef MH_TOOL_INCLUDE_MHTOOL_COMM_LAND_MARK_H_
#define MH_TOOL_INCLUDE_MHTOOL_COMM_LAND_MARK_H_
#include <opencv2/core.hpp>
#include "mhtool/core/pos_colors.h"

class LandMark {
 private:
  cv::Point2i _pos;
  PosColors _posColors;

 public:
  LandMark(cv::Point2i pos, PosColors posColors);
};
#endif //MH_TOOL_INCLUDE_MHTOOL_COMM_LAND_MARK_H_
