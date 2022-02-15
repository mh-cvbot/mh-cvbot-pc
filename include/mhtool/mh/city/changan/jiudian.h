//
// Created by huhua on 2022/2/15.
//

#ifndef MH_TOOL_INCLUDE_MHTOOL_MH_CITY_CHANGAN_JIUDIAN_H_
#define MH_TOOL_INCLUDE_MHTOOL_MH_CITY_CHANGAN_JIUDIAN_H_
#include "../building.h"
#include "../npc.h"
namespace mh {
class Xiaoer: public Npc {

};

class Jiudian: public mh::Building {
 public:
  Xiaoer *xiaoer;
};
}
#endif //MH_TOOL_INCLUDE_MHTOOL_MH_CITY_CHANGAN_JIUDIAN_H_
