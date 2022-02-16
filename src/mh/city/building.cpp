//
// Created by huhua on 2022/2/16.
//

#include <mhtool/mh/city/building.h>
#include <mhtool/mh/city/city.h>

mh::Building::Building(mh::City *_city): city(_city) {

}

Result mh::Building::come() {
  auto rst = city->come();
  if (!rst.isOk()) {
    return rst;
  }
  return this->realCome();
}
