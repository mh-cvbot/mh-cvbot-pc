//
// Created by huhua on 2022/1/23.
//

#ifndef MH_TOOL_INCLUDE_MHTOOL_COMM_POS_COLOR_H_
#define MH_TOOL_INCLUDE_MHTOOL_COMM_POS_COLOR_H_
#include <opencv2/core.hpp>

class PosColor {
 public:
  // ok, if you are vec3b, you should be bgr
  PosColor(::cv::Point2i pPos, const ::cv::Vec3b& pColor, int pDst = 0);
  ::cv::Point2i pos;
  ::cv::Vec3b color;
//  // 允许误差
// Deprecated!!, use check(const ::cv::Mat &mat, int mistake)
  int dst;

 public:
  bool check(const ::cv::Mat &mat);
  bool check(const ::cv::Mat &mat, int mistake);

  friend std::ostream& operator<<(std::ostream& os, const PosColor& thiz);
};
#endif //MH_TOOL_INCLUDE_MHTOOL_COMM_POS_COLOR_H_
