//
// Created by huhua on 2022/2/11.
//

#include "mhtool/mh/city/city.h"

mh::City::City(const std::string &name) : GameScene(name) {
}

Result mh::City::come() {
  return {1, "Please impl"};
}

Result mh::City::come(cv::Point2i pos) {
  return come();
}

