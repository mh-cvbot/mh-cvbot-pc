//
// Created by huhua on 2022/2/15.
//

#ifndef MH_TOOL_INCLUDE_MHTOOL_MH_CITY_NPC_H_
#define MH_TOOL_INCLUDE_MHTOOL_MH_CITY_NPC_H_
#include <mhtool/comm/Result.h>
#include "mhtool/mh/BaotuTaskInfo.h"

namespace mh {
class Npc {
 public:
  Result come();
  Result clickMe();
  void chat(int choice);

  /**
   * For now, we use refer for result
   */
  Result takeBaotuTask(BaotuTaskInfo *info);
};
}
#endif //MH_TOOL_INCLUDE_MHTOOL_MH_CITY_NPC_H_
