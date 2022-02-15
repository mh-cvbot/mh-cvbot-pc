//
// Created by huhua on 2022/2/15.
//

#ifndef MH_TOOL_INCLUDE_MHTOOL_MH_CITY_BUILDING_H_
#define MH_TOOL_INCLUDE_MHTOOL_MH_CITY_BUILDING_H_
#include <mhtool/comm/Result.h>

namespace mh {
  class City;
  class Building {
   public:
    City *city;
   public:
    /**
     * come here.
     */
    Result come();
  };
}

#endif //MH_TOOL_INCLUDE_MHTOOL_MH_CITY_BUILDING_H_
