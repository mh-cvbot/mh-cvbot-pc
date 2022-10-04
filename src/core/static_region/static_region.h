//
// Created by huhua on 2022/10/2.
//

#ifndef MH_CVBOT_SRC_CORE_STATIC_REGION_STATIC_REGION_H_
#define MH_CVBOT_SRC_CORE_STATIC_REGION_STATIC_REGION_H_

#include <string>
#include <utility>
#include "mhtool/core/pos_color/pos_colors.h"

/**
 * Static region是通过某些特殊的像素点来识别是否匹配
 *
 * 优点是快速
 * 缺点是必须是静态，且位置和像素值不能有一点偏差
 */
class StaticRegion {
 public:
  StaticRegion(std::string name, PosColors posColors);
  StaticRegion(std::string name, PosColors posColors, std::string desc);

  bool check(const cv::Mat &mat);
 private:
  std::string name;
  std::string desc;
  PosColors posColors;
};

#endif //MH_CVBOT_SRC_CORE_STATIC_REGION_STATIC_REGION_H_
