//
// Created by huhua on 2022/2/11.
//

#include "mhtool/mh/city/city.h"
#include <mhtool/mh.h>
#include <mhtool/config.h>

using namespace mh;

City::City(const std::string &name) : GameScene(name) {
}

Result City::come() {
}

Result City::come(const eb::Pos &p) {
  // first check is near.

  auto pos = MH::inst()->pos();
  // check is already done
  if (pos.name == this->name() && pos.pos.isNear(p, Config::SAME)) {
    return {0, "done"};
  }

  // check near, use mouth click to go to
  if (pos.name == this->name() && pos.isNear(p)) {
    return MH::inst()->goByMouseClick(pos, p);
  }

  // check is in same city
  if (pos.name == this->name()) {
    // let the city do it self, is better?
    MH::inst()->goByLittleMap(p);
    // do the real go by little map logic
  } else {
    // fly to this city.
    throw std::runtime_error("Pleas impl fly to this city");
  }

  // first check can we use a daobq
  if (this->canDaobq) {
    // but how to check a daobq??
    // 遇事不觉，使用mh
  }

  if (!this->canDaobq && this->canFeixf) {
    // find the best previous city.
    // for now only find one, can be not the best for now.
  }

//  auto pos = MH::inst()->pos();

//  if (pos.name != this->name()) {
//  }

  // then check already has a feixf
  // then check can I buy this feixf easy?
  // then check If already have the feixf or daobq
  // then check I have the money to buy that.
  // then buy it if I have enough money
  // I don't want check buy failed, because the items is cheap.
  // use the feixf or daobq
  // go the pos
//  return City::come(pos);
  return {1, "Please impl"};
}

