//
// Created by huhua on 10/6/2022.
//

#ifndef MH_CVBOT_INCLUDE_MHTOOL_CORE_CV_GAME_POS_CV_H_
#define MH_CVBOT_INCLUDE_MHTOOL_CORE_CV_GAME_POS_CV_H_
#include "./icv"
#include <mhtool/model/game_pos.h>

class GamePosCV: public ICV<mh::GamePos> {
 public:
  GamePos cv(const cv::Mat &mat) override;
};
#endif //MH_CVBOT_INCLUDE_MHTOOL_CORE_CV_GAME_POS_CV_H_
