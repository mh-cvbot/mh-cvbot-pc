//
// Created by huhua on 2022/1/23.
//

#ifndef MH_TOOL_SRC_COMM_CV_POS_INDICATOR_LAND_MARK_H_
#define MH_TOOL_SRC_COMM_CV_POS_INDICATOR_LAND_MARK_H_
#include <opencv2/core.hpp>
#include "mhtool/core/pos_colors.h"

class PosIndicatorLandMark {
 private:
  PosColors *_pcs = nullptr;

 public:
  explicit PosIndicatorLandMark(const ::cv::Point2i &pos);
  ~PosIndicatorLandMark();

  PosColors* pcs();
};

#endif //MH_TOOL_SRC_COMM_CV_POS_INDICATOR_LAND_MARK_H_
