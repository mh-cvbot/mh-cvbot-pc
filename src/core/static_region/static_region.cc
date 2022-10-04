//
// Created by huhua on 2022/10/2.
//

#include "static_region.h"

#include <utility>

StaticRegion::StaticRegion(std::string name, PosColors posColors):
name(std::move(name)), posColors(posColors), desc(name)
{
}

bool StaticRegion::check(const cv::Mat &mat) {
  return this->posColors.check(mat);
}

StaticRegion::StaticRegion(std::string name, PosColors posColors, std::string desc):
name(std::move(name)), posColors(posColors), desc(std::move(desc)){ }
