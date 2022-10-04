//
// Created by huhua on 2022/10/3.
//

#include "mhtool/core/cv/game_state_cv.h"

std::string GameStateCV::cv(const cv::Mat &mat) {
  auto isHome = this->sr12Plus.check(mat);
  if (isHome) {
    return "Home";
  }
  return "Unknown";
}
