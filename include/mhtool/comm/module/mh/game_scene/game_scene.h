//
// Created by huhua on 2022/2/9.
//

#ifndef MH_TOOL_INCLUDE_MHTOOL_COMM_GAM_SCENE_H_
#define MH_TOOL_INCLUDE_MHTOOL_COMM_GAM_SCENE_H_
#include <string>

namespace mh {
// I need a better name
class GameScene {
 private:
  std::string _name;

 public:
  GameScene(const std::string &name);
  inline std::string name() {return this->_name;}
};
}
#endif //MH_TOOL_INCLUDE_MHTOOL_COMM_GAM_SCENE_H_
