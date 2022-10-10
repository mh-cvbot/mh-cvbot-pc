//
// Created by th on 2022/1/31.
//

#include "mhtool/model/game_pos.h"
#include <iostream>
#include <mhtool/config.h>

using namespace mh;

bool mh::GamePos::operator==(const GamePos &other) {
  return this->pos == other.pos
    && this->state == other.state;
}

bool mh::operator==(const mh::GamePos &thiz, const mh::GamePos &other) {
  return thiz.pos == other.pos
      && thiz.state == other.state;
}

std::ostream &mh::operator<<(std::ostream &os, const mh::GamePos &thiz) {
  os << thiz.state << " " << thiz.pos;
  return os;
}

bool GamePos::isNear(const eb::Pos &other) {
  return this->pos.isNear(other, Config::DISTANCE_NEAR);
}

bool GamePos::isNear(const GamePos &indicator) {
  return indicator.name == this->name && isNear(indicator.pos);
}
