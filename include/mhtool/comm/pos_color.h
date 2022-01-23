//
// Created by huhua on 2022/1/23.
//

#ifndef MH_TOOL_INCLUDE_MHTOOL_COMM_POS_COLOR_H_
#define MH_TOOL_INCLUDE_MHTOOL_COMM_POS_COLOR_H_
#include <opencv2/core.hpp>

class PosColor {
 public:
  PosColor(cv::Point2i pPos, const cv::Vec3b& pColor, int pDst = 0);
  cv::Point2i pos;
  cv::Vec3b color;
  // better name?
  int dst;

 public:
  bool check(const cv::Mat &mat);
};
#endif //MH_TOOL_INCLUDE_MHTOOL_COMM_POS_COLOR_H_
