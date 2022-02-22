//
// Created by th on 2022/1/31.
//

#include "mhtool/mh/pos_indicator.h"
#include <iostream>
#include <mhtool/config.h>

using namespace mh;

bool mh::PosIndicator::operator==(const PosIndicator &other) {
  return this->pos == other.pos
    && this->state == other.state;
}

bool mh::operator==(const mh::PosIndicator &thiz, const mh::PosIndicator &other) {
  return thiz.pos == other.pos
      && thiz.state == other.state;
}

std::ostream &mh::operator<<(std::ostream &os, const mh::PosIndicator &thiz) {
  os << thiz.state << " " << thiz.pos;
  return os;
}

bool PosIndicator::isNear(const eb::Pos &other) {
  return this->pos.isNear(other, Config::DISTANCE_NEAR);
}

bool PosIndicator::isNear(const PosIndicator &indicator) {
  return indicator.name == this->name && isNear(indicator.pos);
}
