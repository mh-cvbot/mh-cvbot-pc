//
// Created by huhua on 2022/2/9.
//

#ifndef MH_TOOL_INCLUDE_MHTOOL_CITY_H_
#define MH_TOOL_INCLUDE_MHTOOL_CITY_H_
#include "mhtool/mh/game_scene/game_scene.h"
#include "mhtool/comm/Result.h"
#include <opencv2/core.hpp>

namespace mh {
/**
 * How can go here?
 */
class City: public GameScene {
 public:
  /**
   * 城市大小
   */
  cv::Size2i size;

  /**
   * 是否可用飞行符到这里
   */
  bool canFeixf;

  /**
   * 是否可用导标旗到这里
   */
  bool canDaobq;

 public:
  City(const std::string &name);
  virtual Result come();
  virtual Result come(cv::Point2i pos);

  /**
   * 走到传送点
   * @param sendPoint
   * @return
   */
  Result goSendPoint(cv::Point2i sendPoint);

  City* findPreviousCity();
};
}
#endif //MH_TOOL_INCLUDE_MHTOOL_CITY_H_