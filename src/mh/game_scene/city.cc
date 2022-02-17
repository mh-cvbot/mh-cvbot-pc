//
// Created by huhua on 2022/2/11.
//

#include "mhtool/mh/city/city.h"
#include <mhtool/mh.h>

mh::City::City(const std::string &name) : GameScene(name) {
}

Result mh::City::come() {
}

Result mh::City::come(cv::Point2i pos) {
  // this is complicated situation

  // 首先确定我们已经到附近了吧

  // first check can we use a daobq
  if (this->canDaobq) {
    // but how to check a daobq??
    // 遇事不觉，使用mh
  }

  if (!this->canDaobq && this->canFeixf) {
    // find the best previous city.
    // for now only find one, can be not the best for now.
  }

  auto pos = MH::inst()->pos();

  if (pos.name != this->name()) {
  }

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

