//
// Created by th on 2022/1/31.
//

#include <mhtool/comm/pos_indicator/pos_indicator.h>
#include <iostream>

bool mh::PosIndicator::operator==(const PosIndicator &other) {
  return this->name.compare(other.name)
    && this->pos == other.pos
    && this->state == other.state;
}

bool mh::operator==(const mh::PosIndicator &thiz, const mh::PosIndicator &other) {
  return thiz.name.compare(other.name) == 0
      && thiz.pos == other.pos
      && thiz.state == other.state;
}

std::ostream &mh::operator<<(std::ostream &os, const mh::PosIndicator &thiz) {
  os << thiz.state << " " << thiz.name << "[" << thiz.pos.x << "," << thiz.pos.y << "]";
  return os;
}
