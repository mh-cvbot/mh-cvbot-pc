//
// Created by huhua on 2022/2/17.
//

#include <mhtool/mh/city/changan/chang_an.h>
#include "mhtool/mh/mh.h"

Result mh::ChangAn::come(cv::Point2i dst) {
  // this is complicated situation

  // first check should use feixf or a daobq
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
}
