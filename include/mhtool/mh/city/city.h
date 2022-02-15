//
// Created by huhua on 2022/2/9.
//

#ifndef MH_TOOL_INCLUDE_MHTOOL_CITY_H_
#define MH_TOOL_INCLUDE_MHTOOL_CITY_H_
#include "mhtool/mh/game_scene/game_scene.h"
namespace mh {
/**
 * How can go here?
 */
class City: public GameScene {
 public:
  /**
   * 是否可用飞行符到这里
   */
  bool canFxf;

  /**
   * 是否可用导标旗到这里
   */
  bool canDbq;

 public:
  City(const std::string &name);
};
}
#endif //MH_TOOL_INCLUDE_MHTOOL_CITY_H_
