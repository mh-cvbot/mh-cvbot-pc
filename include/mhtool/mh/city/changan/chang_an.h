//
// Created by huhua on 2022/2/11.
//

#ifndef MH_TOOL_INCLUDE_MHTOOL_MH_GAME_SCENE_CITY_CHANGAN_H_
#define MH_TOOL_INCLUDE_MHTOOL_MH_GAME_SCENE_CITY_CHANGAN_H_

#include "mhtool/mh/city/building.h"
#include "./jiudian.h"
#include "../city.h"

namespace mh {
/**
 * 长安
 */
class ChangAn: public City {
 public:
  ChangAn();
 public:
  mh::Jiudian *jiudian;
  Result come(cv::Point2i pos) override;
};

}

#endif //MH_TOOL_INCLUDE_MHTOOL_MH_GAME_SCENE_CITY_CHANGAN_H_
