//
// Created by huhua on 2022/10/3.
//

#ifndef MH_CVBOT_SRC_CORE_CV_GAME_STATE_CV_H_
#define MH_CVBOT_SRC_CORE_CV_GAME_STATE_CV_H_

#include "ich.h"
#include <string>
#include "mhtool/core/static_region/sr_12_plus.h"

class GameStateCV: public ICV<std::string> {
 private:
  SR12Plus sr12Plus;

 public:
  std::string cv(const cv::Mat &mat) override;
};

#endif //MH_CVBOT_SRC_CORE_CV_GAME_STATE_CV_H_
