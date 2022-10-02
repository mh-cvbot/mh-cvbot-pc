//
// Created by huhua on 2022/1/23.
//

#ifndef MH_TOOL_INCLUDE_MHTOOL_COMM_POS_COLORS_H_
#define MH_TOOL_INCLUDE_MHTOOL_COMM_POS_COLORS_H_
#include <vector>
#include "mhtool/core/pos_color.h"
#include <opencv2/core.hpp>

class PosColors {
  std::vector<PosColor> posColors;

 public:
  // copy construct??
  explicit PosColors(std::vector<PosColor> pPosColors);

 public:
  inline bool check(const ::cv::Mat & mat) {
    return check(mat, 0);
  }

  bool check(const ::cv::Mat & mat, int mistake);

  friend std::ostream& operator<<(std::ostream& os, const PosColors& thiz);
};
#endif //MH_TOOL_INCLUDE_MHTOOL_COMM_POS_COLORS_H_
