//
// Created by huhua on 2022/2/16.
//

#include <mhtool/mh/city/npc.h>
#include <mhtool/mh/city/city.h>
#include <mhtool/mh/city/building.h>

mh::Npc::Npc(mh::City *city, mh::Building *building): city(city), building(building) {
}

Result mh::Npc::come() {
  // C++ the lambda is not good?
  auto rst = city->come();
  if (!rst.isOk()) {
    return rst;
  }
  rst = building->come();
  if (!rst.isOk()) {
    return rst;
  }
  return this->realCome();
}

Result mh::Npc::realCome() {
  return {1, "not impl"};
}


